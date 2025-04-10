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


//24120041 - Pham Vo Duc

#include <iostream>

struct Point
{
    double x;
    double y;
};

typedef struct Point Point;

std::ostream& operator<< (std::ostream& output, const Point& point){
    output << "(" << point.x << " , " << point.y << ")";
    return output;
}

std::istream& operator>> (std::istream& input, Point& point){
    input >> point.x >> point.y;
    return input;
}

void quickSort(Point *a, int n);
void quickSort(Point *a, int left, int right);
void findMaximaPoints(Point *a, int n);

int main(){
    int n;
    std:: cout << "Enter number of points :";
    std:: cin >> n;
    Point *a = new Point[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> *(a+i);
    }

    findMaximaPoints(a, n);

    delete[] a;
    return 0;
}

void quickSort(Point *a, int n){
    quickSort(a, 0, n-1);
}

void quickSort(Point *a, int left, int right){
    int mid = (left + right) / 2;
    Point pivot = a[mid];
    int i = left;
    int j = right;

    do{
        while (a[i].x < pivot.x)
        {
            i++;
        }
        while (a[j].x > pivot.x)
        {
            j--;
        }
        if (i <= j){
            std::swap(a[i], a[j]);
            i++;
            j--;
        }           
    }while (i < j);

    if (j > left) quickSort(a, left, j); 
    if (i < right) quickSort(a, i, right);    
}

void findMaximaPoints(Point *a, int n){
    //Sort array of point following x
    quickSort(a, n);

    //Make array to save Maxima Points
    Point *temp = new Point[n];

    //Find maxima points following y
    double maxY = a[n-1].y;
    int j =0;
    for (int i = n-1 ; i > 0; i--)
    {
        if (a[i].y >= maxY){
            temp[j++] = a[i];
            if (a[i].y > maxY) 
                maxY = a[i].y;
        }
    }

    //If having possible point
    if (j > 0){
        std::cout << temp[j-1];
        for (int i = j - 2; i >= 0; i--)
        {
            std::cout << ", " << temp[i];
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "NO MAXIMA POINTS" << std:: endl;
    }

    delete[] temp;
}
