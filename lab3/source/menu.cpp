#include "menu.h"

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
  for (const auto* learner : learners) {
    if (learner->getType() == "Student") {
      learner->display();
      cout << endl;
      hasStudent = true;
    }
  }

  if (!hasStudent) {
    cout << "No students" << endl;
  }

  cout << "Schoolboys:" << endl;

  bool hasSchoolboy = false;

  for (const auto* learner : learners) {
    if (learner->getType() == "Schoolboy") {
      learner->display();
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
  for (const auto* learner : learners) {
    cout << counter << ". ";
    learner->display();
    counter++;
  }
}

Learner** addLearner(Learner** learners, int& count, Learner* newLearner) {
  auto** newArray = new Learner*[count + 1];

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

  learners = addLearner(learners, count,
                        new Student("Jack", 19, "BSUIR", "Physics", 2));
  learners = addLearner(learners, count,
                        new Schoolboy("Sara", 16, "Pavlovichi school", 10));
  learners = addLearner(learners, count,
                        new Student("Sam", 20, "BRU", "Mathematics", 3));
  learners = addLearner(learners, count,
                        new Student("Rihanna", 18, "BSU", "Faculty of law", 1));
  learners = addLearner(learners, count,
                        new Schoolboy("Alex", 12, "Myshkovichi school", 5));
  learners = addLearner(learners, count,
                        new Schoolboy("Maria", 14, "Gymnasium #2", 7));
  learners =
      addLearner(learners, count, new Schoolboy("Oleg", 10, "Gymnasium #1", 4));
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
  if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input" << endl;
    return;
  }
  cin.ignore();

  if (type != static_cast<int>(LearnerType::Student) &&
      type != static_cast<int>(LearnerType::Schoolboy)) {
    cout << "Invalid input" << endl;
    return;
  }

  cout << "Enter the name:";
  getline(cin, name);
  if (name.empty()) {
    cout << "Name can't be empty" << endl;
    return;
  }

  cout << "Enter the age:";
  cin >> age;
  if (cin.fail() || !Learner::isValidAge(age)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid age! Must be between " << Learner::getMinAge() << " and "
         << Learner::getMaxAge() << endl;
    return;
  }
  cin.ignore();

  Learner* newLearner = nullptr;

  if (type == static_cast<int>(LearnerType::Student)) {
    cout << "Enter the university:";
    getline(cin, university);

    if (university.empty()) {
      cout << "University cannot be empty!" << endl;
      return;
    }

    cout << "Enter the faculty:";
    getline(cin, faculty);

    if (faculty.empty()) {
      cout << "Faculty cannot be empty!" << endl;
      return;
    }

    cout << "Enter the course:";
    cin >> course;
    if (cin.fail() || !Student::isValidCourse(course)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid course! Must be between " << Student::getMinCourse()
           << " and " << Student::getMaxCourse() << endl;
      return;
    }

    cin.ignore();

    newLearner = new Student(name, age, university, faculty, course);
  } else {
    cout << "Enter the school name:";
    getline(cin, schoolName);

    if (schoolName.empty()) {
      cout << "School name cannot be empty!" << endl;
      return;
    }

    cout << "Enter the grade:";
    cin >> grade;
    if (cin.fail() || !Schoolboy::isValidGrade(grade)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid grade! Must be between " << Schoolboy::getMinGrade()
           << " and " << Schoolboy::getMaxGrade() << endl;
      return;
    }
    cin.ignore();

    newLearner = new Schoolboy(name, age, schoolName, grade);
  }
  learners = addLearner(learners, count, newLearner);
  cout << "New learner is created succesful" << endl;
}
