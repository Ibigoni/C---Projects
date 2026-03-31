#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


class Student {
private:
    string name;
    vector<int> scores;

public:
    Student(const string & studentName) : name(studentName) {}

    void addScore(int score) {
        scores.push_back(score);
    }

    double average() const {
        if (scores.empty()) return 0.0;
        int sum = 0;
        for (int s : scores) sum += s;
        return static_cast<double>(sum) / scores.size();
    }

    void printInfo() const {
        cout << "Student: " << name << " | Scores: ";
        for (int s : scores) cout << s << " ";
        cout << "| Avg: " << fixed << setprecision(1) << average() << endl;
    }

    string getName() const {
        return name;
    }
};

// === Find Top Student ===
int findTopStudentIndex(const vector<Student>& students) {
    int topIndex = 0;
    double topAvg = students[0].average();
    for (int i = 1; i < students.size(); ++i) {
        if (students[i].average() > topAvg) {
            topAvg = students[i].average();
            topIndex = i;
        }
    }
    return topIndex;
}


int main() {
    int numStudents;
    cout << "=== Student Grade Analyzer ===" << endl;

    do {
        cout << "How many students? ";
        cin >> numStudents;
        if (numStudents < 1 || numStudents > 50)
            cout << "Invalid number of students. Must be between 1 and 50." << endl;
    } while (numStudents < 1 || numStudents > 50);

    vector<Student> students;

    for (int i = 0; i < numStudents; ++i) {
        string name;
        cout << "Enter name for student #" << i + 1 << ": ";
        cin >> ws;
        getline(cin, name);
        Student s(name);

        int numScores;
        do {
            cout << "How many scores for " << name << "? ";
            cin >> numScores;
            if (numScores < 1 || numScores > 10)
                cout << "Invalid number of scores. Must be between 1 and 10." << endl;
        } while (numScores < 1 || numScores > 10);

        for (int j = 0; j < numScores; ++j) {
            int score;
            do {
                cout << "Enter score #" << j + 1 << ": ";
                cin >> score;
                if (score < 0 || score > 100)
                    cout << "Invalid score. Must be between 0 and 100." << endl;
            } while (score < 0 || score > 100);
            s.addScore(score);
        }

        students.push_back(s);
    }

    cout << endl;
    for (const Student& s : students)
        s.printInfo();

    int top = findTopStudentIndex(students);
    cout << "\nTop Student: " << students[top].getName()
         << " with average " << fixed << setprecision(1)
         << students[top].average() << endl;

    return 0;
}
