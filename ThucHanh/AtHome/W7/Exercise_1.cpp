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
#include <vector>
using namespace std;

typedef long long ll;

ll recursiveFibonacci(ll n){
  if (n <= 1) return n;
  return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
}

ll memoizationFibonacci(ll n){
  if (n <= 1) return n;
  vector<int> arr(n, 0);
  arr[0] = 0;
  arr[1] = 1;
  for (ll i=2; i < n; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }
  return arr[n-1] + arr[n-2];
}

ll interativeFibonacci(ll n) {
  if (n <= 1) return n;
  ll a = 0;
  ll b = 1;
  ll c = 0;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

struct matrix {
  ll a[2][2];
  matrix() {
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
  }
  matrix operator * (matrix b) {
    matrix c;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        c.a[i][j] = 0;
        for(int k = 0; k < 2; k++) {
          c.a[i][j] += a[i][k] * b.a[k][j];
        }
      }
    }
    return c;
  }
};

matrix matrixFibonacci(matrix a, ll n) {
  if (n == 1) return matrix();
  if (n == 0) {
    matrix a;
    a.a[0][0] =  1;
    a.a[0][1] =   0;
    a.a[1][0] =   0;
    a.a[1][1] =   0;
    return a;
  };
  matrix tmp = matrixFibonacci(a, n / 2);
  if(n % 2 == 1){
    return tmp * tmp * a;
  }
  else{
    return tmp * tmp;
  }
}

int main(int argc, char const *argv[]){
  ll n;
  cout << "Enter a number th: ";
  cin >> n;

  matrix a;
  cout << "Recursive Fibonacci: " << recursiveFibonacci(n) << endl;
  cout << "Memoization Fibonacci: " << memoizationFibonacci(n) << endl;
  cout << "Interative Fibonacci: " << interativeFibonacci(n) << endl;
  cout << "Matrix Fibonacci: " << matrixFibonacci(a,n).a[0][1] << endl;
  return 0;
}