#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node* next;
    Node* prev;

    Node()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(T value) :Node()
    {
        this->value = value;
    }

    T GetValue()
    {
        return this->value;
    }
};

template <typename T>
class Stack
{
private:
    Node<T>* head;
    Node<T>* tail;
    uint32_t length;
 

public:
    Stack()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;  
    }

    bool Push(T elem)
    {
        Node<T>* node_elem = new Node<T>(elem);
        if (length == 0)
        {
            head = tail = node_elem;
        }
        else
        {
            tail->next = node_elem;
            node_elem->prev = tail;
            tail = node_elem;
        }
        length++;
        return true;
    }

   
    bool Pop()
    {
        Node<T>* node_elem = new Node<T>();
        node_elem = tail;
        if (node_elem->prev == nullptr)
        {
            tail = head = nullptr;
        }
        else
        {
            tail = node_elem->prev;
            tail->next = nullptr;
        }

        delete node_elem;
        --length;
        return true;
    }
    bool printAll()
    {
        Node<T>* node_elem = tail;
        do
        {
            cout << node_elem->value << "\t";
            node_elem = node_elem->prev;
        } while (node_elem != nullptr);
        cout << endl;
        return true;
    }
    bool Clear()
    {
        do
        {
            Pop();
        } while (tail != nullptr);

        return true;
    }

    uint32_t size()
    {
        return length;
    }

    bool empty()
    {
        return (length == 0) ? true : false;
    }

    bool isNotEmpty()
    {
        return (length != 0) ? true : false;
    }

    int count()
    {
        return length;
    }

    T Top()
    {
        if (length == 0)
        {
            return (T)NULL;
        }
        else
        {
            return tail->GetValue();
        }
    }
};

int main()
{
    Stack <char> stack;



    for (size_t i = 147; i < 160; i++)
    {
        stack.Push(i);
        cout << "Top [" << i << "] : " << stack.Top() << endl;
    }
   
    stack.printAll();

    cout << "Size = " << stack.size() << endl;
    if (stack.empty())
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "Stack is not empty!" << endl;
    }
    
    if (stack.isNotEmpty())
    { 
        cout << "Stack is not empty!" << endl;
    }
    else
    {
        cout << "Stack is empty!" << endl;
    }

    cout << "Count: " << stack.count() << endl;


    return 0;
}