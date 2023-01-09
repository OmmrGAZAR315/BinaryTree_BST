#include "iostream"
struct Node {
    int num;
    Node *next;

    Node(int Num) {
        num = Num;
        next = nullptr;
    }
};

class stack {
    Node *top = nullptr;

public:

    void push(int);

    void display();

    int pop();

    int peek();

    stack() = default;

    stack(stack &s) {
        Node *t = s.top;
        stack ss;
        while (t != nullptr) {
            ss.push(t->num);
            t = t->next;
        }
        t = ss.top;
        while (t != nullptr) {
            push(t->num);
            t = t->next;
        }

    }

    inline bool isEmpty() {
        return top == nullptr;
    }

};

void stack::push(int num) {
    if (top == nullptr)
        top = new Node(num);
    else {
        Node *temp = top;
        top = new Node(num);
        top->next = temp;
    }
}

int stack::pop() {
    Node *temp = top;
    top = top->next;
    int value = temp->num;
    delete temp;
    return value;
}

void stack::display() {
    if (top == nullptr)
        return;
    Node *temp = top;
    while (temp != nullptr) {
        std::cout << temp->num << std::endl;
        temp = temp->next;
    }
}

int stack::peek() {
    if (top != nullptr)
        return top->num;
    return 0;
}