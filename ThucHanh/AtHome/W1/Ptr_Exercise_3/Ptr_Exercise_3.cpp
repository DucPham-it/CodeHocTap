// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠈⠉⠉⠉⠉⠒⠀⠀⠤⣀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠁⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠑⡄⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠰⠿⠿⠿⠣⣶⣿⡏⣶⣿⣿⠷⠶⠆⠀⠀⠘⠀
// ⠀⠀⠀⠀⠀⠀⠠⠴⡅⠀⠀⠠⢶⣿⣿⣷⡄⣀⡀⡀⠀⠀⠀⠀⠀⡇⠀
// ⠀⣰⡶⣦⠀⠀⠀⡰⠀⠀⠸⠟⢸⣿⣿⣷⡆⠢⣉⢀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⢹⣧⣿⣇⠀⠀⡇⠀⢠⣷⣲⣺⣿⣿⣇⠤⣤⣿⣿⠀⢸⠀⣤⣶⠦⠀⠀
// ⠀⠀⠙⢿⣿⣦⡀⢇⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⡜⣾⣿⡃⠇⢀⣤⡀⠀
// ⠀⠀⠀⠀⠙⢿⣿⣮⡆⠀⠙⠿⣿⣿⣾⣿⡿⡿⠋⢀⠞⢀⣿⣿⣿⣿⣿⡟⠁
// ⠀⠀⠀⠀⠀⠀⠛⢿⠇⣶⣤⣄⢀⣰⣷⣶⣿⠁⡰⢃⣴⣿⡿⢋⠏⠉⠁⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠠⢾⣿⣿⣿⣞⠿⣿⣿⢿⢸⣷⣌⠛⠋⠀⠘⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠙⣿⣿⣿⣶⣶⣿⣯⣿⣿⣿⣆⠀⠇
// TRY TO FIX BUG TODAY, BECOME A NICE CODER TOMORROW !!!

// 24120041 - Pham Vo Duc

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool readMatrix(const char *filename, int **&matrix, int &rows, int &cols)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }

    rows = 0;
    cols = 0;
    char line[1024];
    int **tempMatrix = nullptr;
    int tempRows = 0;
    int tempCols = 0;

    while (file.getline(line, 1024))
    {
        int *row = new int[1024]; 
        int colCount = 0;
        char *token = strtok(line, " ");
        while (token != nullptr)
        {
            row[colCount++] = atoi(token);
            token = strtok(nullptr, " ");
        }
        if (colCount > 0)
        {
            int **newTempMatrix = new int*[tempRows + 1];
            for (int i = 0; i < tempRows; ++i)
            {
                newTempMatrix[i] = tempMatrix[i];
            }
            newTempMatrix[tempRows] = new int[colCount];
            for (int j = 0; j < colCount; ++j)
            {
                newTempMatrix[tempRows][j] = row[j];
            }
            delete[] tempMatrix;
            tempMatrix = newTempMatrix;
            ++tempRows;
            if (colCount > tempCols)
            {
                tempCols = colCount;
            }
        }
        delete[] row;
    }

    rows = tempRows;
    cols = tempCols;

    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = tempMatrix[i][j];
        }
    }

    file.close();
    return true;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
