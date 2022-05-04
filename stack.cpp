#include <iostream>

using namespace std;

struct node{
    int value;
    node* next = nullptr;
};
enum status { empty = false, contain = true};

class Stack {
    private:
        node* top = nullptr;
    public:
        Stack(){
            this->top = new node;
            this->top->value = 0;
        };
        Stack(int value){
            this->top = new node;
            this->top->value = value;
        };
        ~Stack(){
            cout << "dropped Stack" << endl;
        }
        void Put(int value){
            node* prevousTop = this->top;
            this->top = new node;
            this->top->value = value;
            this->top->next = prevousTop;
        };
        int Get(){
            if(this->State()){
                int value = this->top->value;
                this->top = this->top->next;
                return value;
            }
        };
        void Display(){
            if(!this->State()){
                cout << "\\/--Stack--" << endl;
                cout << "|  " << "empty" << endl;
            }else{
                node* node = this->top;
                cout << "\\/ Stack" << endl;
                while (node->next != nullptr){
                    cout << "|  " << node->value << endl;
                    node = node->next;
                }
                cout << "|  " << node->value << endl;
            }
            cout << "\\/--------" << endl;
        };
        status State() const {
            if(this->top == nullptr){
                cout << "underflow.." << endl;
                return status::empty;
            }else{
                return status::contain;
            }
        };
        int Size() const {
            if(!this->State()){return 0;};
            int size = 1;
            node* node = this->top;
            while (node->next != nullptr){
                node = node->next;
                size++;
            }
            return size;
        }

};


int main(){
    Stack stos(1);
    stos.Get();
    stos.Display();
    return 0;
}