#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <direct.h>
using namespace std;

const string main_path = "C:\\Users\\TATA\\Desktop\\Acads\\EEE 121\\"; // global variable

class Flashcard {
    public:
        int id, difficulty;
        string question;
        char answer;
        vector<string> choices;
        Flashcard(int id, int difficulty, string question, char answer, vector<string> choices) 
            : id(id),
              difficulty(difficulty),
              question(question),
              answer(answer),
              choices(choices) 
        {}
};

class FlashcardBST {
    protected:
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

        bool addFlashcard(int difficulty, string question, char answer, vector<string> choices) {
            Flashcard* flashcard = new Flashcard(nextID, difficulty, question, answer, choices);
            Node* node = findDifficulty(difficulty);

            if (node == nullptr) {
                return true;
            }
            get<1>(node -> data).push(*flashcard);
            flashcardIDs[nextID] = flashcard;

            // Creates a new flashcard file
            string new_file_path = main_path + to_string(difficulty) + "\\" + "flashcard_" + to_string(nextID) + ".txt";
            ofstream new_file(new_file_path);
            if (new_file.is_open()) {
                new_file << "ID: " << nextID << endl;
                new_file << "Difficulty: " << difficulty << endl;
                new_file << "Question: " << question << endl;
                new_file << "Choices: " << endl;
                for (int i = 0; i < 4; i++) {
                    char ltr = 'A' + i;
                    new_file << "[" << ltr << "] " << choices[i] << endl;
                }
                new_file << "Answer: " << answer << endl;
                new_file.close();
            } else {
                cerr << "[!!] Error creating file for card #" << nextID << " [!!]" << endl;
            }

            cout << "Successfully added flashcard #" << nextID << endl;
            nextID++;
            return false;
        }

        bool editFlashcard(int ID, int new_difficulty, string new_question, char new_answer, vector<string> new_choices) {
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
                file << "Question: " << new_question << endl;
                file << "Choices: " << endl;
                for (int i = 0; i < 4; i++) {
                    char ltr = 'A' + i;
                    file << "[" << ltr << "] " << new_choices[i] << endl;
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
            vector<string> choices(4);
            char answer;
            
            while (getline(file, line)) {
                if (line.find("Question: ") == 0) { // skips 10 chars
                    question = line.substr(10);
                } 
                else if (line.find("[A] ") == 0) choices[0] = line.substr(4); // skips 4 chars
                else if (line.find("[B] ") == 0) choices[1] = line.substr(4); // skips 4 chars
                else if (line.find("[C] ") == 0) choices[2] = line.substr(4); // skips 4 chars
                else if (line.find("[D] ") == 0) choices[3] = line.substr(4); // skips 4 chars
                else if (line.find("Answer: ") == 0) answer = line.substr(8)[0]; // skips 8 chars, [0] only takes the first char
            }
            
            return Flashcard(id, difficulty, question, answer, choices);
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
        }

        void menuInterface() {
            bool run = true;
        int input;

        while(run) {
            cout << "====================================================\n";
            cout << "----->[MAIN MENU]<-----\n";
            cout << endl;
            cout << "[0] Add Flashcard\n";
            cout << "[1] Edit Flashcard\n";
            cout << "[2] Delete Flashcard\n";
            cout << "[3] Study Mode\n";
            cout << "[4] Exit\n";
            cout << endl;
            cout << "Selection: ";
            cin >> input;

            switch(input) {
                case 0:
                    addInterface();
                    break;
                case 1:
                    editInterface();
                    break;
                case 2:
                    deleteInterface();
                    break;
                case 3:
                    studyInterface();
                    break;
                case 4:
                    cout << "Thank you!" << endl;
                    run = false;
                    break;
                }
            }
        }

        void addInterface() {
            bool run = true;
            int difficulty;
            string question, choice;
            char yn, answer, ltr;
            vector<string> choices;

            while(run) {
                cout << "====================================================\n";
                cout << "----->[ADD FLASHCARD]<-----\n";
                cout << endl;
                cout << "Enter question: ";
                cin.ignore();
                getline(cin, question);
                cout << endl;

                for (int j = 0; j < 4; j++) {
                    ltr = 65 + j;   // A, B, C, D
                    cout << "Enter choice [" << ltr << "]: ";
                    getline(cin, choice);
                    choices.push_back(choice);
                }

                bool run1 = true;
                while (run1) {   // Loop for invalid inputs
                    cout << "Enter correct choice: ";
                    cin >> answer;
                    cout << endl;

                    switch(answer) {
                        case 'a': case 'A': case 'B': case 'b': case 'C': case 'c': case 'D': case 'd':
                            run1 = false;
                            break;
                        default:
                            cout << "[!!] Invalid Input [!!]";
                            cout << endl;
                    }
                }
                
                bool run2 = true;
                while (run2) {
                    cout << "Difficulty: ";
                    cin >> difficulty;
                    cout << endl;

                    run2 = addFlashcard(difficulty, question, answer, choices);
                    if (run2) {
                        cout << "[!!] Difficulty does not exist [!!]\n";
                    }
                }

                bool run3 = true;
                while (run3) {   // Loop for invalid inputs
                    cout << "Do you want to add another flashcard [Y/N]? ";
                    cin >> yn;
                    cout << endl;

                    switch(yn) {
                        case 'N': case 'n':
                            run3 = false;
                            run = false;
                            break;
                        case 'Y': case 'y':
                            run3 = false;
                            break;
                        default:
                            cout << "[!!] Invalid Input [!!]";
                            cout << endl;
                            break;
                    }
                }

                cout << "====================================================\n";
                difficulty = 0; // Reset difficulty for the next flashcard
                question.clear(); // Clear the question string for the next flashcard
                choices.clear(); // Clear the choices vector for the next flashcard
            }
        }

        void editInterface() {
            bool run = true;
            int ID, input;
            string choice;
            char ltr;

            while(run) {
                cout << "====================================================\n";
                cout << "----->[EDIT FLASHCARD]<-----\n";
                cout << endl;
                cout << "Enter the ID of the flashcard you wish to edit: ";
                cin >> ID;
                
                auto iterator = flashcardIDs.find(ID);
                if (iterator == flashcardIDs.end()) {
                    cout << "[!!] Flashcard not found [!!]\n";
                    continue;
                }
                Flashcard* flashcard = iterator -> second;
                string new_question = flashcard -> question;        // Set up with original/default values
                vector<string> new_choices = flashcard -> choices;
                char new_answer = flashcard -> answer;
                int new_difficulty = flashcard -> difficulty;

                flashcardInterface(flashcard -> question, flashcard -> choices, 0);
                cout << "Answer: " << flashcard -> answer << endl;
                cout << "Difficulty: " << flashcard -> difficulty << endl;

                bool run1 = true;
                while (run1) {
                    cout << "====================================================\n";
                    cout << "[0] Edit Question\n";
                    cout << "[1] Edit Choices\n";
                    cout << "[2] Edit Answer\n";
                    cout << "[3] Edit Difficulty\n";
                    cout << "[4] Cancel\n";
                    cout << "Selection: ";
                    cin >> input;

                    switch(input) {
                        case 0:
                            cout << "Enter new question: ";
                            cin.ignore();
                            getline(cin, new_question);
                            run1 = false;
                            break;
                        case 1:
                            new_choices.clear();
                            cin.ignore();
                            for(int j = 0; j < 4; j++) {
                                ltr = 65 + j;   // A, B, C, D
                                cout << "Enter new choice [" << ltr << "]: ";
                                getline(cin, choice);
                                new_choices.push_back(choice);
                            }
                            run1 = false;
                            break;
                        case 2:
                            cout << "Enter new answer: ";
                            cin >> new_answer;
                            run1 = false;
                            break;
                        case 3:
                            cout << "Enter new difficulty: ";
                            cin >> new_difficulty;
                            if (findDifficulty(new_difficulty)) {
                                run1 = false;
                            } else {
                                cout << "[!!] Difficulty doesn't exist [!!]\n";
                            }
                            break;
                        case 4:
                            return;
                        default:
                            cout << "[!!] Invalid Input [!!]";
                            cout << endl;
                            break;
                    }
                }

                run = !editFlashcard(ID, new_difficulty, new_question, new_answer, new_choices);
            }
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

                    switch(yn) {
                        case 'N': case 'n':
                            run1 = false;
                            continue;
                            break;
                        case 'Y': case 'y':
                            run1 = false;
                            break;
                        default:
                            cout << "[!!] Invalid Input [!!]";
                            cout << endl;
                            break;
                    }
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
                    string question = flashcards.front().question;
                    char flash_answer = flashcards.front().answer;
                    vector<string> choices = flashcards.front().choices;
                    int question_number = i + 1;
                    char user_answer;
        
                    flashcardInterface(question, choices, question_number);                
                    cout << "Enter your answer: ";
                    cin >> user_answer;
                    cin.ignore();

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
                string question = flashcards.front().question;
                char flash_answer = flashcards.front().answer;
                vector<string> choices = flashcards.front().choices;
                char user_answer = user_answers.front();
                int question_number = i + 1;

                flashcardInterface(question, choices, question_number);
                cout << "Your answer was: " << user_answer << endl;
                if (user_answer == flash_answer || user_answer == flash_answer + 32 || user_answer == flash_answer - 32) {
                    cout << "Your answer is correct!\n";
                    correct_answers++;
                } else {
                    cout << "The correct answer is: " << flash_answer << endl;
                }
                
                choices.clear();
                flashcards.pop();
                user_answers.pop();
            }

            cout << "Your score is " << correct_answers << "/" << size << "!\n";
            cout << "Enter any character to exit: ";
            cin >> ch;
        }

        void flashcardInterface(string question, vector<string> choices, int question_number) {
            cout << "====================================================\n";
            cout << "Question #" << question_number << ": " << question << endl;
            cout << "Choices: " << endl;
            cout << "[A] " << choices[0] << endl;
            cout << "[B] " << choices[1] << endl;
            cout << "[C] " << choices[2] << endl;
            cout << "[D] " << choices[3] << endl;
        }
};
    
int main() {
    FlashcardInterface flashcard;
    flashcard.initializer();
    flashcard.menuInterface();
    return 0;
}