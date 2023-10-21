#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value){
            data = value;
            next = nullptr;
        }
};

class Pilha {

    private:
        Node* top;

    public:
        Pilha() {
            top = nullptr;
        }

        void push(int value)
        {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        bool pilhaVazia()
        {
            return top == nullptr;
        }

        int pop()
        {
            if (pilhaVazia()) {
                throw::std::underflow_error("A pilha esta vazia");
            }

            Node* temp = top;
            int poppedValue = temp->data;
            top = top->next;
            delete temp;
            return poppedValue;
        }

        int size() 
        {
            int count = 0;
            Node* current = top;
            while (current != nullptr) {
                count++;
                current = current->next;
            }

            return count;
        }

};

int main() {
    Pilha pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    pilha.push(40);

    cout << "Tamanho da Pilha: " << pilha.size() << endl;

    while ( !pilha.pilhaVazia() ) {
        cout << "Elemento desempilhado: " << pilha.pop() << endl;
    }

    cout << "Tamanho da Pilha: " << pilha.size() << endl;
}