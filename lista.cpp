#include <iostream>

using namespace std;

/**
 * Classe Nó
 * Representa um nó da lista
*/
class Node {
    public:
        // Dado inteiro
        int data;
        // Ponteiro para o próximo nó
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;            
        }
};

/**
 * Classe Lista Encadeada
*/
class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() {
            head = nullptr;
        }

        /**
         * Insere no início da Lista
        */
        void insereNoInicio(int value)
        {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        int buscarElementoLista(int value) 
        {
            Node* current = head;
            int resposta;
            bool achou = false;
            while (achou != true) {
                if (current->data == value) {
                    resposta = current->data;
                    achou = true;
                }
                current = current->next;

                if (current == nullptr) {
                    resposta = 0;
                    achou = true;
                }
            }

            return resposta;
        }

        void removerItemLista(int value)
        {
            Node* current = head;
            Node* prev = nullptr;

            while (current != nullptr && current->data != value) {                
                prev = current;
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Elemento não encontrado.";
            }

            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            delete current;
        }

        void imprimirLista()
        {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        ~LinkedList() 
        {
            while (head != nullptr) {
                Node* current = head;
                head = head->next;
                delete current;
            }
        }
};

int main()
{
    LinkedList list;
    list.insereNoInicio(2);
    list.insereNoInicio(3);
    list.insereNoInicio(1);

    cout << "Lista: ";
    list.imprimirLista();

    cout << "Busca: " << list.buscarElementoLista(1) << endl;

    list.removerItemLista(3);
    cout << "Lista: ";
    list.imprimirLista();

    return 0;
}

