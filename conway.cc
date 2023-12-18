#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

std::vector<std::vector<bool>> readGameOfLifeFile(const std::string& filename);

bool updateCellState(const std::vector<std::vector<bool>>& currentField, size_t row, size_t col);

std::vector<std::vector<bool>> updateGameField(const std::vector<std::vector<bool>>& currentField);

// Funktion zur Ausgabe des Spielfelds auf der Konsole
void printGameField(const std::vector<std::vector<bool>>& gameField);

std::string confile = "game_of_life.txt";
std::vector<std::vector<bool>> gameField = readGameOfLifeFile(confile);

int main() {
    std::string confile = "game_of_life.txt";
    std::vector<std::vector<bool>> gameField = readGameOfLifeFile(confile);

    if (gameField.empty()) {
        std::cerr << "Error: Unable to read the game field from file.!" << std::endl;
        return 1;
    }

    while (true) {
        std::cout << "\x1B[2J\x1B[H";

        printGameField(gameField);

        gameField = updateGameField(gameField);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}

std::vector<std::vector<bool>> readGameOfLifeFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<bool>> gameLife;

    if (!file.is_open()) {
        std::cerr << "Error: COuld not open file " << confile << std::endl;
        return gameField;
    }

    std::string line;
    size_t rows = 0;
    size_t cols = 0;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        } 

        if (cols == 0) {
            cols = line.size();
        }
        else if (line.size() != cols) {
            std::cerr << "Error: Inconsistent number of columns in the file." << std::endl;
            return std::vector<std::vector<bool>>();
        }

        std::vector<bool> row;
        for (char c : line) {
            if (c == '0') {
                row.push_back(true);
            }
            else if (c == ' ') {
                row.push_back(false);
            }
            else {
                std::cerr << "Error: Invalid character in the file. " << std::endl;
                return std::vector<std::vector<bool>>();
            }
        }

        gameField.push_back(row);
        rows++;
    }

    if (rows == 0) {
        std::cerr << "Error: Empty file. " << std::endl;
        return std::vector<std::vector<bool>>();
    }

    file.close();
    return gameField;
}

bool updateCellState(const std::vector<std::vector<bool>>& currentField, size_t row, size_t col) {
    size_t numRows = currentField.size();
    size_t numCols = currentField[0].size();

    // Die lebendigen Nachbarn zählen
    int liveNeighbors = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue; // Überspringe die aktuelle Zelle
            }

            // Randbedingungen
            size_t newRow = (row + i + numRows) % numRows;
            size_t newCol = (col + j + numCols) % numCols;

            liveNeighbors += currentField[newRow][newCol] ? 1 : 0;
        }
    }

    if (currentField[row][col]) {
        return liveNeighbors == 2 || liveNeighbors == 3;
    }
    else {
        return liveNeighbors == 3;
    }
}

std::vector<std::vector<bool>> updateGameField(const std::vector<std::vector<bool>>& currentField) {
    std::vector<std::vector<bool>> newField(currentField.size(), std::vector<bool>(currentField[0].size(), false));

    for (size_t i = 0; i < currentField.size(); ++i) {
        for (size_t j = 0; j < currentField[0].size(); ++j) {
            newField[i][j] = updateCellState(currentField, i, j);
        }
    }

    return newField;
}

void printGameField(const std::vector<std::vector<bool>>& gameField) {
    for (const auto& row : gameField) {
        for (bool cell : row) {
            std::cout << (cell ? '0' : ' ') << ' ';
        }
        std::cout << std::endl;
    }
}
