#include"menu.h"

using namespace std;

void showMenu() {
	cout << "----------MENU----------" << endl;
    cout << "1. Create test data" << endl;
    cout << "2. Add learner" << endl;
    cout << "3. View all learners" << endl;
    cout << "4. View students and scholars separately" << endl;
    cout << "5. Delete data" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
}

void deleteData(Learner**& learners, int& count) {
    if (learners == nullptr) {
        return;
    }

    for (int i = 0; i < count; i++) {
        delete learners[i];
    }

    delete[] learners;
    learners = nullptr;
    count = 0;
}

void viewSeparately(span<Learner*> learners) {
    if (learners.empty()) {
        cout << "No learners" << endl;
        return;
    }

    cout << "Students:" << endl;

    bool hasStudent = false;
    for (auto* learners:learners) {
        if (learners->getType() == "Student") {
            learners->display();
            cout << endl;
            hasStudent = true;
        }
    }

    if (!hasStudent) {
        cout << "No students" << endl;
    }

    cout << "Schoolboys:" << endl;

    bool hasSchoolboy = false;

    for (auto* learners:learners) {
        if (learners->getType() == "Schoolboy") {
            learners->display();
            cout << endl;
            hasSchoolboy = true;
        }
    }

    if (!hasSchoolboy) {
        cout << "No schoolboy" << endl;
    }

}

void viewLearners(span<Learner*> learners) {
    if (learners.empty()) {
        cout << "No learners" << endl;
        return;
    }

    cout << "Learners(" << learners.size() << "):" << endl;
    int counter = 1;
    for (auto* learner : learners) {
        cout << counter << ". ";
        learner->display();
        counter++;
    }
}

Learner** addLearner(Learner** learners, int& count,Learner* newLearner) {
    auto** newArray = new Learner * [count + 1];

    for (int i = 0; i < count; i++) {
        newArray[i] = learners[i];
    }

    newArray[count] = newLearner;
    count++;

    delete[] learners;

    return newArray;
}

void createTestData(Learner**& learners, int& count) {
    deleteData(learners, count);


    learners = addLearner(learners, count, new Student("Jack", 19, "BSUIR", "Physics", 2));
    learners = addLearner(learners, count, new Schoolboy("Sara", 16, "Pavlovichi school", 10));
    learners = addLearner(learners, count, new Student("Sam", 20, "BRU", "Mathematics", 3));
    learners = addLearner(learners, count, new Student("Rihanna", 18, "BSU", "Faculty of law", 1));
    learners = addLearner(learners, count, new Schoolboy("Alex", 12, "Myshkovichi school", 5));
    learners = addLearner(learners, count, new Schoolboy("Maria", 14, "Gymnasium #2", 7));
    learners = addLearner(learners, count, new Schoolboy("Oleg", 10, "Gymnasium #1", 4));
}

void addNewLearner(Learner**& learners, int& count) {
    int type;
    string name;
    int age;
    string university;
    string faculty;
    int course;
    int grade;
    string schoolName;

    cout << "1. Student" << endl;
    cout << "2. Schoolboy" << endl;
    cout << "Your choice:";
    cin >> type;
    cin.ignore();

    cout << "Enter the name:";
    getline(cin, name);


    cout << "Enter the age:";
    cin >> age;
    cin.ignore();

    Learner* newLearner = nullptr;

    if (type == 1) {
        cout << "Enter the university:";
        getline(cin, university);

        cout << "Enter the faculty:";
        getline(cin, faculty);

        cout << "Enter the course:";
        cin >> course;
        cin.ignore();

        newLearner = new Student(name, age, university, faculty, course);
    }
    else {
        cout << "Enter the school name:";
        getline(cin, schoolName);

        cout << "Enter the grade:";
        cin >> grade;
        cin.ignore();

        newLearner = new Schoolboy(name, age, schoolName, grade);
    }
    learners = addLearner(learners, count, newLearner);
    cout << "New learner is created succesful" << endl;
}