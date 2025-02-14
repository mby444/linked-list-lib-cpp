#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

bool isEmpty()
{
    return head == NULL;
}

bool isNull(Node *node)
{
    return node == NULL;
}

bool isNextNull(Node *node)
{
    return node->next == NULL;
}

void display()
{
    if (!isEmpty())
    {
        Node *temp = head;

        while (!isNull(temp))
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
    else
    {
        cout << "Linked list masih kosong" << endl;
    }
}

Node *search(int data)
{
    if (isEmpty())
    {
        return NULL;
    }

    Node *temp = head;
    bool found = false;

    while (!isNull(temp))
    {
        if (temp->data == data)
        {
            found = true;
            break;
        };
        temp = temp->next;
    }

    if (found)
    {
        return temp;
    }

    return NULL;
}

void deleteNode(int data)
{
    bool found = false;

    if (isEmpty())
    {
        cout << "Linked list masih kosong" << endl;
    }
    else if (isNextNull(head))
    {
        if (head->data == data)
        {
            delete head;
            head = NULL;
            found = true;
        }
    }
    else
    {
        Node *temp = head;

        while (!isNextNull(temp))
        {
            if (temp->next->data == data)
            {
                found = true;
                Node *temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
            }
            temp = temp->next;
        }
    }
    if (!found)
    {
        cout << data << " tidak ditemukan" << endl;
    }
}

void deleteFront()
{
    if (isEmpty())
    {
        cout << "Linked list masih kosong" << endl;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteBack()
{
    if (isEmpty())
    {
        cout << "Linked list masih kosong" << endl;
    }
    else if (isNextNull(head))
    {
        deleteFront();
    }
    else
    {
        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

void clearNode()
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *createNode(int newData)
{
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int newData)
{
    Node *newNode = createNode(newData);

    if (!isEmpty())
    {
        newNode->next = head;
    }

    head = newNode;
}

void insertBack(int newData)
{
    Node *newNode = createNode(newData);

    if (isEmpty())
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (!isNextNull(temp))
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertAfter(int dataAfter, int newData)
{
    if (isEmpty())
    {
        cout << "Linked list masih kosong" << endl;
    }
    else
    {
        Node *temp = head;
        bool found = false;

        while (!isNull(temp))
        {
            if (!isNextNull(temp))
                temp = temp->next;
        }
    }
}

void insertBefore()
{
}

int main()
{

    return 0;
}