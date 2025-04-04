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
using namespace std;

struct Fraction {
    int numerator, denominator;
};

typedef struct Fraction Fraction;


ostream & operator << (ostream & output, const Fraction & fraction) {
    if (fraction.denominator == 1 || fraction.numerator == 0) {
        output << fraction.numerator;
    } else {
        output << fraction.numerator << "/" << fraction.denominator;
    }
    return output;
}


istream & operator >> (istream & input, Fraction & fraction) {
    input >> fraction.numerator >> fraction.denominator;
    return input;
}

void inputArrayOfFraction(Fraction *&fraction, int &n) {
    cout << "Enter the number of fractions: ";
    cin >> n;
    fraction = new Fraction[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter fraction " << i + 1 << ": ";
        cin >> fraction[i];
    }
}


void outputArrayOfFraction(Fraction *fraction, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Fraction " << i + 1 << ": " << fraction[i] << endl;
    }
}


void insertFractionAtEnd(Fraction *&fraction, int &n, Fraction value) {
    Fraction *newFraction = new Fraction[n + 1];
    for (int i = 0; i < n; i++) {
        newFraction[i] = fraction[i];
    }
    newFraction[n] = value;
    n++;
    delete[] fraction;
    fraction = newFraction;
}


void deleteFractionAtEnd(Fraction *&fraction, int &n){
    Fraction *newFraction = new Fraction[n - 1];
    for (int i = 0; i < n-1; i++) {
        newFraction[i] = fraction[i];
    }
    n--;
    delete[] fraction;
    fraction = newFraction;
}

void delocateFractionArray(Fraction *&fraction) {
    delete[] fraction;
    fraction = nullptr;
}

int main(int argc, char const *argv[])
{
    Fraction *fraction = nullptr;
    int n;
    inputArrayOfFraction(fraction, n);
    outputArrayOfFraction(fraction, n);

    Fraction *fractionPtr = new Fraction; 
    cout << "Enter a new fraction to at at end: ";
    cin >> (*fractionPtr);  
    insertFractionAtEnd(fraction, n, *fractionPtr);
    outputArrayOfFraction(fraction, n);

    cout << "Delete a fraction at end: " << endl;
    deleteFractionAtEnd(fraction, n);
    outputArrayOfFraction(fraction, n);


    delocateFractionArray(fraction);
    delete fractionPtr; 

    return 0;
}

