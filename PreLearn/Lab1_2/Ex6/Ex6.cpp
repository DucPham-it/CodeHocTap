#include <iostream>
#include <vector>

using namespace std;

void floodFill(vector<vector<int>>& image, int sr,
int sc, int originalColor, int newColor);

int main (int argc, char *argv[]) {
  int m, n;
  int sr, sc;
  int newColor;

  cin >> m >> n;
  vector<vector<int>> image(m, vector<int>(n));
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> image[i][j];
    }
  }
  cin >> sr >> sc;
  cin >> newColor;
  
  int originalColor = image[sr][sc];
  if (originalColor != newColor)
    floodFill(image,sr, sc, originalColor, newColor);

  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cout << image[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}


void floodFill(vector<vector<int>>& image,
               int sr, int sc,
               int originalColor,
               int newColor)
{
    if (sr < 0 || sc < 0 ||
        sr >= image.size() ||
        sc >= image[0].size())
        return;

    if (image[sr][sc] != originalColor || image[sr][sc] == newColor)
        return;

    image[sr][sc] = newColor;

    floodFill(image, sr - 1, sc, originalColor, newColor);
    floodFill(image, sr + 1, sc, originalColor, newColor);
    floodFill(image, sr, sc - 1, originalColor, newColor);
    floodFill(image, sr, sc + 1, originalColor, newColor);
}

