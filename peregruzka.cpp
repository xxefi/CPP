#include <iostream>
#include <vector>
using namespace std;

/*1. Реализовать перегрузку операторов для дз с дробями. 
2. Реализовать класс Student, Clasrrom.
В классе Student и Classroom сделать перегрузку операторов >, <, ==, !=,  <<, >>

Если выводить Classroom, то тогда нужно выводить всех 
студентов. 

*/
class Student {
private:
    string name;
    int age;

public:
    Student(const string& studentName, int studentAge) : name(studentName), age(studentAge) {}

    bool operator>(const Student& other) const {
        return age > other.age;
    }

    bool operator<(const Student& other) const {
        return age < other.age;
    }

    bool operator==(const Student& other) const {
        return name == other.name && age == other.age;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Имя: " << student.name << ", Возраст: " << student.age;
        return os;
    }
};

class Classroom {
private:
    vector<Student> students;

public:
    void AddStudent(const Student& student) {
        students.push_back(student);
    }

    bool operator>(const Classroom& other) const {
        return students.size() > other.students.size();
    }

    bool operator<(const Classroom& other) const {
        return students.size() < other.students.size();
    }

    bool operator==(const Classroom& other) const {
        return students == other.students;
    }

    bool operator!=(const Classroom& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Classroom& classroom) {
        for (const Student& student : classroom.students) {
            os << student << endl;
        }
        return os;
    }
};

int main() {
    Student s1("Халил", 16);
    Student s2("Иса", 16);
    Student s3("Бахтияр", 17);

    Classroom c1;
    c1.AddStudent(s1);
    c1.AddStudent(s2);

    Classroom c2;
    c2.AddStudent(s1);
    c2.AddStudent(s2);
    c2.AddStudent(s3);

    cout << "Студент 1:" << endl;
    cout << c1 << endl;

    cout << "Студент 2:" << endl;
    cout << c2 << endl;

    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;
}
