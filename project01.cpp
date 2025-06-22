#include <bits/stdc++.h>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
public:
    int id;
    string name;
    int age;
    string course;
};

vector<Student> students;

// Function to center text
void printCentered(const string &text, int width) {
    int padding = (width - text.length()) / 2;
    if (padding < 0) padding = 0;
    cout << string(padding, ' ') << text << endl;
}

// Check if ID is unique
bool isUniqueID(int id) {
    for (const auto &s : students) {
        if (s.id == id) return false;
    }
    return true;
}

// Insert student
void insertStudent() {
    if (students.size() >= MAX_STUDENTS) {
        printCentered("Student record list is full.", 100);
        return;
    }

    Student s;

    printCentered("Enter Student ID: ", 100);
    cin >> s.id;
    while (!isUniqueID(s.id)) {
        printCentered("ID already exists. Enter a unique Student ID: ", 100);
        cin >> s.id;
    }

    cin.ignore(); // clear newline

    printCentered("Enter Student Name: ", 100);
    getline(cin, s.name);

    printCentered("Enter Student Age: ", 100);
    cin >> s.age;
    while (cin.fail() || s.age <= 0 || s.age > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        printCentered("Invalid age. Please enter a valid age (1-100): ", 100);
        cin >> s.age;
    }

    cin.ignore();

    printCentered("Enter Student Course: ", 100);
    getline(cin, s.course);

    students.push_back(s);
    printCentered("Student record inserted successfully.", 100);
}

// View all students
void viewAllStudents() {
    if (students.empty()) {
        printCentered("No student records found.", 100);
        return;
    }

    printCentered("ID\tName\t\tAge\tCourse", 100);
    printCentered("-------------------------------------------", 100);
    for (const auto &s : students) {
        cout << setw(25) << s.id << "\t"
             << setw(25) << s.name << "\t"
             << setw(25) << s.age << "\t"
             << setw(25) << s.course << endl;
    }
}

// Search by ID
void searchStudentByID() {
    int id;
    printCentered("Enter Student ID to search: ", 100);
    cin >> id;

    for (const auto &s : students) {
        if (s.id == id) {
            cout << "ID: " << s.id << ", Name: " << s.name
                 << ", Age: " << s.age << ", Course: " << s.course << endl;
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Search by name
void searchStudentByName() {
    string name;
    printCentered("Enter Student Name to search: ", 50);
    cin.ignore();
    getline(cin, name);

    for (const auto &s : students) {
        if (s.name == name) {
            cout << "ID: " << s.id << ", Name: " << s.name
                 << ", Age: " << s.age << ", Course: " << s.course << endl;
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Delete student
void deleteStudent() {
    int id;
    printCentered("Enter Student ID to delete: ", 100);
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            char confirmation;
            printCentered("Are you sure you want to delete this student record? (y/n): ", 100);
            cin >> confirmation;
            if (confirmation == 'y' || confirmation == 'Y') {
                students.erase(it);
                printCentered("Student record deleted successfully.", 100);
            } else {
                printCentered("Deletion cancelled.", 100);
            }
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Update student
void updateStudent() {
    int id;
    printCentered("Enter Student ID to update: ", 100);
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cin.ignore();
            printCentered("Enter new Student Name: ", 100);
            getline(cin, s.name);

            printCentered("Enter new Student Age: ", 100);
            cin >> s.age;
            while (cin.fail() || s.age <= 0 || s.age > 100) {
                cin.clear();
                cin.ignore(1000, '\n');
                printCentered("Invalid age. Please enter a valid age (1-100): ", 100);
                cin >> s.age;
            }

            cin.ignore();
            printCentered("Enter new Student Course: ", 100);
            getline(cin, s.course);

            printCentered("Student record updated successfully.", 100);
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Sort students by name
void sortStudentsByName() {
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.name < b.name;
    });
    printCentered("Students sorted by name.", 100);
}

// Display statistics
void displayStatistics() {
    if (students.empty()) {
        printCentered("No student records to calculate statistics.", 100);
        return;
    }

    int totalAge = 0;
    for (const auto &s : students) {
        totalAge += s.age;
    }

    cout << "Total number of students: " << students.size() << endl;
    cout << "Average age of students: " << static_cast<float>(totalAge) / students.size() << endl;
}
bool loginSystem() {
    const string USERNAME = "Admin";
    const string PASSWORD = "pass123";

    string enteredUsername, enteredPassword;
    int attempts = 0;

    while (attempts < 3) {
        printCentered("LOGIN TO STUDENT MANAGEMENT SYSTEM", 100);
        cout << "Enter Username: ";
        cin >> enteredUsername;
        cout << "Enter Password: ";
        cin >> enteredPassword;

        if (enteredUsername == USERNAME && enteredPassword == PASSWORD) {
            printCentered("Login successful. Welcome, Admin!", 100);
            return true;
        } else {
            printCentered("Incorrect username or password. Try again.", 100);
            attempts++;
        }
    }

    printCentered("Too many failed attempts. Access denied.", 100);
    return false;
}


// Menu
int main() {
    if (!loginSystem()) {
        return 0; // Exit if login fails
    }
    int choice;
    do {
        printCentered("-------- Student Management System Menu Of JECRC --------", 100);
        printCentered("1. Insert Student record", 100);
        printCentered("2. View All Student records", 100);
        printCentered("3. Search Student record by ID", 100);
        printCentered("4. Search Student record by Name", 100);
        printCentered("5. Delete Student record", 100);
        printCentered("6. Update Student record", 100);
        printCentered("7. Sort Students by Name", 100);
        printCentered("8. Display Statistics", 100);
        printCentered("9. Exit", 100);
        printCentered("Enter your choice: ", 100);
        cin >> choice;

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: searchStudentByID(); break;
            case 4: searchStudentByName(); break;
            case 5: deleteStudent(); break;
            case 6: updateStudent(); break;
            case 7: sortStudentsByName(); break;
            case 8: displayStatistics(); break;
            case 9: printCentered("Exiting the program.", 50); break;
            default: printCentered("Invalid choice. Please try again.", 50);
        }
    } while (choice != 9);

    return 0;
}
