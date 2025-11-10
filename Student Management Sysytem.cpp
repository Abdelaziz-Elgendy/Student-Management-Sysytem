/* Student Management System */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int grade;
    vector<string> courses;

public:
    Student(int id, string name, int grade) : id(id), name(name), grade(grade) {}

    int getId() { return id; }
    string getName() { return name; }
    int getGrade() { return grade; }

    void addCourse(string course) {
        courses.push_back(course);
    }

    void deleteCourse(string course) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i] == course) {
                courses.erase(courses.begin() + i);
                cout << "Course deleted successfully\n";
                return;
            }
        }
        cout << "Course Not Found\n";
    }

    void disPlay() {
        cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << "\nCourses: ";
        if (courses.empty())
            cout << "None";
        else {
            for (int i = 0; i < courses.size(); i++) {
                cout << courses[i] << " ";
            }
        }
        cout << "\n\n";
    }
};

class StudentManageer {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id, grade;
        string name;

        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Grade: ";
        cin >> grade;

        students.push_back(Student(id, name, grade));
        cout << "Student Added Successfully\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student Deleted Successfully\n";
                return;
            }
        }
        cout << "Student Not Found\n";
    }

    void addCourseToStudent() {
        int id;
        cout << "Enter Student ID to add course: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                string course;
                cout << "Enter Course Name: ";
                cin >> course;
                students[i].addCourse(course);
                cout << "Course Added Successfully\n";
                return;
            }
        }
        cout << "Student Not Found\n";
    }

    void deletCourseFromStudent() {
        int id;
        cout << "Enter Student ID to delete course: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                string course;
                cout << "Enter Course Name: ";
                cin >> course;
                students[i].deleteCourse(course);
                return;
            }
        }
        cout << "Student Not Found\n";
    }

    void displayAllStudents() {
        if (students.empty()) {
            cout << "No Students Available\n";
            return;
        }
        cout << "\n--- List of Students ---\n";
        for (int i = 0; i < students.size(); i++) {
            students[i].disPlay();
        }
    }
};


void menu() {
    StudentManageer manager;
    int choice;

    do {
        cout << "\n==== Student Management System ====\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Add Course to Student\n";
        cout << "4. Delete Course from Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.deleteStudent();
            break;
        case 3:
            manager.addCourseToStudent();
            break;
        case 4:
            manager.deletCourseFromStudent();
            break;
        case 5:
            manager.displayAllStudents();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
