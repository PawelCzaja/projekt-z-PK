#include <iostream>

using namespace std;


struct node{
    node *previous;
    int value;
    node *next;
};

class Stack{
    private:
        node* first = nullptr;
        node* LastNode(){
            node *currentNode = this->first;
            while(currentNode->next != nullptr){
                currentNode = currentNode->next;
            }
            return currentNode;
        }
    public:
        Stack(){
            this->first = new node;
            this->first->previous = nullptr;
            this->first->value = 0;
            this->first->next = nullptr;
        }
        Stack(int value){
            this->first = new node;
            this->first->previous = nullptr;
            this->first->value = 0;
            this->first->next = nullptr;

            this->PutOnStack(value);
        }
        ~Stack(){
            cout << "Stack destroyed" << endl;
        }
        bool PutOnStack(int value){
            node *lastNode = this->LastNode();
            lastNode->next = new node;

            node *newNode = lastNode->next;
            newNode->previous = lastNode;
            newNode->value = value;
            newNode->next = nullptr;
            return true;
        }
        int GetFromStack(){
            node *currentNode = this->LastNode();
            int value = currentNode->value;
            if(currentNode->previous != nullptr){
                currentNode->previous->next = nullptr;
                return value;
            }else{
                cout << "ERROR: stack underflow" << endl;
                return 0;
            }
        }
        int StackSize() {
            int size = 0;
            node *currentNode = this->first;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
                size++;
            }
            return size;
        }
        enum status {
                empty = 0,
                full = 1,
                contain
        };

    friend ostream& operator<<(ostream& os, const Stack& stack);
};

ostream& operator<<(ostream& os, const Stack& stack){
    node *currentNode = stack.first;
    os << "---------STACK---------" << endl;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    while(currentNode->previous != nullptr){
        os << "|          " <<currentNode->value <<"          |" << endl;
        currentNode = currentNode->previous;
    }
    os << "-----------------------" << endl;
    return os;
}


int main() {

    Stack stos(1);
    stos.PutOnStack(2);
    stos.PutOnStack(3);
    stos.PutOnStack(3);
    cout << stos.StackSize() << endl;
    cout << stos;
    cout << stos.GetFromStack() << endl;
    cout << stos.GetFromStack() << endl;
    cout << stos.GetFromStack() << endl;
    cout << stos.GetFromStack() << endl;
    cout << stos.GetFromStack() << endl;
    return 0;
}
