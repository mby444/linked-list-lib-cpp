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

    cout << data << " tidak ditemukan" << endl;
    return NULL;
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
        int data = temp->data;
        delete temp;
        cout << data << " berhasil dihapus" << endl;
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
        int data = head->data;
        delete head;
        head = NULL;
        cout << data << " behasil dihapus" << endl;
    }
    else
    {
        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        int data = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        cout << data << " berhasil dihapus" << endl;
    }
}

void deleteNode(int data)
{
    bool found = false;

    if (isEmpty())
    {
        cout << "Linked list masih kosong" << endl;
    }
    else if (head->data == data)
    {
        deleteFront();
        found = true;
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
                cout << data << " berhasil dihapus" << endl;
                break;
            }
            temp = temp->next;
        }
    }
    if (!found)
    {
        cout << data << " tidak ditemukan" << endl;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout << "Linked list masih kosong" << endl;
    }
    else
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Linked list berhasil dikosongkan" << endl;
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
    cout << newData << " berhasil ditambahkan dari depan" << endl;
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
        cout << newData << " berhasil ditambahkan dari belakang" << endl;
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
            if (temp->data == dataAfter)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (found)
        {
            Node *newNode = createNode(newData);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << newData << " berhasil ditambahkan setelah " << dataAfter << endl;
        }
        else
        {
            cout << dataAfter << " tidak ditemukan" << endl;
        }
    }
}

void insertBefore(int dataBefore, int newData)
{
    if (isEmpty())
    {
        cout << "Linked list masih kosong" << endl;
    }
    else
    {
        Node *cur = head;
        Node *prev = NULL;
        bool found = false;

        while (!isNull(cur))
        {
            if (cur->data == dataBefore)
            {
                found = true;
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if (found)
        {
            Node *newNode = createNode(newData);
            newNode->next = cur;

            if (isNull(prev))
            {
                head = newNode;
            }
            else
            {
                prev->next = newNode;
            }
            cout << newData << " berhasil ditambahkan sebelum " << dataBefore << endl;
        }
        else
        {
            cout << dataBefore << " tidak ditemukan" << endl;
        }
    }
}

int main()
{
    insertFront(1);
    insertFront(2);
    insertFront(3);
    insertBack(1);
    insertBack(2);
    insertBack(3);

    display();
    clear();
    return 0;
}