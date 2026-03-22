
#include <iostream>
#include <chrono>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  auto start = chrono::steady_clock::now();
  for (int i = 0; i < 100000; ++i)
      cout << "Line " << i << endl;
  auto end = chrono::steady_clock::now();
  auto t1 = chrono::duration_cast<chrono::milliseconds>(end - start);
  
  start = chrono::steady_clock::now();
  for (int i = 0; i < 100000; ++i)
      cout << "Line " << i << '\n';
  end = chrono::steady_clock::now();
  auto t2 = chrono::duration_cast<chrono::milliseconds>(end - start);
  
  cout << "endl: " << t1.count() << " ms\n";
  cout << "\\n : " << t2.count() << " ms\n";
  return 0;
}

