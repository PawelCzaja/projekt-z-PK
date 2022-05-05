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
    Stack(const Stack & s){
        top = s.top;
    };
    ~Stack(){
        // not needed
        //cout << "dropped stack" << endl;
    };
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
        }else{
            cout << "underflow.." << endl;
            return 0;
        }
    };
    status State() const {
        if(this->top == nullptr){
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
    // put
    void operator +(const int & i){
        this->Put(i);
    }
    // get
    int operator -(){
        return this->Get();
    }
    // join other Stack on top
    void operator +=(Stack s){
        Stack temp(s.Get());
        while(s.State()){
            temp.Put(s.Get());
        }
        while(temp.State()){
            this->Put(temp.Get());
        }
    }
    Stack& operator=(const Stack& s) {
        this->top = s.top;
    };
    friend ostream& operator<<(ostream& os, const Stack& s);
};

ostream& operator<<(ostream& os, const Stack& s){
    if(!s.State()){
        os << "\\/--Stack--" << endl;
        os << "|  " << "empty" << endl;
    }else{
        node* node = s.top;
        os << "\\/--Stack--" << endl;
        while (node->next != nullptr){
            os << "|  " << node->value << endl;
            node = node->next;
        }
        os << "|  " << node->value << endl;
    }
    os << "\\/--------" << endl;
    return os;
}


int main(){
    // tworzenie stosu z i bez parametru oraz wypełnianie go nastepnymi liczbami
    Stack stos1;
    stos1.Put(1);
    stos1.Put(2);
    stos1.Put(3);

    Stack stos2(4);
    stos2+5;
    stos2+6;
    stos2+7;

    // wyswitlanie stosu za pomoca przeciazonego operatora iostream
    cout << endl << endl << endl << "wyswitlanie stosu za pomoca przeciazonego operatora iostream" << endl;
    cout << "stos 1:"<< endl;
    cout << stos1;
    cout << "stos 2:"<< endl;
    cout << stos2;

    // zdejmowanie elementu ze stosu
    cout << endl << endl << endl << "zdejmowanie elementu ze stosu" << endl;
    cout << "zdjety element ze stosu1 za pomoca Get(): " << stos1.Get() << endl;
    cout << "stos 1:"<< endl;
    cout << stos1;
    cout << "zdjety element ze stosu2 za pomoca -: " << -stos2 << endl;
    cout << "stos 2:"<< endl;
    cout << stos2;

    // kopiowanie stosu za pomoca przypisania operatorem = oraz za pomoca konstruktora kopiujacego
    cout << endl << endl << endl << "kopiowanie stosu za pomoca przypisania operatorem = oraz za pomoca konstruktora kopiujacego" << endl;
    Stack kopiaStosu1(stos1);
    cout << "kopiaStosu1:"<< endl;
    cout << kopiaStosu1;

    Stack kopiaStosu2;
    kopiaStosu2 = stos2;
    cout << "kopiaStosu2:"<< endl;
    cout << kopiaStosu2;

    // łaczenie stosów za pomocą przeciążonego operatora +=
    cout << endl << endl << endl << "laczenie stosow za pomoca przeciazonego operatora +=" << endl;
    kopiaStosu1 += kopiaStosu2;
    cout << "kopiaStosu1 += kopiaStosu2:"<< endl;
    cout << kopiaStosu1;

    // wyświetlanie rozmiaru stosu oraz próba underflow
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu " << kopiaStosu1.Size() << endl;
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu " << kopiaStosu1.Size() << endl;
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu " << kopiaStosu1.Size() << endl;
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu " << kopiaStosu1.Size() << endl;
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu " << kopiaStosu1.Size() << endl;
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu" << kopiaStosu1.Size() << endl;
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu" << kopiaStosu1.Size() << endl;
    cout << "zdjeto " << -kopiaStosu1 << endl;
    cout << kopiaStosu1;
    cout << "rozmiar stosu" << kopiaStosu1.Size() << endl;



    return 0;
}