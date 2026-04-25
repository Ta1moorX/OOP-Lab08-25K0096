#include <iostream>
using namespace std;

class Student {
    string name;
    float grade[3];
public:
    Student(string n, float g1, float g2, float g3)
        : name(n) {
        grade[0]=g1; grade[1]=g2; grade[2]=g3;
    }

    void displayGrades() {
        cout << "Student: " << name << endl;
        for (int i = 0; i < 3; i++)
            cout << "  Grade " << i+1 << ": " << grade[i] << endl;
    }

    friend class Teacher;
    friend float calculateAverageGrade(Student& s);
};

float calculateAverageGrade(Student& s) {
    return (s.grade[0] + s.grade[1] + s.grade[2]) / 3;
}

class Teacher {
public:
    void updateGrade(Student& s, int index, float newGrade) {
        if (index >= 0 && index < 3) {
            s.grade[index] = newGrade;
            cout << "Teacher updated Grade " << index+1
                 << " to: " << newGrade << endl;
        }
    }
};

int main() {
    Student st("Ali", 70, 65, 80);
    Teacher teacher;

    cout << "--- Before Update ---" << endl;
    st.displayGrades();
    cout << "Average: " << calculateAverageGrade(st) << endl;

    cout << "\n--- Teacher Updates Grade 2 ---" << endl;
    teacher.updateGrade(st, 1, 85);

    cout << "\n--- After Update ---" << endl;
    st.displayGrades();
    cout << "New Average: " << calculateAverageGrade(st) << endl;

    return 0;
}