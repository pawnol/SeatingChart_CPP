/*
Seating Chart
Pawelski
5/17/2022
This program allows the user to display and modify a seating chart for a 4x5
grid of desks.
*/

#include <iostream>
#include <iomanip>
#include <vector>

/// <summary>
/// Creates a seating chart with the given number of rows and columns.
/// </summary>
/// <param name="rows">Rows for the seating chart.</param>
/// <param name="columns">Columns of the seating chart.</param>
/// <returns>A 2D vectors consisting of "-".</returns>
std::vector<std::vector<std::string>> PopulateSeatingChart(int rows, int columns)
{
    std::vector<std::vector<std::string>> seating_chart;
    for (int i = 0; i < columns; i++)
    {
        std::vector<std::string> temp;
        for (int j = 0; j < rows; j++)
        {
            temp.push_back("_");
        }
        seating_chart.push_back(temp);
    }
    return seating_chart;
}

/// <summary>
/// Displays the seating chart.
/// </summary>
/// <param name="seating_chart">Seating chart to display.</param>
void DisplaySeatingChart(std::vector<std::vector<std::string>> seating_chart)
{
    std::cout << "Front" << std::endl;
    for (int i = 0; i < seating_chart.size(); i++)
    {
        for (int j = 0; j < seating_chart[i].size(); j++)
        {
            std::cout << std::setw(10) << seating_chart[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "Back" << std::endl;
}

/// <summary>
/// Updates the seating chart with a new student name.
/// </summary>
/// <param name="seating_chart">Seating chart.</param>
/// <returns>Updated seating chart.</returns>
std::vector<std::vector<std::string>> UpdateSeatingChart(std::vector<std::vector<std::string>> seating_chart)
{
    int row, column;
    std::string name;

    std::cout << "What row and column do you need to change? >> ";
    std::cin >> row;
    std::cin >> column;
    std::cout << "What is the student's name? >> ";
    std::cin >> name;

    seating_chart[row - 1][column - 1] = name;
    return seating_chart;
}

int main()
{
    const int ROWS = 4, COLUMNS = 5;
    std::vector<std::vector<std::string>> seating_chart;
    seating_chart = PopulateSeatingChart(ROWS, COLUMNS);

    while (true)
    {
        int user_choice;
        std::cout << "Please select one of the following options.\n";
        std::cout << "1. Display seating chart.\n";
        std::cout << "2. Change seat.\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3) >> ";
        std::cin >> user_choice;
        while (user_choice < 1 || 3 < user_choice)
        {
            std::cout << "Invalid choice.\n";
            std::cout << "Please select one of the following options.\n";
            std::cout << "1. Display seating chart.\n";
            std::cout << "2. Change seat.\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter your choice (1-3) >> ";
            std::cin >> user_choice;
        }
        std::cout << std::endl;

        if (user_choice == 1)
        {
            DisplaySeatingChart(seating_chart);
        }
        else if (user_choice == 2)
        {
            seating_chart = UpdateSeatingChart(seating_chart);
        }
        else if (user_choice == 3)
        {
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}
