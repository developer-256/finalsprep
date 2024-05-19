// Write a C++ function remove_duplicates(), this function will take a doubly linked list as input and checks if there is any duplication in the doubly linked list, if there is any, it should keep the first occurrence and remove the second one. (15 Marks)

// For example: Input double linked list is: 1<>3<>5<>1<>6<>7<>6<>9
// Output should be: 1<>3<>5<>6<>7<>9

#include <iostream>
using namespace std;

class Node
{
    int value;
    Node *nextNode;
    Node *prevNode;

public:
    Node() { value = 0, nextNode = nullptr, prevNode = nullptr; }
    Node(int value) { this->value = value, nextNode = nullptr, prevNode = nullptr; }
    void setValue(int value) { this->value = value; }
    int getValue() { return value; }
    void setNextNode(Node *nextNode) { this->nextNode = nextNode; }
    Node *getNextNode() { return nextNode; }
    void setPrevNode(Node *prevNode) { this->prevNode = prevNode; }
    Node *getPrevNode() { return prevNode; }
};

void remove_duplicates(Node *&headNode);
void insertAtTail(Node *&headNode, int value);
void printLinkedList(Node *&headNode);

int main()
{
    system("cls");
    Node *headNode = nullptr;
    insertAtTail(headNode, 1);
    insertAtTail(headNode, 3);
    insertAtTail(headNode, 5);
    insertAtTail(headNode, 1);
    insertAtTail(headNode, 6);
    insertAtTail(headNode, 7);
    insertAtTail(headNode, 6);
    insertAtTail(headNode, 9);

    cout << "Original List: \n";
    printLinkedList(headNode);

    remove_duplicates(headNode);

    cout << "List with duplicates removed: \n";
    printLinkedList(headNode);
    return 0;
}

void insertAtTail(Node *&headNode, int value)
{
    Node *newNode = new Node(value);
    if (headNode == nullptr)
    {
        headNode = newNode;
    }
    else
    {
        Node *currentNode = headNode;
        while (currentNode->getNextNode() != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        currentNode->setNextNode(newNode);
        newNode->setPrevNode(currentNode);
    }
}
void printLinkedList(Node *&headNode)
{
    if (headNode == nullptr)
    {
        return;
    }
    else
    {
        Node *currentNode = headNode;
        cout << "start -> ";
        while (currentNode->getNextNode() != nullptr)
        {
            cout << currentNode->getValue() << " <-> ";
            currentNode = currentNode->getNextNode();
        }
        cout << currentNode->getValue() << " <-> ";
        cout << "end\n";

        // cout << "end -> ";
        // while (currentNode != nullptr)
        // {
        //     cout << currentNode->getValue() << " -> ";
        //     currentNode = currentNode->getPrevNode();
        // }
        // cout << "start\n";
    }
}
void remove_duplicates(Node *&headNode)
{
    Node *currentNode = headNode;
    while (currentNode != nullptr)
    {
        Node *innerCurrentNode = currentNode->getNextNode();
        while (innerCurrentNode != nullptr)
        {
            if (currentNode->getValue() == innerCurrentNode->getValue())
            {
                Node *nodeToDelete = innerCurrentNode;
                if (innerCurrentNode->getNextNode() == nullptr)
                {
                    innerCurrentNode->getPrevNode()->setNextNode(nullptr);
                }
                else
                {
                    innerCurrentNode->getPrevNode()->setNextNode(innerCurrentNode->getNextNode());
                    innerCurrentNode->getNextNode()->setPrevNode(innerCurrentNode->getPrevNode());
                }
                innerCurrentNode = innerCurrentNode->getNextNode();
                delete nodeToDelete;
            }
            else
            {
                innerCurrentNode = innerCurrentNode->getNextNode();
            }
        }

        currentNode = currentNode->getNextNode();
    }
}

// QUESTION 2:
// A matrix is called magic matrix if its sum either diagonal, columnar or row wise is same. For example: Here sum is 15 if you sum the values in any above given order.

// Write a C++ function is_magic(), which takes a 2D array and its size as its parameters and return the Boolean value indicating whether the matrix is magic or not? (10 Marks)

#include <iostream>
using namespace std;

bool is_magic(int matrix[][3], int size);

int main()
{
    int size = 3;
    int matrix[3][3] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8},
    };

    if (is_magic(matrix, size))
    {
        cout << "This is a magic matrix\n";
    }
    else
    {
        cout << "This is not a magic matrix\n";
    }

    return 0;
}

bool is_magic(int matrix[][3], int size)
{
    int diagonal_1 = 0, diagonal_2 = 0;

    // checking sum of value of diagnol
    for (int i = 0; i < size; i++)
    {
        diagonal_1 += matrix[i][i];
    }

    // checking sum of value of other diagnol
    for (int i = 0; i < size; i++)
    {
        diagonal_2 += matrix[i][size - 1 - i];
    }

    // checking if sum of both diagnol is same
    if (diagonal_1 != diagonal_2)
    {
        return false;
    }

    // checking is sum of any row is not same as diagnol
    for (int i = 0; i < size; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < size; j++)
        {
            row_sum += matrix[i][j];
        }
        if (row_sum != diagonal_1)
        {
            return false;
        }
    }

    // checking is sum of any column is not same as diagnol
    for (int i = 0; i < size; i++)
    {
        int col_sum = 0;
        for (int j = 0; j < size; j++)
        {
            col_sum += matrix[j][i];
        }
        if (col_sum != diagonal_1)
        {
            return false;
        }
    }

    return true;
}
