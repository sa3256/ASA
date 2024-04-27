
struct Node {
    int info;
    Node *next;
    Node *prev;
};

// In circulardoublylist.h
class CircularDoublyList {
public:
    CircularDoublyList();
    ~CircularDoublyList();

    void insertBegin(int value);
    void insertEnd(int value);
    void insertAtPosition(int value, int pos);
    void deleteAtPosition(int pos);
    void searchElement(int value);
    void displayList();
    void reverseList();

    // Getter methods for testing
    Node* getStart() const { return start; }
    Node* getLast() const { return last; }
    int getCount() const { return count; }

private:
    Node* createNode(int value);
    Node* start;
    Node* last;
    int count;
};

