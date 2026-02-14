#include <iostream>
using namespace std;

struct Fraction {
  int numerator, denominator;
  Fraction(): numerator(0), denominator(1) {}
  Fraction(int n, int d): numerator(n), denominator(d) {}
};

typedef struct Fraction Fraction;

istream& operator>>(istream& in, Fraction& f) {
  char slash; // to read the '/' character
  in >> f.numerator >> slash >> f.denominator;
  return in;
}

ostream& operator<<(ostream& out, const Fraction& f) {
  if (f.denominator == 1 or f.numerator == 0) {
    out << f.numerator;
  }
  else {
    out << f.numerator << '/' << f.denominator;
  }
  return out;
}

struct arrayFraction {
private:
  Fraction* arr;
  int size;
public:
  arrayFraction(int s): size(s) {
    arr = new Fraction[size];
  }

  ~arrayFraction() {
    delete[] arr;
  }
public:
  Fraction& operator[](int index) {
    return arr[index];
  }
  arrayFraction (const arrayFraction& other) {
    size = other.size;
    arr = new Fraction[size];
    for (int i = 0; i < size; i++) {
      arr[i] = other.arr[i];
    }
  }

public:
  void inputArray() {
    for (int i = 0; i < size; i++) {
      cin >> arr[i];
    }
  }
  void outputArray() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << '\n';
    }
  }
  void insertFractionAtEnd(const Fraction& f) {
    Fraction* newArr = new Fraction[size + 1];
    for (int i = 0; i < size; i++) {
      newArr[i] = arr[i];
    }
    newArr[size] = f;
    delete[] arr;
    arr = newArr;
    size++;
  }

  void deleteFractionAtEnd() {
    if (size == 0) return;
    Fraction* newArr = new Fraction[size - 1];
    for (int i = 0; i < size - 1; i++) {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
  }
};

int main() {
  int n;
  cout << "Enter number of fractions: ";
  cin >> n;
  arrayFraction arr(n);
  cout << "Enter fractions:\n";
  arr.inputArray();
  cout << "You entered:\n";
  arr.outputArray();

  cout << "Deleting last fraction...\n";
  arr.deleteFractionAtEnd();
  cout << "After deletion:\n";
  arr.outputArray();

  cout << "Insert Fraction at end: ";
  Fraction f;
  cin >> f;

  arr.insertFractionAtEnd(f);
  cout << "After insertion:\n";
  arr.outputArray();

  return 0;
}
