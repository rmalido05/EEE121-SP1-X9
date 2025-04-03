#include <iostream>

#include <string>

using namespace std;

template<typename S>
class BinaryNode {
    public:
        S diff;
        BinaryNode* right;
        BinaryNode* left;
    
        BinaryNode(S val);
    //template<typename> friend class FlashcardBST;
};

template<typename S>
BinaryNode<S>::BinaryNode(S diff):right(NULL),left(NULL),diff(diff) {}

template<typename Card>
class FlashcardBST {
    private: 
        BinaryNode<Card>* root;
        int size;
        void addHelper(BinaryNode<Card>* curr, Card diff, string ques, string ans, bool correctness);
        void deleteHelper(BinaryNode<Card>* curr);
        void postorderHelper(BinaryNode<Card>* curr);
        void preorderHelper(BinaryNode<Card>* curr);
        void inorderHelper(BinaryNode<Card>* curr);
    public:
        FlashcardBST();
        void addCard(Card diff, string ques, string ans, bool correctness);
        void deleteTree();
        void postorder();
        void preorder();
        void inorder();
};

template<typename Card>
FlashcardBST<Card>::FlashcardBST():root(NULL),size(0) {}

template<typename Card>
void FlashcardBST<Card>::addCard(Card diff, string ques, string ans, bool correctness) {
    if(this -> root) {
        this -> addHelper(this -> root, diff, ques, ans, correctness);
    } else {
        this -> root  = new BinaryNode<Card>(diff);
    }
    (this -> size)++;
}

template<typename Card>
void FlashcardBST<Card>::addHelper(BinaryNode<Card>* curr, Card diff, string ques, string ans, bool correctness) {
    if(curr -> diff >= diff) {
       if(curr -> left) {
           this -> addHelper(curr -> left,diff, ques, ans, correctness);
       } else {
           curr -> left = new BinaryNode<Card>(diff, ques, ans, correctness);
       }
    } else { 
        if(curr -> right) {
           this -> addHelper(curr -> right, diff, ques, ans, correctness);
       } else {
           curr -> right = new BinaryNode<Card>(diff, ques, ans, correctness);
       }
    }
}


template<typename Card>
void FlashcardBST<Card>::deleteTree() {
    if(this -> root == NULL) {
        return;
    } else {
        this -> deleteHelper(this -> root);
    }
    this -> size = 0;
}

template<typename Card>
void FlashcardBST<Card>::deleteHelper(BinaryNode<Card>* curr) {
    if(curr == NULL) {
        return;
    } else {
        this -> deleteHelper(curr -> left);
        this -> deleteHelper(curr -> right);
        delete curr;
    }
}

template<typename Card>
void FlashcardBST<Card>::postorder() {
    if(this -> root == NULL) {
        cout << "Nothing to print" << endl;
    } else {
        postorderHelper(this -> root);
        cout << endl;
    }
}

template<typename Card>
void FlashcardBST<Card>::postorderHelper(BinaryNode<Card>* curr) {
    if(curr == NULL) {
        return;
    } else {
        this -> postorderHelper(curr -> left);
        this -> postorderHelper(curr -> right);
        cout << "DIFFICULTY: " << curr -> diff << endl;     // Prints the diff value of the card
        cout << curr -> ques << " ";                        // Prints the question of the card
    }
}


template<typename Card>
void FlashcardBST<Card>::preorder() {
    if(this -> root == NULL) {
        cout << "Nothing to print" << endl;
    } else {
        preorderHelper(this -> root);
        cout << endl;
    }
}

template<typename Card>
void FlashcardBST<Card>::preorderHelper(BinaryNode<Card>* curr) {
    if(curr == NULL) {
        return;
    } else {
        cout << "DIFFICULTY: " << curr -> diff << endl;
        cout << curr -> ques << " ";
        this -> preorderHelper(curr -> left);
        this -> preorderHelper(curr -> right);
    }
}

template<typename Card>
void FlashcardBST<Card>::inorder() {
    if(this -> root == NULL) {
        cout << "Nothing to print" << endl;
    } else {
        inorderHelper(this -> root);
        cout << endl;
    }
}

template<typename Card>
void FlashcardBST<Card>::inorderHelper(BinaryNode<Card>* curr) {
    if(curr == NULL) {
        return;
    } else {
        this -> inorderHelper(curr -> left);
        cout << "DIFFICULTY: " << curr -> diff << endl;
        cout << curr -> ques << " ";
        this -> inorderHelper(curr -> right);
    }
}

main(){
    // Place main code here.
    return 0;
}
