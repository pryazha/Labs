#ifndef SOLUTION_H
#define SOLUTION_H

#include "road.h"

#include <cmath>
#include <algorithm>

class Solution {
public:
    Solution(std::vector<City*> cities, std::vector<Road*> roads, QString starting_city);

    void return_solution();
    QString get_answer();

signals:
    void solved(std::vector<int>);

private:
    std::vector<int> solve(std::vector<std::vector<double>>, int);
    QString double_to_string(double);
    void print_matrix(std::vector<std::vector<double>>, int);

    std::vector<QString> city_names;
    std::vector<std::vector<double>> matrix;
    std::vector<int> route;
    QString solution_text;
    QString answer;
};

#endif // SOLUTION_H
