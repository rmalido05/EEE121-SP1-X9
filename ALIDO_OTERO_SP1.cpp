#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

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

        Node* newDiffHelper(Node* currentNode, int difficulty) {    // Makes a new difficulty node
            if(currentNode == nullptr) {
                return new Node(difficulty, flashcards);
            } else if(difficulty < get<0>(currentNode -> data)) {
                currentNode -> left = newDiffHelper(currentNode -> left, difficulty);
            } else {
                currentNode -> right = newDiffHelper(currentNode -> right, difficulty);
            }
            return currentNode;
        }

        Node* findDiffHelper(Node* currentNode, int difficulty) {   // Finds the node correspoding to input difficulty
            if (currentNode == nullptr) {
                cout << 0 << endl;
                return nullptr;
            }
            if(difficulty == get<0>(currentNode -> data)) {
                cout << 7 << endl;          // For debugging purposes
                return currentNode;
            } else if(difficulty < get<0>(currentNode -> data)) {
                cout << 8 << endl;          // For debugging purposes
                return findDiffHelper(currentNode -> left, difficulty);
            } else {
                cout << 9 << endl;          // For debugging purposes
                return findDiffHelper(currentNode -> right, difficulty);
            }
        }
    public:
        FlashcardBST():root(nullptr) {}

        void newDiff(int difficulty) {
            root = newDiffHelper(root, difficulty);
        }

        Node* findDiff(int difficulty) {
            Node* node = findDiffHelper(root, difficulty);
            return node;
        }
};

class FlashcardSystem : public FlashcardBST {
    private:
        void addFlashcardHelper(int id, int difficulty, string question, char answer, vector<string> choices) {
            Flashcard flashcard = Flashcard(id, difficulty, question, answer, choices); // Instantiate flashcard
            Node* node = findDiff(difficulty);  // Instantiate difficulty node

            // If the node doesn't exist, create it
            if (node == nullptr) {
                newDiff(difficulty);
                node = findDiff(difficulty);    // Re-fetch the code after creating it
            }
            get<1>(node->data).push(flashcard); // Push flashcard object into queue under difficulty node
        }

        // void editFlashcardHelper() {}

        // void deleteFlashcardHelper() {}

        queue<Flashcard> studySystem(int difficulty) {
            Node* node = findDiff(difficulty);  // Instantiate difficulty node
            
            // If the node doesn't exist, create it
            if (node == nullptr) {
                cout << "====================================================\n";
                cout << "[!!] No flashcards for the selected difficulty!\n";
                return queue<Flashcard>(); // Return an empty queue
            }
            
            // Find flashcard queue based on difficulty
            return get<1>(node -> data);
        }

    public:
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
            cout << "====================================================\n";

            switch(input) {
                case 0:
                    addInterface();
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

    void addInterface() {
        bool run = true;
        int id, difficulty;
        string question, choice;
        char yn, answer, ltr;
        vector<string> choices;

        id = 0;
        while(run) {
            cout << "====================================================\n";
            cout << "----->[ADD FLASHCARD]<-----\n";
            cout << endl;
            cout << "Enter question: ";
            cin.ignore();
            getline(cin, question);
            cout << endl;

            for(int j = 0; j < 4; j++) {
                ltr = 65 + j;   // A, B, C, D
                cout << "Enter choice [" << ltr << "]: ";
                getline(cin, choice);
                choices.push_back(choice);
            }

            bool run1 = true;
            while(run1) {   // Loop for invalid inputs
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

            cout << "Difficulty: ";
            cin >> difficulty;
            cout << endl;

            addFlashcardHelper(id, difficulty, question, answer, choices);
            
            bool run2 = true;
            while(run2) {   // Loop for invalid inputs
                cout << "Do you want to add another flashcard [Y/N]? ";
                cin >> yn;
                cout << endl;

                switch(yn) {
                    case 'N': case 'n':
                        run2 = false;
                        run = false;
                        break;
                    case 'Y': case 'y':
                        run2 = false;
                        break;
                    default:
                        cout << "[!!] Invalid Input [!!]";
                        cout << endl;
                        break;
                }
            }

            cout << "====================================================\n";

            id++;
            difficulty = 0; // Reset difficulty for the next flashcard
            question.clear(); // Clear the question string for the next flashcard
            choices.clear(); // Clear the choices vector for the next flashcard
        }
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

    void studyInterface() {
        int difficulty;

        cout << "====================================================\n";
        cout << "----->[STUDY MODE]<-----\n";
        cout << endl;
        cout << "Select a difficulty: ";
        cin >> difficulty;

        queue<Flashcard> flashcards = studySystem(difficulty);
        if (flashcards.empty()) {
            return; // Exit if no flashcards are found
        }
        
        int correct = 0;
        int size = flashcards.size();
        
        for(int i = 0; i < size; i++) {
            string question = flashcards.front().question;
            char flash_answer = flashcards.front().answer;
            vector<string> choices = flashcards.front().choices;
            int ctr = i + 1;
            char user_answer;

            flashcardInterface(question, flash_answer, choices, ctr);                
            cout << "Enter your answer: ";
            cin >> user_answer;
            cin.ignore();
            cout << endl << endl;
            if (user_answer == flash_answer || user_answer == flash_answer + 32 || user_answer == flash_answer - 32) {
                correct++; 
                cout << "Your answer is correct!" << endl;
            } else {
                cout << "Incorrect! The correct answer is: " << flashcards.front().answer << endl;
            }
            choices.clear();
            flashcards.pop();
            cout << endl;
        }
        cout << endl << "==================================================== \n";
        cout << "You have answered " << correct << " out of " << size << " questions correctly. \n";
        cout << endl;
    }

    void flashcardInterface(string question, char answer, vector<string> choices, int ctr) {
        cout << "====================================================\n";
        cout << "Question #" << ctr << ": " << question << endl;
        cout << "Choices: " << endl;
        cout << "[A] " << choices[0] << endl;
        cout << "[B] " << choices[1] << endl;
        cout << "[C] " << choices[2] << endl;
        cout << "[D] " << choices[3] << endl;
    }
};

int main() {
    FlashcardSystem flash;
    FlashcardBST ez;
    ez.newDiff(1);
    ez.newDiff(2);
    ez.newDiff(3);
    flash.menuInterface();
    return 0;
}
