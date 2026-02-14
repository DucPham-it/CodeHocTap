#include <iostream>

using namespace std;

void towerOfHaNoi( int n, char sourse, char auxiliary,
    char destination);

int main (int argc, char *argv[]) {
  int n;
  cout << "Enter numbers of disk in tower: ";
  cin >> n;
  char sourse = 'A';
  char auxiliary = 'B';
  char destination = 'C';
  towerOfHaNoi(n, sourse, auxiliary, destination);

  return 0;
}

void towerOfHaNoi( int n, char sourse, char auxiliary,
    char destination) {
  if (n == 0) {
    return;
  }

  towerOfHaNoi(n-1, sourse, destination, auxiliary);
  cout << "Move disk " << n << " from rod " << sourse << " to rod " << destination << "\n";
  towerOfHaNoi(n-1, auxiliary, sourse, destination);
}


