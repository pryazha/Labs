#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

bool isReflexive(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        if (matrix[i][i] != 1)
            return false;
    return true;
}

bool isAntireflexive(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        if (matrix[i][i] == 1)
            return false;
    return true;
}

bool isSymmetric(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++)
        for (int j = i + 1; j < matrix[i].size(); j++)
            if (matrix[i][j] != matrix[j][i])
                return false;
    return true;
}

bool isAntisymmetric(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            if (matrix[i][j] == 1 && matrix[j][i] == 1 && i != j)
                return false;
    return true;
}

bool isAsymmetric(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            if (matrix[i][j] == 1 && matrix[j][i] == 1)
                return false;
    return true;
}

bool isTransitive(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1)
                for (int k = 0; k < n; k++)
                    if (matrix[j][k] == 1 && matrix[i][k] == 0)
                        return false;

    return true;
}

int main() {
    std::vector<std::vector<int>> matrix(6, std::vector<int>(6));

    std::string file;
    int num;
    std::cout << "Enter number of file: ";
    std::cin >> num; 
    while (num <= 0 && num >= 9) {
        std::cout << "Invalid number!\n";
        std::cin >> num;
    }
    file = "m" + std::to_string(num) + ".txt";
    std::ifstream inputFile(file);
    if (!inputFile.is_open()) {
        std::cout << "Unable to open file";
        return 1;
    }
    std::string line;
    int i = 0;
    bool flag = true;
    while (std::getline(inputFile, line) && flag) {
        int j = 0;
        std::stringstream ss(line);
        std::string temp;
        while (ss >> temp) {
            try {
                int number = std::stoi(temp);
                flag = number == 1 || number == 0;
                if (!flag) {
                    std::cout << "Invalid input\n";
                    break;
                }
                matrix[i][j] = number;
                j++;
            } catch (std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << "\n";
            } catch (std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << "\n";
            }
        }
        i++;
    }
    inputFile.close();

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Relation properties:\n";
    if (isReflexive(matrix))
        std::cout << "Reflexive\n";
    if (isAntireflexive(matrix))
        std::cout << "Antireflexive\n";
    if (isSymmetric(matrix))
        std::cout << "Symmetrical\n";
    if (isAntisymmetric(matrix))
        std::cout << "Antisymmetrical\n";
    if (isAsymmetric(matrix))
        std::cout << "Asymmetrical\n";
    if (isTransitive(matrix))
        std::cout << "Transitive\n";

    system("pause");
    return 0;
}
