#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

class Flashcard {
    public:
        int id, difficulty;
        string question, answer;
        vector<string> choices;
        Flashcard(int id, int difficulty, string question, string answer, vector<string> choices) 
            : id(id),
              difficulty(difficulty),
              question(question),
              answer(answer),
              choices(choices) 
        {}
};

class FlashcardBST {
    private:
        queue<Flashcard> flashcards;
    protected:
        struct Node {
            tuple<int, queue<Flashcard>> data;
            Node* right;
            Node* left;

            Node(int difficulty, queue<Flashcard> flashcards)
                : data({difficulty, flashcards}), 
                  right(NULL), 
                  left(NULL) 
            {}
        };
        Node* root;

        Node* newDiffHelper(Node* currentNode, int difficulty) {
            if(currentNode == nullptr) {
                return new Node(difficulty, flashcards);
            } else if(difficulty < get<0>(currentNode -> data)) {
                currentNode -> left = newDiffHelper(currentNode -> left, difficulty);
            } else {
                currentNode -> right = newDiffHelper(currentNode -> right, difficulty);
            }
            return currentNode;
        }

        Node* findDiffHelper(Node* currentNode, int difficulty) {
            if (currentNode == nullptr) {
                return nullptr;
            }
            if(difficulty == get<0>(currentNode -> data)) {
                cout << 0 << endl;          // For debugging purposes
                return currentNode;
            } else if(difficulty < get<0>(currentNode -> data)) {
                cout << 1 << endl;          // For debugging purposes
                return findDiffHelper(currentNode -> left, difficulty);
            } else {
                cout << 2 << endl;          // For debugging purposes
                return findDiffHelper(currentNode -> right, difficulty);
            }
        }
    public:
        FlashcardBST():root(nullptr) {}

        void newDiff(int difficulty) {
            root = newDiffHelper(root, difficulty);
        }

        Node* findDiff(int difficulty) {
            cout << 0 << endl;                              // For debugging purposes
            Node* node = findDiffHelper(root, difficulty);
            return node;
        }
};

class FlashcardSystem : public FlashcardBST {
    private:
        void addFlashcardHelper(int id, int difficulty, string question, string answer, vector<string> choices) {
            cout << 0 << endl;
            Flashcard flashcard(id, difficulty, question, answer, choices);
            Node* node = findDiff(difficulty);

            if (node == nullptr) {
                newDiff(difficulty);
                node = findDiff(difficulty);
            }

            get<1>(node->data).push(flashcard);
            return;
        }
        queue<Flashcard> studySystem(int difficulty) {
            queue<Flashcard> flashcards = get<1>(findDiff(difficulty) -> data);
            return flashcards;
        }
    public:
        void menuInterface() {
            bool run = true;
            int input;
            while(run) {
                cout << "====================================================\n";
                cout << "[MAIN MENU]\n";
                cout << endl;
                cout << "[0] Add Flashcard\n";
                cout << "[1] Edit Flashcard\n";
                cout << "[2] Delete Flashcard\n";
                cout << "[3] Study Mode\n";
                cout << "[4] Exit\n";
                cout << endl;
                cout << "Selection: ";
                cin >> input;
                cout << "====================================================\n";

                switch(input) {
                    case 0:
                        run = addInterface();
                        break;
                    case 1:
                        // editInterface();
                        break;
                    case 2:
                        // deleteInterface();
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

        bool addInterface() {
            bool run = true;
            int id, difficulty;
            string question, answer, choice, yn;
            vector<string> choices;

            id = 0;
            while(run) {
                cout << "====================================================\n";
                cout << "[ADD FLASHCARD]\n";
                cout << "Enter question: ";
                getline(cin, question);
                cin.ignore(); // Clear the newline character from the input buffer
                for(int j = 0; j < 4; j++) {
                    cout << "Enter choice" << j + 1 << ": ";
                    getline(cin, choice);
                    choices.push_back(choice);
                    cin.ignore();   
                    cout << endl;
                }

                cout << "Enter correct answer: ";
                getline(cin, answer);
                cin.ignore();
                cout << endl;
                cout << "Difficulty: ";
                cin >> difficulty;
                cout << endl;

                addFlashcardHelper(id, difficulty, question, answer, choices);

                cout << "Do you want to add another flashcard [Y/N]? ";
                cin >> yn;
                cout << "====================================================\n";
                if(yn == "N" || yn == "n") {
                    run = false;
                }

                id++;
                difficulty = 0; // Reset difficulty for the next flashcard
                question.clear(); // Clear the question string for the next flashcard
                answer.clear(); // Clear the answer string for the next flashcard
                choices.clear(); // Clear the choices vector for the next flashcard
            }
            return true;
        }

        // bool deleteInterface() {
        //     // delete flashcard
        //     cout << "====================================================\n";
        //     cout << "[DELETE FLASHCARD]\n";
        //     cout << "Choose a flashcard to delete: ";
        //     int size = flashcards.size();
        //     for(int i = 1; i < size; i++) {
        //         cout << "[" << i << "]" << " " << flashcards.question << endl;
        //     }
        //     return true;
        // }

        bool studyInterface() {
            int difficulty;
            queue<Flashcard> flashcards;
            cout << "====================================================\n";
            cout << "[STUDY MODE]\n";
            cout << "Select a difficulty: ";
            cin >> difficulty;

            int correct = 0;
            flashcards = studySystem(difficulty);
            int size = flashcards.size();
            
            for(int i = 0; i <= size; i++) {
                string question = flashcards.front().question;
                string flash_answer = flashcards.front().answer;
                vector<string> choices = flashcards.front().choices;
                int ctr = i + 1;
                string user_answer;

                flashcardInterface(question, flash_answer, choices, ctr);                
                cout << "Enter your answer: ";  
                
                getline(cin, user_answer);
                cin.ignore();
                cout << endl << endl;
                if (user_answer == flash_answer) {
                    correct++; 
                    cout << "Your answer is correct!" << endl;
                } else {
                    cout << "Incorrect! The correct answer is: " << flashcards.front().answer << endl;
                }
                flashcards.pop();
                cout << endl;
            }
            cout << endl << "==================================================== \n";
            cout << "You have answered " << correct << " out of " << size << " questions correctly. \n";
            cout << endl;
            return true;
        }

        void flashcardInterface(string question, string answer, vector<string> choices, int ctr) {
            cout << "====================================================\n";
            cout << "Question #" << ctr << ": " << question << endl;
            cout << "Choices: " << endl;
            cout << "[A] " << choices[0] << endl;
            cout << "[B] " << choices[1] << endl;
            cout << "[C] " << choices[2] << endl;
            cout << "[D] " << choices[3] << endl;
            return;
        }
};

main(){
    FlashcardSystem flash;
    FlashcardBST ez;
    ez.newDiff(1);
    ez.newDiff(3);
    flash.menuInterface();
    return 0;
}
