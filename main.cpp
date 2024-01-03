#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
class MyList {
public:
    struct Node {
        T data;
        Node *next{};
        Node *previous{};

        Node(T data) {
            this->data = data;

        }
    };

    MyList() : head(nullptr) {}

    MyList(T data) {
        head = new Node(data);
    }

    MyList(initializer_list<T> list) : head(nullptr) {
        for (T item: list) {
            pushBack(item);
        }
    }

    void pushBack(T data) {
        if (head == nullptr) {
            head = new Node(data);
            return;
        }
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        Node *newNode = new Node(data);
        newNode->previous = current;
        current->next = newNode;
    }

    friend ostream &operator<<(ostream &os, const MyList &list) {
        Node *current = list.head;
        while (current != nullptr) {
            os << "Value: " << current->data << " ";
            current = current->next;
        }
        return os;
    }

    T operator[](int index) {
        Node *current = head;
        int counter = 0;
        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->next;
            counter++;
        }
        return T();
    }

private:
    Node *head;
};

int main() {
    MyList<int> list2{1, 2, 3, 4, 5};
    cout << list2 << endl;

}