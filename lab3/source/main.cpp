#include"menu.h"

int main() {
	system("chcp 1251");
	Learner** learners = nullptr;
	int count = 0;

	char choice;

	do {
		showMenu();

		std::cin >> choice;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice)
		{
		case '1':
			createTestData(learners, count);
			break;
		case '2':
			addNewLearner(learners, count);
			break;
		case '3':
			viewLearners(learners, count);
			break;
		case '4':
			viewSeparately(learners, count);
			break;
		case '5':
			learners = deleteData(learners, count);
			break;
		case '0':
			std::cout << "Exit" << std::endl;
			break;
		default:
			std::cout << "Error" << std::endl;
			break;
		}

	} while (choice != '0');

	learners = deleteData(learners, count);

	return 0;
}
