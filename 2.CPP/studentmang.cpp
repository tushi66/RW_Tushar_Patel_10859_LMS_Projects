#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
public:
    int id;
    string name;
    float marks;

    Student() {
        id = 0;
        name = "";
        marks = 0.0;
    }

    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

class StudentManagement {
    Student students[MAX_STUDENTS];
    int count;

public:
    StudentManagement() {
        count = 0;
    }

    void addStudent() {
        if (count >= MAX_STUDENTS) {
            cout << "Student list is full.\n";
            return;
        }
        int id;
        string name;
        float marks;
        cout << "Enter Student ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Student Name: "; getline(cin, name);
        cout << "Enter Marks: "; cin >> marks;

        students[count] = Student(id, name, marks);
        count++;
        cout << "Student added successfully.\n";
    }

    void displayStudents() {
        if (count == 0) {
            cout << "No students to display.\n";
            return;
        }
        cout << "Student List:\n";
        for (int i = 0; i < count; i++) {
            students[i].display();
        }
    }

    void searchStudent() {
        if (count == 0) {
            cout << "No students to search.\n";
            return;
        }
        int searchId;
        cout << "Enter Student ID to search: "; cin >> searchId;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (students[i].id == searchId) {
                cout << "Student found:\n";
                students[i].display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Student with ID " << searchId << " not found.\n";
    }
};

int main() {
    StudentManagement sm;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.displayStudents(); break;
            case 3: sm.searchStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 4);

    return 0;
}
