#include <iostream>

template<typename T>
class MyStack
{
private:

    int Size;
    class Node
    {
    public:
        T data;
        Node* pNext;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node* top;

public:

    MyStack()
    {
        this->Size = 0;
        this->top = nullptr;
    }

    void push(T value)
    {
        if (top == nullptr)
        {
            top = new Node(value);
            Size++;
        }
        else
        {
            Node* temp = top;
            top = new Node(value);
            top->pNext = temp;
            Size++;
        }
    }

    void pop()
    {
        if (top != nullptr)
        {
            Node* temp = top->pNext;
            delete top;
            top = temp;
            Size--;
        }
    }

    int GetSize() { return Size; }

    bool isEmpty()
    {
        if (top == nullptr)
            return true;
        return false;
    }

    int Search(T target) // відносно порядку добавляння
    {
        int count = 0;
        Node* current = top;
        for (int i = 0; i < this->Size; i++)
        {
            if (current->data == target)
                return Size-count-1;
            current = current->pNext;
            count++;
        }
        return -1;
    }

    ~MyStack()
    {
        while (Size)
        {
            this->pop();
        }
    }
};

int main()
{
    
}
