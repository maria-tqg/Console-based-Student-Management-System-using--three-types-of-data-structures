#include <iostream>     // For input and output (cin, cout)
#include <cstring>      // For string handling functions like strcmp
#include <iomanip>      // For formatting output (setw)

using namespace std;

// Maximum limits
const int MAX_STUDENTS = 100;          // Maximum number of students allowed
const int MAX_NAME_LENGTH = 50;        // Maximum length of student name
const int MAX_COURSE_LENGTH = 50;      // Maximum length of course name

// Structure to store student information
struct Student {
    int id;                             // Student ID
    char name[MAX_NAME_LENGTH];         // Student name
    int age;                            // Student age
    char course[MAX_COURSE_LENGTH];     // Student course
};

// Global student array and counter
Student students[MAX_STUDENTS];         // Array to store students
int studentCount = 0;                   // Current number of students

// ================= STACK (Linked List for Undo) =================

// Node structure for stack (used for undo functionality)
struct StackNode {
    Student data;       // Student data
    string action;      // Action performed: insert, delete, update
    int index;          // Index where action occurred
    StackNode* next;    // Pointer to next node
};

StackNode* topStack = NULL;  // Pointer to top of stack

// Push a new action onto the stack
void push(Student s, string action, int index) {
    StackNode* newNode = new StackNode;  // Create new node
    newNode->data = s;
    newNode->action = action;
    newNode->index = index;
    newNode->next = topStack;
    topStack = newNode;                  // Update top pointer
}

// Check if stack is empty
bool isStackEmpty() {
    return topStack == NULL;
}

// Pop the top element from the stack
StackNode pop() {
    StackNode temp = *topStack;          // Copy top node
    StackNode* del = topStack;
    topStack = topStack->next;           // Move top to next node
    delete del;                          // Free memory
    return temp;                         // Return popped node
}

// ================= QUEUE (Linked List for Reports) =================

// Node structure for queue (used for statistics/report tracking)
struct QueueNode {
    string reportType;   // Type of report
    QueueNode* next;     // Pointer to next node
};

QueueNode* frontQueue = NULL;   // Front pointer of queue
QueueNode* rearQueue = NULL;    // Rear pointer of queue

// Add a new report request to queue
void enqueue(string report) {
    QueueNode* newNode = new QueueNode;
    newNode->reportType = report;
    newNode->next = NULL;

    if (rearQueue == NULL) {     // If queue is empty
        frontQueue = rearQueue = newNode;
    } else {
        rearQueue->next = newNode;
        rearQueue = newNode;
    }
}

// Check if queue is empty
bool isQueueEmpty() {
    return frontQueue == NULL;
}

// Remove an element from the queue
string dequeue() {
    if (isQueueEmpty()) return "";

    QueueNode* temp = frontQueue;
    string report = temp->reportType;
    frontQueue = frontQueue->next;

    if (frontQueue == NULL)
        rearQueue = NULL;

    delete temp;                 // Free memory
    return report;
}

// ================= FUNCTIONS =================

// Function to print text centered within a given width
void printCentered(const string &text, int width) {
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; ++i)
        cout << " ";
    cout << text << endl;
}

// Check if student ID is unique
bool isUniqueID(int id) {
    for (int i = 0; i < studentCount; i++)
        if (students[i].id == id)
            return false;
    return true;
}

// Insert new student record
void insertStudent() {

    // Check if array is full
    if (studentCount >= MAX_STUDENTS) {
        printCentered("Student record list is full.", 100);
        return;
    }

    Student newStudent;

    // Input student ID
    cout << "Enter Student ID:  ";
    cin >> newStudent.id;

    // Ensure ID is unique
    while (!isUniqueID(newStudent.id)) {
        printCentered("ID already exists. Enter a unique Student ID: ", 100);
        cin >> newStudent.id;
    }

    cin.ignore();

    // Input student name
    cout << "Enter Student Name: ";
    cin.getline(newStudent.name, MAX_NAME_LENGTH);

    // Input student age
    cout << "Enter Student Age:  ";
    cin >> newStudent.age;

    // Validate age input
    while (cin.fail() || newStudent.age <= 0 || newStudent.age > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        printCentered("Invalid age. Please enter a valid age (1-100): ", 100);
        cin >> newStudent.age;
    }

    cin.ignore();

    // Input student course
    cout << "Enter Student Course: ";
    cin.getline(newStudent.course, MAX_COURSE_LENGTH);

    // Store student in array
    students[studentCount] = newStudent;

    // Save action to stack for undo
    push(newStudent, "insert", studentCount);

    studentCount++;  // Increase student count

    printCentered("Student record inserted successfully.", 100);
}

// View all student records
void viewAllStudents() {

    if (studentCount == 0) {
        printCentered("No student records found.", 100);
        return;
    }

    // Print table header
    printCentered("ID            Name            Age           Course", 90);
    printCentered("---------------------------------------------------------------", 100);

    // Display each student
    for (int i = 0; i < studentCount; i++) {
        cout << setw(17) << students[i].id
             << setw(20) << students[i].name
             << setw(18) << students[i].age
             << setw(22) << students[i].course << endl;
    }
}

// Search student by ID
void searchStudentByID() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
                 printCentered("Student Information", 100);
            cout << "ID: " << students[i].id
                 << ", Name: " << students[i].name
                 << ", Age: " << students[i].age
                 << ", Course: " << students[i].course << endl;
            return;
        }
    }

    printCentered("Student record not found.", 100);
}

// Search student by Name
void searchStudentByName() {
    char name[MAX_NAME_LENGTH];

    printCentered("Enter Student Name to search: ", 50);
    cin.ignore();
    cin.getline(name, MAX_NAME_LENGTH);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, name) == 0) {
                printCentered("Student Information", 100);
            cout << "ID: " << students[i].id
                 << ", Name: " << students[i].name
                 << ", Age: " << students[i].age
                 << ", Course: " << students[i].course << endl;
            return;
        }
    }

    printCentered("Student record not found.", 100);
}

// Delete student record
void deleteStudent() {
    int id;
    printCentered("Enter Student ID to delete: ", 100);
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {

            // Save delete action for undo
            push(students[i], "delete", i);

            // Shift elements left
            for (int j = i; j < studentCount - 1; j++)
                students[j] = students[j + 1];

            studentCount--;

            printCentered("Student record deleted successfully.", 100);
            return;
        }
    }

    printCentered("Student record not found.", 100);
}

// Update student record
void updateStudent() {
    int id;
    printCentered("Enter Student ID to update: ", 100);
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {

            // Save old data for undo
            push(students[i], "update", i);

            cin.ignore();

            // Input new name
            printCentered("Enter new Student Name: ", 100);
            cin.getline(students[i].name, MAX_NAME_LENGTH);

            // Input new age
            printCentered("Enter new Student Age: ", 100);
            cin >> students[i].age;

            cin.ignore();

            // Input new course
            printCentered("Enter new Student Course: ", 100);
            cin.getline(students[i].course, MAX_COURSE_LENGTH);

            printCentered("Student record updated successfully.", 100);
            return;
        }
    }

    printCentered("Student record not found.", 100);
}

// Undo last action performed
void undoLastAction() {

    if (isStackEmpty()) {
        printCentered("Nothing to undo.", 100);
        return;
    }

    StackNode last = pop();  // Get last action

    if (last.action == "insert") {
        studentCount--;      // Remove last inserted student
    }
    else if (last.action == "delete") {

        // Shift elements right
        for (int j = studentCount; j > last.index; j--)
            students[j] = students[j - 1];

        students[last.index] = last.data;
        studentCount++;
    }

    printCentered("Last action undone successfully.", 100);
}

// Sort students alphabetically by name (Bubble Sort)
void sortStudentsByName() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printCentered("Students sorted by name.", 100);
}

// Display statistics (total students and average age)
void displayStatistics() {

    enqueue("Statistics");  // Add report request to queue

    while (!isQueueEmpty()) {
        dequeue();          // Process report

        if (studentCount == 0) {
            printCentered("No student records to calculate statistics.", 100);
            return;
        }

        int totalAge = 0;

        // Calculate total age
        for (int i = 0; i < studentCount; i++)
            totalAge += students[i].age;

        cout << "Total number of students: " << studentCount << endl;
        cout << "Average age of students: "
             << static_cast<float>(totalAge) / studentCount << endl;
    }
}

// ================= MAIN =================

int main() {
    int choice;

    do {
        // Display menu
        printCentered("..................................................................................", 100);
        printCentered("...................... Student Management System Menu ............................", 100);
        printCentered("........................ Build By MST. Maria.................................", 100);
        printCentered("-------------------------------------------------------------------------",100);

        printCentered("1. Add Student", 90);
        printCentered("2. View All Student Records", 104);
        printCentered("3. Search Student Record by ID", 107);
        printCentered("4. Search Student Record by Name", 108);
        printCentered("5. Delete Student Record", 100);
        printCentered("6. Update Student Record", 100);
        printCentered("7. Sort Students by Name", 100);
        printCentered("8. Display Statistics", 98);
        printCentered("9. Undo Last Action", 95);
        printCentered("10. Exit", 84);
        printCentered("--------------------------------------------", 100);

        cout << "Enter Choice: ";
        cin >> choice;

        // Perform action based on user choice
        switch (choice) {
            case 1: insertStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: searchStudentByID(); break;
            case 4: searchStudentByName(); break;
            case 5: deleteStudent(); break;
            case 6: updateStudent(); break;
            case 7: sortStudentsByName(); break;
            case 8: displayStatistics(); break;
            case 9: undoLastAction(); break;
            case 10: printCentered("Exiting the program.", 50); break;
            default: printCentered("Invalid choice. Please try again.", 50);
        }

    } while (choice != 10);

    return 0;
}
