#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>


std::string verstecken (std::string word) {
	int string_size = word.length();

	for (int i = 0; i < string_size; i++) {
		word[i] = '_';
	}

	return word;
}

bool aufdecken (std::string& current_state, std::string solution, char letter) {
	int n = solution.length();
	bool result;

	letter = std::tolower(letter);

	for (int i = 0; i < n; i++) {
		char c = solution[i];
		c = std::tolower(c);

		if (c == letter) {
			current_state[i] = solution[i];
			result = true;
			continue;
		}
	}


	if (result == true)
		return true;
	else 
		return false;
}

bool istFertig (std::string& current_state, std::string solution) {
	if (current_state == solution) {
		return true;
	}
	else {
		return false;
	}
}


void gameLoop (std::string solution) {
	char letters;
	int leben = 10;

	std::string curr = verstecken(solution);

	while (true) {
		std::cout << curr << std::endl;
		std::cin >> letters;
		if (aufdecken(curr, solution, letters) == true) {
			if (istFertig(curr, solution) == true) {
				std::cout << curr << std::endl;
				std::cout << "You Won!" << std::endl;
				break;
			}
			else {
				continue;
			}
		}
		else {
			leben--;
			std::cout << "Falscher Buchstabe, du hast ein Leben verloren!" << "	" << "Anzahl der Leben: " << leben << std::endl;
			if (leben == 0) {
				std::cout << "Du hast kein Leben mehr!" << std::endl;
				break;
			}
		}

	}
}

std::vector<std::string> readFiles (std::vector<std::string> wordlist) {
	std::ifstream file;
	file.open("wortliste.txt");
	std::string word;
	
	while (file >> word) {
		wordlist.push_back(word);
	}

	file.close();

	return wordlist;
}


int main() {
	std::vector<std::string> words {"Auto", "Hallenbad", "Steuerung", "Computer", "Informatik", "Yasemin"};

	std::vector<std::string> hello = readFiles(words);

	std::srand(std::time(nullptr));

	int n = hello.size();
	int index = std::rand() % n;

	gameLoop(hello[index]);

	return 0;
}

