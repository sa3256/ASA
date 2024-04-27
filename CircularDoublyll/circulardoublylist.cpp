#include "circulardoublylist.h"
#include <iostream>

using namespace std;

CircularDoublyList::CircularDoublyList() : start(NULL), last(NULL), count(0) {}

CircularDoublyList::~CircularDoublyList() {
    Node* current = start;
    Node* next;
    if (start != NULL) {
        do {
            next = current->next;
            delete current;
            current = next;
        } while (current != start);
    }
    start = last = NULL;
    count = 0;
}

Node* CircularDoublyList::createNode(int value) {
    Node* temp = new Node;
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void CircularDoublyList::insertBegin(int value) {
    Node* temp = createNode(value);
    if (start == NULL) {
        start = last = temp;
        temp->next = temp->prev = temp;
    } else {
        temp->next = start;
        temp->prev = last;
        start->prev = last->next = temp;
        start = temp;
    }
    count++;
}

void CircularDoublyList::insertEnd(int value) {
    if (start == NULL) {
        insertBegin(value);
    } else {
        Node* temp = createNode(value);
        temp->next = start;
        temp->prev = last;
        last->next = start->prev = temp;
        last = temp;
        count++;
    }
}

void CircularDoublyList::insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertBegin(value);
        return;
    } else if (pos == count + 1) {
        insertEnd(value);
        return;
    } else if (pos > 1 && pos <= count) {
        Node* temp = createNode(value);
        Node* ptr = start;
        for (int i = 1; i < pos - 1; i++) {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next->prev = temp;
        ptr->next = temp;
        count++;
    } else {
        cout << "Position out of range" << endl;
    }
}

void CircularDoublyList::deleteAtPosition(int pos) {
    if (start == NULL) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }
    if (pos == 1) {
        Node* temp = start;
        if (start == last) {
            start = last = NULL;
        } else {
            start = start->next;
            start->prev = last;
            last->next = start;
        }
        delete temp;
        count--;
    } else if (pos == count) {
        Node* temp = last;
        last = last->prev;
        last->next = start;
        start->prev = last;
        delete temp;
        count--;
    } else {
        Node* ptr = start;
        for (int i = 1; i < pos; i++) {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        count--;
    }
}

void CircularDoublyList::searchElement(int value) {
    Node* temp = start;
    int pos = 1;
    bool found = false;
    if (temp == NULL) {
        cout << "The list is empty, nothing to search" << endl;
        return;
    }
    do {
        if (temp->info == value) {
            cout << "Element " << value << " found at position " << pos << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != start);
    if (!found) {
        cout << "Element not found in the list" << endl;
    }
}

void CircularDoublyList::displayList() {
    Node* temp = start;
    if (temp == NULL) {
        cout << "The list is empty, nothing to display" << endl;
        return;
    }
    do {
        cout << temp->info << " <-> ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

void CircularDoublyList::reverseList() {
    if (start == NULL || start == last) {
        cout << "No need to reverse, the list is empty or has only one element" << endl;
        return;
    }
    Node* current = start;
    Node* temp = NULL;
    last = start;  // last will now be where start was
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // as prev and next are swapped, we move to prev
    } while (current != start);
    start = temp->prev;  // reset start to the new start
}
