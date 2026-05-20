#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Node {
public:
    T info;
    Node* next;

    Node (T value) {info = value; next = nullptr;}
    void show () const {
        cout << "INFO: " << info << endl;
        cout << "\tNEXT: " << next << endl;
    }
};

template <typename T>
class DNode {
public:
    T info;
    DNode* prev;
    DNode* next;

    DNode (T value) {info = value; next = prev = nullptr;}
    void show () const {
        cout << "INFO: " << info << endl;
        cout << "\tPREV: " << prev << endl;
        cout << "\tNEXT: " << next << endl;
    }
};

template <typename U>
class List {
    Node<U>* head;
    Node<U>* tail;
public:
    List () {
        head = tail = nullptr;
    }

    void push_back (U value) {

        // 1. Створюємо вузол
        Node<U>* item = new Node<U>(value);

        // 2. Чи це перший вузол списку
        if (head == nullptr || tail == nullptr) {
            head = tail = item;
        }
        else {
            // 3. Як що не первий вузол в списку
            tail->next = item;
            tail = item;
        }
    }

    void showList() {
        Node<U>* p = head;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->next;
        }
    }
};
//

// =================== Робота з двозв'язним списком. ===================
template <typename U>
class DList {
    DNode<U>* head;
    DNode<U>* current;
public:
    DList() { head = nullptr; current = nullptr; }
    ~DList() {
        DNode<U>* p = head;
        if (p == nullptr) {
            return;
        }
        if (p->next == nullptr) {
            delete p;
            head = nullptr;
            current = nullptr;
        }
        else {
            while (p->next != nullptr) {
                p = p->next;
                cout << "DELETE: " << p->prev->info << endl;
                delete p->prev;
            }
            cout << "DELETE: " << p->info << endl;
            delete p;
        }
    }

    void push_back(U value) { //Добавлення нового вузла в кінець списку

        //1. Створення нового вузла
        DNode<U>* item = new DNode<U>(value);

        // 2. Чи перший вузол в списку
        if (head == nullptr || current == nullptr) {
            head = current = item;
        }
        else {
            // 3. Не перший вузол
            current->next = item;
            item->prev = current;

            current = item;
        }
    }
    void show() {//Виведення списку на екран
        DNode<U>* p = head;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->next;
        }
    }
    void show_reverse() {
        DNode<U>* p = current;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->prev;
        }
        cout << endl;
    }

    DNode<U>* search(U value) {  //Пошук вузла із заданим значенням
        DNode<U>* p = head;
        while (p != nullptr) {
            if (p->info == value) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    //======================= Додавання вузла на початок списку ======================

    void push_front(U value) {
        DNode<U>* item = new DNode<U>(value);
        if (head == nullptr || current == nullptr) {
            head = current = item;
        }
        else {
            item->next = head;
            head->prev = item;
            head = item;
        }
    }
    // ================= Додавання вузла перед заданим значенням =======================

    void insertBefore(U before, U value) {
        DNode<U>* p = head;

        while (p != nullptr) {
            if (p->info == before) {

                DNode<U>* item = new DNode<U>(value);

                if (p == head) {
                    item->next = head;
                    head->prev = item;
                    head = item;
                }
                else {
                    item->next = p;
                    item->prev = p->prev;

                    p->prev->next = item;
                    p->prev = item;
                }

                return;
            }

            p = p->next;
        }
    }

    // ================= Додавання вузла після заданого значення =======================

    void insertAfter(U after, U value) {

        DNode<U>* p = head;

        while (p != nullptr) {

            if (p->info == after) {

                DNode<U>* item = new DNode<U>(value);

                item->next = p->next;

                item->prev = p;

                if (p->next != nullptr) {
                    p->next->prev = item;
                }

                p->next = item;

                if (p == current) {
                    current = item;
                }

                return;
            }

            p = p->next;
        }
    }

    // ================= Видалення вузла із заданим значенням =======================
    void erase(U value) {
        DNode<U>* p = head;

        while (p != nullptr) {

            if (p->info == value) {

                if (p->prev != nullptr) {
                    p->prev->next = p->next;
                }
                else {
                    head = p->next;
                }

                if (p->next != nullptr) {
                    p->next->prev = p->prev;
                }
                else {
                    current = p->prev;
                }

                delete p;
                return;
            }

            p = p->next;
        }
    }
};



