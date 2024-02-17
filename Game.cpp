#include <iostream>
#include <random>
#include <unordered_map>

void endMenu();

int playCPU() {
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int> random(0, 2);

	return random(generator);
}

void runGame() {
	std::unordered_map<int, std::string> textChoices{
	{0, "rock"}, {1, "paper"}, {2, "scissors"}
	};

	std::cout << "r -> rock" << std::endl;
	std::cout << "p -> paper" << std::endl;
	std::cout << "s -> scissors\n" << std::endl;

	std::string input;
	std::cin >> input;
	std::cout << "\n" << std::endl;

	std::unordered_map<std::string, int> inputToInt {
		{"r", 0}, { "p", 1 }, {"s", 2}
	};
	
	int CPU = playCPU();

	if (input == "r" || input == "p" || input == "s") {
		if (((inputToInt[input] + 1) % 3) == CPU) {
			std::cout << "you: " << textChoices[inputToInt[input]] << std::endl;
			std::cout << "cpu: " << textChoices[CPU] << std::endl;
			std::cout << "you loose!\n" << std::endl;
		}
		else if (((inputToInt[input] + 2) % 3) == CPU) {
			std::cout << "you: " << textChoices[inputToInt[input]] << std::endl;
			std::cout << "cpu: " << textChoices[CPU] << std::endl;
			std::cout << "you win!\n" << std::endl;
		}
		else {
			std::cout << "you: " << textChoices[inputToInt[input]] << std::endl;
			std::cout << "cpu: " << textChoices[CPU] << std::endl;
			std::cout << "its a tie!\n" << std::endl;
		}
		endMenu();
	}
	else {
		std::cout << "invalid input\n" << std::endl;
		runGame();
	}
}