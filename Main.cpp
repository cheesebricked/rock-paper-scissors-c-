#include <iostream>
#include <unordered_map>

void runGame();

void endMenu() {
	std::cout << "a -> play again" << std::endl;
	std::cout << "e -> exit\n" << std::endl;

	std::string input;
	std::cin >> input;
	std::cout << "\n" << std::endl;

	if (input == "a") {
		runGame();
	}
	else if (input == "e") {
	}
	else {
		std::cout << "invalid input\n" << std::endl;
		endMenu();
	}
}


int main() {
	runGame();
}