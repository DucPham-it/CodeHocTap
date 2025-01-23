
#include <iostream>
using namespace std;

struct Point{
    int x,y;
};

void findBoundaryDifferences(char** matrix, int rows, int cols, Point* a) {
    int k=0;  
    for (int i=1; i < rows-1; i++){
        for (int j = 0; j < cols; j+=cols-1){          
            if (matrix[i][j] != matrix[0][0]){
                a[k].x=i;
                a[k].y=j;
                k++;
                if (k == 2) return;
            }
           
        }
    }
    for (int i=1; i < cols-1; i++){
        for (int j = 0; j < rows; j+=rows-1){
            // if (k == 2) break;
            if (matrix[j][i] != matrix[0][0]){
                a[k].x=j;
                a[k].y=i;
                k++;
                if (k ==2) return;
            }
        }
    }
}

int findStep(char** matrix, int rows, int cols, Point* a) {
    int count = 0;
    Point before = a[0];
    Point cur = a[0];
    Point end = a[1];
    
    // Directions: down, right, up, left
    Point step[4] = {
        {1, 0},  // Down
        {0, 1},  // Right
        {-1, 0}, // Up
        {0, -1}  // Left
    };

    // While the current point is not the end point
    while (cur.x != end.x || cur.y != end.y) {
        for (int i = 0; i < 4; i++) {
            int newX = cur.x + step[i].x;
            int newY = cur.y + step[i].y;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                if (newX == end.x && newY == end.y) {
                    return count;
                }
                if (matrix[newX][newY] == '*' && (newX != before.x || newY != before.y)) {
                    before = cur;
                    cur.x = newX;
                    cur.y = newY;
                    count++;
                    break;  
                }
            }
        }
    }
    return count;
}

int main() {
    int rows, cols;
    Point DifferencesPoint[2];
    cout << "Input Rows: ";
    cin >> rows;
    cout << "Input Cols: " ;
    cin >> cols;
    cout << "Input Matrix: " << endl;
    cin.ignore();

    char** matrix=  new char*[rows];
    for (int i=0; i< rows; i++){
        matrix[i] = new char[cols+1];
        cin.getline(matrix[i],cols+1,'\n');
    }

    for (int i=0; i < rows; i++){
        for (int j=0; j< cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    findBoundaryDifferences(matrix, rows, cols, DifferencesPoint); 
    for (int i=0; i<2; i++){
        cout << "(" << DifferencesPoint[i].x << ", " << DifferencesPoint[i].y <<")"<< endl;
    }
    cout << findStep(matrix, rows, cols, DifferencesPoint) << endl;

    for (int i=0; i< rows; i++){
        delete[] matrix[i];

    }

    delete[] matrix;
    return 0;
}
