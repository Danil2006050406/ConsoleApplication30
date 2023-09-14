#include <iostream>
#include <vector>
#include <algorithm> 
#include <Windows.h>

using namespace std;

class Student {
public:
    Student(const string& firstName, const string& lastName, double averageGrade)
        : firstName(firstName), lastName(lastName), averageGrade(averageGrade) {}

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    double getAverageGrade() const {
        return averageGrade;
    }

private:
    string firstName;
    string lastName;
    double averageGrade;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Student> students;

    
    students.push_back(Student("Іван", "Петров", 85.5));
    students.push_back(Student("Марія", "Іванова", 92.0));
    students.push_back(Student("Петро", "Сидоров", 78.7));
    students.push_back(Student("Анна", "Коваль", 88.9));

    
    auto maxStudent = max_element(students.begin(), students.end(),
        [](const Student& student1, const Student& student2) {
            return student1.getAverageGrade() < student2.getAverageGrade();
        }
    );

    if (maxStudent != students.end()) {
        cout << "Студент з найвищим балом: " << maxStudent->getFirstName() << " " << maxStudent->getLastName() << endl;
    }
    else {
        cout << "Відсутні студенти у списку." << endl;
    }

    return 0;
}
