#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <direct.h>
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QDir>
#include <io.h>
#include "editflashcardsdialog.h"

using namespace std;

const string main_path = QDir::currentPath().toStdString() + "\\"; // global variable

class Flashcard {
public:
    int id, difficulty;
    QString question;
    QString answer;
    vector<QString> choices;
    Flashcard(int id, int difficulty, QString question, char answer, vector<QString> choices)
        : id(id),
        difficulty(difficulty),
        question(question),
        answer(answer),
        choices(choices)
    {}
};

class FlashcardBST {
public:
    struct Node {
        tuple<int, queue<Flashcard>> data;
        Node* right;
        Node* left;
    };

    Node* root;

    Node* addHelper(tuple<int, queue<Flashcard>> tup, Node* node) {
        if (node == nullptr) {
            node = new Node;
            node -> data = tup;
            node -> left = node -> right = nullptr;
            _mkdir((main_path + to_string(get<0>(tup))).c_str()); // makes a directory/folder named as the difficulty number
        } else if (get<0>(tup) < get<0>(node -> data)) {
            node -> left = addHelper(tup, node -> left);
        } else if (get<0>(tup) > get<0>(node -> data)) {
            node -> right = addHelper(tup, node -> right);
        }
        return node;
    }

    Node* findMin(Node* node) {
        if (node == nullptr) {
            return nullptr;
        } else if (node -> left == nullptr) {
            return node;
        } else {
            return findMin(node -> left);
        }
    }

    Node* removeHelper(tuple<int, queue<Flashcard>> tup, Node* node) {
        Node* temp;
        if (node == nullptr) {
            return nullptr;
        } else if(get<0>(tup) < get<0>(node -> data)) {
            node -> left = removeHelper(tup, node -> left);
        } else if(get<0>(tup) > get<0>(node -> data)) {
            node -> right = removeHelper(tup, node -> right);
        } else if(node -> left && node -> right) {
            temp = findMin(node -> right);
            node -> data = temp -> data;
            node -> right = removeHelper(node -> data, node ->right);
        } else {
            temp = node;
            if(node -> left == nullptr)
                node = node -> right;
            else if(node -> right == nullptr)
                node = node -> left;
            delete temp;
        }
        return node;
    }

    Node* findHelper(tuple<int, queue<Flashcard>> tup, Node* node) {
        if (node == nullptr) {
            return nullptr;
        } else if (get<0>(tup) < get<0>(node -> data)) {
            return findHelper(tup, node -> left);
        } else if (get<0>(tup) > get<0>(node -> data)) {
            return findHelper(tup, node -> right);
        } else {
            return node;
        }
    }

public:
    FlashcardBST() {
        root = nullptr;
    }

    void addDifficulty(int difficulty) {
        string diff_path = main_path + to_string(difficulty);
        mkdir(diff_path.c_str());

        queue<Flashcard> flashcard;
        tuple<int, queue<Flashcard>> tup = {difficulty, flashcard};
        root = addHelper(tup, root);
    }

    Node* findDifficulty(int difficulty) {
        queue<Flashcard> flashcard;
        tuple<int, queue<Flashcard>> tup = {difficulty, flashcard};
        return findHelper(tup, root);
    }
};

class FlashcardInterface : public FlashcardBST{
private:
    unordered_map<int, Flashcard*> flashcardIDs;
    int nextID = 0;

    int getID(){
        return nextID;
    }

    void incrementID(){
        nextID++;
    }

    bool addFlashcard(int difficulty, QString question, char answer, vector<QString> choices) {
        Flashcard* flashcard = new Flashcard(nextID, difficulty, question, answer, choices);
        Node* node = findDifficulty(difficulty);

        if (node == nullptr) {
            return true;
        }
        else {
            get<1>(node -> data).push(*flashcard);
            flashcardIDs[nextID] = flashcard;
            // Creates a new flashcard file
            string new_file_path = main_path + to_string(difficulty) + "\\" + "flashcard_" + to_string(nextID) + ".txt/";
            ofstream new_file(new_file_path);
            cout << "created flashcard #" << nextID << " at" << new_file_path << "." <<endl;
            if (new_file.is_open()) {
                new_file << "ID: " << nextID << endl;
                new_file << "Difficulty: " << difficulty << endl;
                new_file << "Question: " << question.toStdString() << endl;
                new_file << "Choices: " << endl;
                for (int i = 0; i < 4; i++) {
                    char ltr = 'A' + i;
                    new_file << "[" << ltr << "] " << choices[i].toStdString() << endl;
                }
                new_file << "Answer: " << answer << endl;
                new_file.close();
            }
        }
    }

    bool editFlashcard(int ID, int new_difficulty, QString new_question, char new_answer, vector<QString> new_choices) {
        auto iterator = flashcardIDs.find(ID);
        if (iterator == flashcardIDs.end()) {
            return false;
        }

        Flashcard* flashcard = iterator -> second;
        flashcard -> question = new_question;
        flashcard -> answer = new_answer;
        flashcard -> choices = new_choices;

        Node* node = findDifficulty(flashcard->difficulty);
        if (node) {
            queue<Flashcard> temp;
            while (!get<1>(node->data).empty()) {
                Flashcard current = get<1>(node->data).front();
                get<1>(node->data).pop();
                if (current.id == ID) {
                    current.question = new_question;
                    current.answer = new_answer;
                    current.choices = new_choices;
                }
                temp.push(current);
            }
            get<1>(node->data) = temp;
        }

        if (new_difficulty != flashcard -> difficulty) {
            string file_path = main_path + to_string(flashcard -> difficulty) + "\\" + "flashcard_" + to_string(ID) + ".txt";
            remove(file_path.c_str());
            changeDifficulty(ID, new_difficulty);
        }

        // Overwrite flashcard file
        string file_path = main_path + to_string(new_difficulty) + "\\" + "flashcard_" + to_string(ID) + ".txt";
        ofstream file(file_path, ios::trunc);
        if (file.is_open()) {
            file << "ID: " << ID << endl;
            file << "Difficulty: " << new_difficulty << endl;
            file << "Question: " << new_question.toStdString() << endl;
            file << "Choices: " << endl;
            for (int i = 0; i < 4; i++) {
                char ltr = 'A' + i;
                file << "[" << ltr << "] " << new_choices[i].toStdString() << endl;
            }
            file << "Answer: " << new_answer << endl;
            file.close();
        } else {
            cerr << "[!!] Error editing file for flashcard #" << ID << " [!!]" << endl;
        }

        cout << "Sucessfully edited flashcard #" << ID << endl;
        return true;
    }

    bool deleteFlashcard(int ID) {
        auto iterator = flashcardIDs.find(ID);
        if (iterator == flashcardIDs.end()) {
            return false;
        }
        Flashcard* flashcard = iterator -> second;

        Node* node = findDifficulty(flashcard -> difficulty);
        if (node) {
            queue<Flashcard> temp;
            while (!get<1>(node -> data).empty()) { // Loop through all flashcards in the queue
                Flashcard current = get<1>(node -> data).front(); // Get front of the flashcard queue
                get<1>(node -> data).pop(); // Pop first element to get to base case
                if (current.id != ID) {
                    temp.push(current); // Push current flashcard if it's id doesn't match the one we'll delete
                }
            }
            get<1>(node -> data) = temp;
        }

        string file_path = main_path + to_string(flashcard -> difficulty) + "\\" + "flashcard_" + to_string(ID) + ".txt";
        if (remove(file_path.c_str()) != 0) {
            cerr << "[!!] Could not delete flashcard file #" << ID << "[!!]" << endl;
        }

        cout << "Successfully deleted flashcard #" << ID << endl;
        // Remove from hash table
        delete flashcard;            // Free memory
        flashcardIDs.erase(iterator);
        return true;
    }

    bool changeDifficulty(int ID, int new_difficulty) {
        auto iterator = flashcardIDs.find(ID);
        if (iterator == flashcardIDs.end()) {
            return false;
        }
        Flashcard* flashcard = iterator -> second;
        int old_difficulty = flashcard -> difficulty;

        Node* new_node = findDifficulty(new_difficulty);
        if (new_node == nullptr) {
            return false; // New difficulty doesn't exist
        }

        Node* old_node = findDifficulty(old_difficulty);
        if (old_node) {
            queue<Flashcard> temp;
            while (!get<1>(old_node -> data).empty()) {
                Flashcard current = get<1>(old_node -> data).front();
                get<1>(old_node -> data).pop();
                if (current.id != ID) {
                    temp.push(current);
                }
            }
            get<1>(old_node -> data) = temp;
        }

        // Update difficulty and add to new queue
        flashcard -> difficulty = new_difficulty;
        get<1>(new_node -> data).push(*flashcard);

        return true;
    }

    queue<Flashcard> flashcardFinder(int difficulty) {
        Node* node = findDifficulty(difficulty);

        if (node == nullptr) {
            return queue<Flashcard>(); // Return an empty queue
        }
        return get<1>(node -> data);
    }

    Flashcard readFlashcardFile(ifstream& file, int id, int difficulty) {
        string line, question;
        vector<QString> choices(4);
        char answer;

        while (getline(file, line)) {
            if (line.find("Question: ") == 0) { // skips 10 chars
                question = line.substr(10);
            }
            else if (line.find("[A] ") == 0) choices[0] = QString::fromStdString(line.substr(4)); // skips 4 chars
            else if (line.find("[B] ") == 0) choices[1] = QString::fromStdString(line.substr(4)); // skips 4 chars
            else if (line.find("[C] ") == 0) choices[2] = QString::fromStdString(line.substr(4)); // skips 4 chars
            else if (line.find("[D] ") == 0) choices[3] = QString::fromStdString(line.substr(4)); // skips 4 chars
            else if (line.find("Answer: ") == 0) answer = QString::fromStdString(line.substr(8))[0].toLatin1(); // skips 8 chars, [0] only takes the first char
        }

        return Flashcard(id, difficulty, QString::fromStdString(question), answer, choices);
    }

public:
    void initializer() {
        // Check all directories for difficulties (nodes)
        for (int difficulty = 1; difficulty <= 3; difficulty++) {
            string diff_path = main_path + to_string(difficulty);
            mkdir(diff_path.c_str());
            addDifficulty(difficulty);

        // Check directory contents and push onto flashcard queue
        string flash_path = diff_path + "\\flashcard_*.txt"; // '*' is a wildcard character that can represent any character possible
        _finddata_t file_info; // _finddata_t structure used for file & directory searching / file_info stores the file
        intptr_t handle = _findfirst(flash_path.c_str(), &file_info); // handle - reference used in programming to access system-managed resources

        if (handle != -1) { // handle = -1 means no files match the description (flashcard_*.txt)
            do {
                // Extract ID from filename (flashcard_123.txt -> 123)
                string filename = file_info.name; // stores the specific filename
                size_t underscore = filename.find('_'); // stores index of first occurrence of '_' in the filename
                size_t dot = filename.find('.'); // stores index of first occurrence of '.' in the filename
                int id = stoi(filename.substr(underscore + 1, dot - underscore - 1)); // stores the ID from the filename
                // stoi - string to int | substr(<startpoint>, <size of str expected>) - gets a substr from a string

                // Read flashcard file
                string filepath = diff_path + "\\" + filename;
                ifstream file(filepath);
                if (file.is_open()) {
                    Flashcard flashcard = readFlashcardFile(file, id, difficulty);

                    Node* node = findDifficulty(flashcard.difficulty);
                    if (node) {
                        get<1>(node->data).push(flashcard); // Add flashcard to BST
                    }

                    flashcardIDs[flashcard.id] = new Flashcard(flashcard); // Add flashcard to hash table
                    if (flashcard.id >= nextID) {
                        nextID = flashcard.id + 1; // Update next available ID
                    }
                }
            } while (_findnext(handle, &file_info) == 0);

            _findclose(handle);
        }
        }
        cout << "Initialized progress successfully!" << endl;
        cout << main_path << endl;
    }

    void addInterface(QWidget* parent, int difficulty, QString question, QString answer, vector<QString> choices) {
        bool run2;
        run2 = addFlashcard(difficulty, question, answer[0].toLatin1(), choices);
        if (!run2) {
            QMessageBox::information(parent, "Error!", "Difficulty does not exist!");
        }
        else{
            addFlashcard(difficulty, question, answer[0].toLatin1(), choices);
            QString nextID = QString::number(getID());
            QMessageBox::information(parent, "Flashcard Added.", "Flashcard Details:\n\nDifficulty: " + QString::number(difficulty) + "\nFlashcard No." + nextID + "\nQuestion: " + question + "\nChoice A: " + choices[0] + "\nChoice B: " + choices[1] + "\nChoice C: " + choices[2] + "\nChoice D: " + choices[3] + "\nCorrect Answer: " + QString(answer));
            incrementID();
        }
    }

    void editInterface(QWidget* parent, int ID) {
        auto iterator = flashcardIDs.find(ID);
        if (iterator == flashcardIDs.end()) {
            QMessageBox::information(parent, "Error!", "Flashcard not found.");
            return;
        }
        Flashcard* flashcard = iterator -> second;
        QString new_question = flashcard -> question;        // Set up with original/default values
        vector<QString> new_choices = flashcard -> choices;
        char new_answer = flashcard -> answer[0].toLatin1();
        int new_difficulty = flashcard -> difficulty;

        editFlashcardsDialog* editInputs = qobject_cast<editFlashcardsDialog*>(parent);
        if(parent){
            editInputs -> setFlashcardFields(new_question, new_choices, new_answer, new_difficulty);
        }
        // !editFlashcard(ID, new_difficulty, new_question, new_answer, new_choices);
    }

    void deleteInterface() {
        bool run = true;
        int ID;
        char yn;

        while (run) {
            cout << "====================================================\n";
            cout << "----->[DELETE FLASHCARD]<-----\n";
            cout << endl;
            cout << "Enter the ID of the flashcard you wish to delete: ";
            cin >> ID;

            bool run1 = true;
            while (run1) {
                cout << "Are you sure you want to delete Flashcard #" << ID << "? [Y/N] ";
                cin >> yn;
                cout << endl;
            }
            if (deleteFlashcard(ID)) {
                run = false;
            }
        }
    }

    void studyInterface() {
        int difficulty;
        queue<Flashcard> flashcards;
        queue<Flashcard> flashcards_copy;
        queue<char> user_answers;
        bool run = true;

        while (run) {
            user_answers = queue<char>();

            cout << "====================================================\n";
            cout << "----->[STUDY MODE]<-----\n";
            cout << endl;

            bool run1 = true;
            while (run1) {
                cout << "Select a difficulty: ";
                cin >> difficulty;

                flashcards = flashcardFinder(difficulty);
                if (flashcards.empty() == false) {
                    break;
                }
                cout << "[!!] Difficulty does not exist OR No flashcards in selected difficulty [!!]\n";

            }

            int size = flashcards.size();
            flashcards_copy = flashcards;

            for(int i = 0; i < size; i++) {
                QString question = flashcards.front().question;
                char flash_answer = flashcards.front().answer.at(0).toLatin1();
                vector<QString> choices = flashcards.front().choices;
                int question_number = i + 1;
                char user_answer;

                // flashcardInterface(question, choices, question_number);
                // cout << "Enter your answer: ";
                // cin >> user_answer;
                // cin.ignore();

                user_answers.push(user_answer);
                choices.clear();
                flashcards.pop();
                cout << endl;
            }

            int fin;
            cout << "You've finished all the flashcards for this difficulty.\n\n";

            bool run2 = true;
            while (run2) {
                cout << "[0] Review Answers\n";
                cout << "[1] Exit\n";
                cout << "Selection: ";
                cin >> fin;

                switch (fin) {
                case 0:
                    reviewInterface(flashcards_copy, user_answers);
                    run = false;
                    run2 = false;
                    break;
                case 1:
                    run = false;
                    run2 = false;
                    break;
                default:
                    cout << "[!!] Invalid Input [!!]\n";
                    break;
                }
            }
        }
    }

    void reviewInterface(queue<Flashcard> flashcards, queue<char> user_answers) {
        cout << "====================================================\n";
        cout << "----->[REVIEW MODE]<-----\n";
        cout << endl;

        int correct_answers = 0;
        int size = flashcards.size();
        char ch;
        for (int i = 0; i < size; i++) {
            QString question = flashcards.front().question;
            char flash_answer = flashcards.front().answer.at(0).toLatin1();
            vector<QString> choices = flashcards.front().choices;
            char user_answer = user_answers.front();
            int question_number = i + 1;

            // flashcardInterface(question, choices, question_number);
            // cout << "Your answer was: " << user_answer << endl;
            // if (user_answer == flash_answer || user_answer == flash_answer + 32 || user_answer == flash_answer - 32) {
            //     cout << "Your answer is correct!\n";
            //     correct_answers++;
            // } else {
            //     cout << "The correct answer is: " << flash_answer << endl;
            // }

            choices.clear();
            flashcards.pop();
            user_answers.pop();
        }

        cout << "Your score is " << correct_answers << "\\" << size << "!\n";
        cout << "Enter any character to exit: ";
        cin >> ch;
    }
};
#endif // DATASTRUCTURES_H
