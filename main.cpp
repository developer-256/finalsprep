// final 1
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int data) {
        if (!head) {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(data);
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void InsertBeforeEnd(int data1, int data2) {
        if (!head || !head->next || !head->next->next) {
            cout << "List is too short to perform the insertion." << endl;
            return;
        }

        Node* current = head;

        while (current->next->next->next) {
            current = current->next;
        }

        Node* firstNewNode = new Node(data1);
        Node* secondNewNode = new Node(data2);

        firstNewNode->next = current->next;
        current->next = firstNewNode;
        
        secondNewNode->next = firstNewNode->next;
        firstNewNode->next = secondNewNode;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    cout << "Original List: ";
    list.printList();

    list.InsertBeforeEnd(6, 7);

    cout << "Modified List: ";
    list.printList();

    return 0;
}


// final 2

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int data) {
        if (!head) {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(data);
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void InsertBeforeEnd(int data1, int data2) {
        if (!head || !head->next || !head->next->next) {
            cout << "List is too short to perform the insertion." << endl;
            return;
        }

        Node* current = head;

        while (current->next->next->next) {
            current = current->next;
        }

        Node* firstNewNode = new Node(data1);
        Node* secondNewNode = new Node(data2);

        firstNewNode->next = current->next;
        current->next = firstNewNode;
        
        secondNewNode->next = firstNewNode->next;
        firstNewNode->next = secondNewNode;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    cout << "Original List: ";
    list.printList();

    list.InsertBeforeEnd(6, 7);

    cout << "Modified List: ";
    list.printList();

    return 0;
}


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



// 1. *Patient Management System*: Implement a doubly linked list to manage patient records in a hospital. Each node should store patient ID, name, and age. Implement functions to:
//    - Add a new patient to the end of the list.
//    - Remove a patient by ID.
//    - Search for a patient by name.
//    - Print all patient records.

class PatientManagementSystem
{
private:
    Node *headNode;
    Node *currentNode;
    int size;

public:
    PatientManagementSystem();
    ~PatientManagementSystem();
    void addPatient(int id, string name, int age);
    void removePatient(int id);
    void searchPatient(string name);
    void printAllPatients();
};

PatientManagementSystem::PatientManagementSystem() { size = 0, headNode = nullptr, currentNode = nullptr; }
PatientManagementSystem::~PatientManagementSystem() { delete headNode, delete currentNode; }

void PatientManagementSystem::addPatient(int id, string name, int age)
{
    Node *newNode = new Node(id, name, age);
    if (headNode == nullptr)
    {
        headNode = newNode;
    }
    else
    {
        currentNode = headNode;
        while (currentNode->getNextNode() != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        currentNode->setNextNode(newNode);
        newNode->setPrevNode(currentNode);
    }
    size++;
    cout << "Patient successfully added\n";
}

void PatientManagementSystem::removePatient(int id)
{
    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getId() == id)
        {
            if (currentNode == headNode)
            {
                headNode = currentNode->getNextNode();
            }

            if (currentNode->getNextNode() != nullptr)
            {
                currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());
            }

            if (currentNode->getPrevNode() != nullptr)
            {
                currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
            }

            delete currentNode;
            size--;
            cout << "Patient removed successfully\n";
            return;
        }

        currentNode = currentNode->getNextNode();
    }
}

void PatientManagementSystem::searchPatient(string name)
{
    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getName() == name)
        {
            currentNode->displayPatient();
            return;
        }
        currentNode = currentNode->getNextNode();
    }
    cout << "Patient not found\n";
}

void PatientManagementSystem::printAllPatients()
{
    if (headNode == nullptr)
    {
        cout << "No patient found\n";
    }
    else
    {
        currentNode = headNode;
        while (currentNode != nullptr)
        {
            currentNode->displayPatient();
            currentNode = currentNode->getNextNode();
        }
    }
}

// Student Attendance System: Use a circular linked list to keep track of students' attendance. Each node should store student ID, name, and attendance status (Present/Absent). Implement functions to:
//    - Mark a student as present or absent.
//    - Remove a student's attendance record.
//    - Display the attendance of all students.
//    - Count the number of students present.

#include <iostream>
#include <string>
using namespace std;

class StudentNode {
public:
    int id;
    string name;
    bool isPresent;
    StudentNode* next;
    StudentNode* prev;

    StudentNode(int id, string name, bool isPresent)
        : id(id), name(name), isPresent(isPresent), next(this), prev(this) {}
};

class AttendanceSystem {
private:
    StudentNode* head;
    int size;

public:
    AttendanceSystem() : head(nullptr), size(0) {}

    ~AttendanceSystem() {
        while (size > 0) {
            removeStudent(head->id);
        }
    }

    void markAttendance(int id, string name, bool isPresent) {
        StudentNode* newNode = new StudentNode(id, name, isPresent);
        if (head == nullptr) {
            head = newNode;
        } else {
            StudentNode* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        size++;
        cout << "Attendance marked for student: " << name << endl;
    }

    void removeStudent(int id) {
        if (head == nullptr) return;

        StudentNode* current = head;
        do {
            if (current->id == id) {
                if (current == head) {
                    if (head->next == head) {
                        delete head;
                        head = nullptr;
                    } else {
                        StudentNode* tail = head->prev;
                        head = head->next;
                        tail->next = head;
                        head->prev = tail;
                        delete current;
                    }
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                size--;
                cout << "Student with ID " << id << " removed from attendance." << endl;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void displayAttendance() {
        if (head == nullptr) {
            cout << "No student attendance records found." << endl;
            return;
        }

        StudentNode* current = head;
        do {
            cout << "ID: " << current->id << ", Name: " << current->name
                 << ", Attendance: " << (current->isPresent ? "Present" : "Absent") << endl;
            current = current->next;
        } while (current != head);
    }

    int countPresentStudents() {
        if (head == nullptr) return 0;

        int count = 0;
        StudentNode* current = head;
        do {
            if (current->isPresent) count++;
            current = current->next;
        } while (current != head);

        return count;
    }
};

int main() {
    AttendanceSystem attendanceSystem;

    attendanceSystem.markAttendance(1, "Alice", true);
    attendanceSystem.markAttendance(2, "Bob", false);
    attendanceSystem.markAttendance(3, "Charlie", true);

    cout << "\nDisplaying all student attendance records:" << endl;
    attendanceSystem.displayAttendance();

    cout << "\nNumber of students present: " << attendanceSystem.countPresentStudents() << endl;

    attendanceSystem.removeStudent(2);

    cout << "\nDisplaying all student attendance records after removing a student:" << endl;
    attendanceSystem.displayAttendance();

    return 0;
}


// 3. Library Book Management: Create a singly linked list to manage books in a library. Each node should store book ID, title, and author. Implement functions to:
//    - Add a new book to the start of the list.
//    - Remove a book by title.
//    - Search for a book by author.
//    - Print all books in the library.

#include <iostream>
#include <string>
using namespace std;

class BookNode {
public:
    int id;
    string title;
    string author;
    BookNode* next;

    BookNode(int id, string title, string author)
        : id(id), title(title), author(author), next(nullptr) {}
};

class Library {
private:
    BookNode* head;
    int size;

public:
    Library() : head(nullptr), size(0) {}

    ~Library() {
        while (head != nullptr) {
            BookNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addBook(int id, string title, string author) {
        BookNode* newBook = new BookNode(id, title, author);
        newBook->next = head;
        head = newBook;
        size++;
        cout << "Book added: " << title << " by " << author << endl;
    }

    void removeBook(string title) {
        if (head == nullptr) {
            cout << "Book not found: " << title << endl;
            return;
        }

        if (head->title == title) {
            BookNode* temp = head;
            head = head->next;
            delete temp;
            size--;
            cout << "Book removed: " << title << endl;
            return;
        }

        BookNode* current = head;
        while (current->next != nullptr && current->next->title != title) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Book not found: " << title << endl;
        } else {
            BookNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            cout << "Book removed: " << title << endl;
        }
    }

    void searchBookByAuthor(string author) {
        BookNode* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->author == author) {
                cout << "Book found: " << current->title << " by " << author << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No books found by author: " << author << endl;
        }
    }

    void printAllBooks() {
        if (head == nullptr) {
            cout << "No books in the library." << endl;
            return;
        }

        BookNode* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->id << ", Title: " << current->title
                 << ", Author: " << current->author << endl;
            current = current->next;
        }
    }
};

int main() {
    Library library;

    library.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook(2, "To Kill a Mockingbird", "Harper Lee");
    library.addBook(3, "1984", "George Orwell");

    cout << "\nAll books in the library:" << endl;
    library.printAllBooks();

    library.removeBook("To Kill a Mockingbird");

    cout << "\nAll books in the library after removal:" << endl;
    library.printAllBooks();

    library.searchBookByAuthor("George Orwell");
    library.searchBookByAuthor("J.K. Rowling");

    return 0;
}


// Browser History: Implement a stack to manage a web browser's history. Each entry should store the URL of a visited page. Implement functions to:
//    - Visit a new URL (push).
//    - Go back to the previous URL (pop).
//    - View the current URL (peek).
//    - Display all URLs in the history.

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string url;
    Node *next;
    Node *prev;

    Node(string u) : url(u), next(nullptr), prev(nullptr) {}
};

class BrowserHistory
{
private:
    Node *top;

public:
    BrowserHistory() : top(nullptr) {}

    void visit(string url)
    {
        Node *newNode = new Node(url);
        if (top)
        {
            newNode->prev = top;
            top->next = newNode;
        }
        top = newNode;
        cout << "Visited: " << url << endl;
    }

    void goBack()
    {
        if (!top)
        {
            cout << "No history to go back to.\n";
            return;
        }
        cout << "Going back from: " << top->url << endl;
        Node *temp = top;
        top = top->prev;
        if (top)
        {
            top->next = nullptr;
        }
        delete temp;
    }

    void viewCurrent()
    {
        if (!top)
        {
            cout << "No current URL.\n";
        }
        else
        {
            cout << "Current URL: " << top->url << endl;
        }
    }

    void displayHistory()
    {
        Node *current = top;
        while (current)
        {
            cout << current->url << endl;
            current = current->prev;
        }
    }
};

int main()
{
    BrowserHistory history;
    history.visit("http://example.com");
    history.visit("http://google.com");
    history.visit("http://stackoverflow.com");

    history.viewCurrent();
    history.goBack();
    history.viewCurrent();
    history.displayHistory();

    return 0;
}

// array stack implementation
#include <iostream>
#include <string>
using namespace std;

class ArrayStack {
private:
    static const int MAX_SIZE = 100;
    string stack[MAX_SIZE];
    int top;

public:
    ArrayStack() : top(-1) {}

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(string url) {
        if (isFull()) {
            cout << "Stack is full. Cannot push URL: " << url << endl;
            return;
        }
        stack[++top] = url;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return "";
        }
        return stack[top--];
    }

    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return "";
        }
        return stack[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << stack[i] << endl;
        }
    }
};

int main() {
    ArrayStack browserHistory;

    browserHistory.push("http://example.com");
    browserHistory.push("http://example.com/page1");
    browserHistory.push("http://example.com/page2");

    cout << "Current URL: " << browserHistory.peek() << endl;

    browserHistory.pop();

    cout << "Current URL after going back: " << browserHistory.peek() << endl;

    cout << "All URLs in history:" << endl;
    browserHistory.display();

    return 0;
}


 // Undo Functionality in Text Editor: Use a stack to implement undo functionality in a text editor. Each operation (insert, delete) should be stored in the stack. Implement functions to:
 //   - Record an operation (push).
 //   - Undo the last operation (pop).
 //   - Display the current state of the text.

#include <iostream>
#include <string>
using namespace std;

class Operation
{
public:
    string type;
    string content;
    int position;
    Operation *next;
    Operation *prev;

    Operation(string t, string c, int p) : type(t), content(c), position(p), next(nullptr), prev(nullptr) {}
};

class TextEditor
{
private:
    Operation *top;
    string text;

public:
    TextEditor() : top(nullptr) {}

    void recordOperation(string type, string content, int position)
    {
        Operation *newOp = new Operation(type, content, position);
        if (top)
        {
            newOp->prev = top;
            top->next = newOp;
        }
        top = newOp;
    }

    void insertText(string content, int position)
    {
        text.insert(position, content);
        recordOperation("insert", content, position);
    }

    void deleteText(int position, int length)
    {
        string deletedText = text.substr(position, length);
        text.erase(position, length);
        recordOperation("delete", deletedText, position);
    }

    void undo()
    {
        if (!top)
        {
            cout << "Nothing to undo.\n";
            return;
        }
        Operation *temp = top;
        if (temp->type == "insert")
        {
            text.erase(temp->position, temp->content.length());
        }
        else if (temp->type == "delete")
        {
            text.insert(temp->position, temp->content);
        }
        top = top->prev;
        if (top)
        {
            top->next = nullptr;
        }
        delete temp;
    }

    void displayText()
    {
        cout << "Current Text: " << text << endl;
    }
};

int main()
{
    TextEditor editor;
    editor.insertText("Hello", 0);
    editor.insertText(" World", 5);
    editor.displayText();

    editor.deleteText(5, 6);
    editor.displayText();

    editor.undo();
    editor.displayText();

    editor.undo();
    editor.displayText();

    return 0;
}

// Arithmetic Expression Evaluation: Implement a stack-based solution to evaluate arithmetic expressions in postfix notation. Each token can be an operator (+, -, *, /) or an operand (number). Implement functions to:
//    - Push operands onto the stack.
//    - Perform operations using stack elements.
//    - Return the result of the expression.
#include <iostream>
#include <cstring>
using namespace std;

class OperandNode {
public:
    double value;
    OperandNode* next;
    OperandNode* prev;

    OperandNode(double v) : value(v), next(nullptr), prev(nullptr) {}
};

class ExpressionEvaluator {
private:
    OperandNode* top;

public:
    ExpressionEvaluator() : top(nullptr) {}

    void push(double value) {
        OperandNode* newNode = new OperandNode(value);
        if (top) {
            newNode->prev = top;
            top->next = newNode;
        }
        top = newNode;
    }

    double pop() {
        if (!top) {
            throw runtime_error("Stack underflow");
        }
        OperandNode* temp = top;
        double value = temp->value;
        top = top->prev;
        if (top) {
            top->next = nullptr;
        }
        delete temp;
        return value;
    }

    double evaluatePostfix(const char* expression) {
        char* token = strtok(const_cast<char*>(expression), " ");
        while (token != nullptr) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                push(atof(token));
            } else {
                double operand2 = pop();
                double operand1 = pop();
                if (strcmp(token, "+") == 0) {
                    push(operand1 + operand2);
                } else if (strcmp(token, "-") == 0) {
                    push(operand1 - operand2);
                } else if (strcmp(token, "*") == 0) {
                    push(operand1 * operand2);
                } else if (strcmp(token, "/") == 0) {
                    push(operand1 / operand2);
                }
            }
            token = strtok(nullptr, " ");
        }
        return pop();
    }
};

int main() {
    ExpressionEvaluator evaluator;
    char expression[] = "3 4 + 2 * 7 /";
    cout << "Postfix Expression: " << expression << endl;
    double result = evaluator.evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}

// Ticket Booking System: Implement a queue to manage ticket bookings for an event. Each node should store booking ID, customer name, and number of tickets. Implement functions to:
//    - Add a new booking to the queue.
//    - Serve the next booking (dequeue).
//    - Display all bookings in the queue.
//    - Count the total number of bookings.

#include <iostream>
#include <string>
using namespace std;

class BookingNode {
public:
    int bookingID;
    string customerName;
    int numberOfTickets;
    BookingNode* next;

    BookingNode(int id, string name, int tickets)
        : bookingID(id), customerName(name), numberOfTickets(tickets), next(nullptr) {}
};

class TicketBookingQueue {
private:
    BookingNode* front;
    BookingNode* rear;
    int count;

public:
    TicketBookingQueue() : front(nullptr), rear(nullptr), count(0) {}

    void addBooking(int id, string name, int tickets) {
        BookingNode* newNode = new BookingNode(id, name, tickets);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
        count++;
        cout << "Booking added successfully\n";
    }

    void serveBooking() {
        if (!front) {
            cout << "No bookings to serve\n";
            return;
        }
        BookingNode* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        cout << "Served booking ID: " << temp->bookingID << endl;
        delete temp;
        count--;
    }

    void displayBookings() {
        BookingNode* current = front;
        while (current) {
            cout << "Booking ID: " << current->bookingID << ", Name: " << current->customerName << ", Tickets: " << current->numberOfTickets << endl;
            current = current->next;
        }
    }

    int getTotalBookings() {
        return count;
    }
};

int main() {
    TicketBookingQueue queue;
    queue.addBooking(1, "Alice", 2);
    queue.addBooking(2, "Bob", 4);
    queue.addBooking(3, "Charlie", 1);

    queue.displayBookings();
    cout << "Total bookings: " << queue.getTotalBookings() << endl;

    queue.serveBooking();
    queue.displayBookings();
    cout << "Total bookings: " << queue.getTotalBookings() << endl;

    return 0;
}


// 2. Printer Job Scheduling: Use a queue to manage print jobs in a printer. Each job should store job ID, document name, and number of pages. Implement functions to:
//    - Add a new print job to the queue.
//    - Serve the next print job (dequeue).
//    - Display all pending print jobs.
//    - Check if the queue is empty.

#include <iostream>
#include <string>
using namespace std;

class PrintJobNode {
public:
    int jobID;
    string documentName;
    int numberOfPages;
    PrintJobNode* next;

    PrintJobNode(int id, string docName, int pages)
        : jobID(id), documentName(docName), numberOfPages(pages), next(nullptr) {}
};

class PrinterJobQueue {
private:
    PrintJobNode* front;
    PrintJobNode* rear;

public:
    PrinterJobQueue() : front(nullptr), rear(nullptr) {}

    void addPrintJob(int id, string docName, int pages) {
        PrintJobNode* newNode = new PrintJobNode(id, docName, pages);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
        cout << "Print job added successfully\n";
    }

    void servePrintJob() {
        if (!front) {
            cout << "No print jobs to serve\n";
            return;
        }
        PrintJobNode* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        cout << "Served print job ID: " << temp->jobID << endl;
        delete temp;
    }

    void displayPrintJobs() {
        PrintJobNode* current = front;
        while (current) {
            cout << "Job ID: " << current->jobID << ", Document: " << current->documentName << ", Pages: " << current->numberOfPages << endl;
            current = current->next;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    PrinterJobQueue queue;
    queue.addPrintJob(1, "Doc1", 10);
    queue.addPrintJob(2, "Doc2", 5);
    queue.addPrintJob(3, "Doc3", 15);

    queue.displayPrintJobs();

    queue.servePrintJob();
    queue.displayPrintJobs();

    cout << "Is queue empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

// circular queue implementation
#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    static const int MAX_SIZE = 100;
    struct Job {
        int jobID;
        string documentName;
        int numberOfPages;
    } queue[MAX_SIZE];

    int front;
    int rear;
    int count;

public:
    CircularQueue() : front(0), rear(0), count(0) {}

    bool isFull() {
        return count == MAX_SIZE;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int jobID, string documentName, int numberOfPages) {
        if (isFull()) {
            cout << "Queue is full. Cannot add job: " << documentName << endl;
            return;
        }
        queue[rear].jobID = jobID;
        queue[rear].documentName = documentName;
        queue[rear].numberOfPages = numberOfPages;
        rear = (rear + 1) % MAX_SIZE;
        count++;
    }

    Job dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return {0, "", 0};
        }
        Job job = queue[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        return job;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        int c = count;
        while (c > 0) {
            cout << "Job ID: " << queue[i].jobID
                 << ", Document Name: " << queue[i].documentName
                 << ", Number of Pages: " << queue[i].numberOfPages << endl;
            i = (i + 1) % MAX_SIZE;
            c--;
        }
    }

    int getSize() {
        return count;
    }
};

int main() {
    CircularQueue printerQueue;

    printerQueue.enqueue(1, "Document1", 10);
    printerQueue.enqueue(2, "Document2", 5);
    printerQueue.enqueue(3, "Document3", 15);

    cout << "All print jobs in the queue:" << endl;
    printerQueue.display();

    CircularQueue::Job job = printerQueue.dequeue();
    cout << "Serving job: " << job.documentName << endl;

    cout << "All print jobs in the queue after serving one job:" << endl;
    printerQueue.display();

    return 0;
}


// 3. Customer Service System: Create a queue to manage customer service requests. Each request should store request ID, customer name, and issue description. Implement functions to:
//    - Add a new service request to the queue.
//    - Serve the next service request (dequeue).
//    - Display all pending service requests.
//    - Find and display a service request by customer name.

#include <iostream>
#include <string>
using namespace std;

class ServiceRequestNode {
public:
    int requestID;
    string customerName;
    string issueDescription;
    ServiceRequestNode* next;

    ServiceRequestNode(int id, string name, string issue)
        : requestID(id), customerName(name), issueDescription(issue), next(nullptr) {}
};

class CustomerServiceQueue {
private:
    ServiceRequestNode* front;
    ServiceRequestNode* rear;

public:
    CustomerServiceQueue() : front(nullptr), rear(nullptr) {}

    void addServiceRequest(int id, string name, string issue) {
        ServiceRequestNode* newNode = new ServiceRequestNode(id, name, issue);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
        cout << "Service request added successfully\n";
    }

    void serveServiceRequest() {
        if (!front) {
            cout << "No service requests to serve\n";
            return;
        }
        ServiceRequestNode* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        cout << "Served request ID: " << temp->requestID << endl;
        delete temp;
    }

    void displayServiceRequests() {
        ServiceRequestNode* current = front;
        while (current) {
            cout << "Request ID: " << current->requestID << ", Name: " << current->customerName << ", Issue: " << current->issueDescription << endl;
            current = current->next;
        }
    }

    void findServiceRequestByName(const string& name) {
        ServiceRequestNode* current = front;
        while (current) {
            if (current->customerName == name) {
                cout << "Request ID: " << current->requestID << ", Name: " << current->customerName << ", Issue: " << current->issueDescription << endl;
                return;
            }
            current = current->next;
        }
        cout << "Service request for customer " << name << " not found\n";
    }
};

int main() {
    CustomerServiceQueue queue;
    queue.addServiceRequest(1, "Alice", "Cannot login");
    queue.addServiceRequest(2, "Bob", "Error in payment");
    queue.addServiceRequest(3, "Charlie", "Account suspended");

    queue.displayServiceRequests();

    queue.serveServiceRequest();
    queue.displayServiceRequests();

    queue.findServiceRequestByName("Bob");

    return 0;
}

// Adding and Searching in Binary Search Tree:
// Create a program that allows users to build a binary search tree by adding nodes, and then search for a specific value in the tree.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    cout << "Enter a value to search: ";
    int value;
    cin >> value;

    if (search(root, value)) {
        cout << value << " found in the tree.\n";
    } else {
        cout << value << " not found in the tree.\n";
    }

    return 0;
}


// Deletion from Binary Search Tree:
// Develop a program where users can insert nodes into a binary search tree and then delete a specific value from the tree.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter the value to be deleted: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
