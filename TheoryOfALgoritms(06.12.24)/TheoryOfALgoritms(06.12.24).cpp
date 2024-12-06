#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    
    void addToEnd(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

public:
    List() : head(nullptr), tail(nullptr) {}
    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T& value) {
        addToEnd(value);
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    List operator+(const List& other) const {
        List result;
        Node* current = head;

        while (current) {
            result.push_back(current->data);
            current = current->next;
        }

        current = other.head;
        while (current) {
            result.push_back(current->data);
            current = current->next;
        }
        return result;
    }


    List operator*(const List& other) const {
        List result;
        Node* current1 = head;
        while (current1) {
            Node* current2 = other.head;
            while (current2) {
                if (current1->data == current2->data) {
                    result.push_back(current1->data);
                    break;
                }
                current2 = current2->next;
            }
            current1 = current1->next;
        }
        return result;
    }
};

int main() {
    List<int> list1;
    List<int> list2;

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    List<int> sum = list1 + list2;
    cout << "Sum (List1 + List2): ";
    sum.print();

    List<int> intersection = list1 * list2;
    cout << "Intersection (List1 * List2): ";
    intersection.print();
    return 0;
}
