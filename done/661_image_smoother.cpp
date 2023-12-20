/**
    @author [mst}
    @brief  leetcode series
    661_image_smoother
    An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

    gains:
    -basic array manipulations

    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// initial: use a sliding window across the whole matrix to calculate the averages
//
// sub 94 92
class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int height = img.size();
    int width = img[0].size();
    vector<vector<int>> res(height, vector<int>(width));

    for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {

        // process grid for this index:
        // sum the available cells and return the average
        int sum = 0;
        int cells = 0;  // initial cell
        for (int y = row-1; y < row+2; y++) {
          // check row boundaries
          if (y >= 0 && y < height) {
            for (int x = col-1; x < col+2; x++) {
              // check col boundaries
              if (x >= 0 && x < width) {
                sum += img[y][x];
                cells++;
              }
            }
          }
        }
        res[row][col] = sum/cells;  // int division will floor by default

      }
    }
    return res;
  }
};

// print matrix utility
void printMat(vector<vector<int>> &img) {
  // int height = img.size();
  // int width = img.size();

  // for (int row = 0; row < height; row++) {
  //   for (int col = 0; col < width; col++) {
  //     cout << img[row][col] << " ";
  //   }
  //   cout << endl;
  // }

  for (auto &row : img) {
    for (auto &i : row)
      cout << i << " ";
    cout << endl;
  }

  return;
}

////////////////// DRIVER
int main()
{
    Solution s;



    // vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    // vector<vector<int>> img = {{100,200,100},{200,50,200},{100,200,100}};
    vector<vector<int>> img = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    vector<vector<int>> res = s.imageSmoother(img);
    printMat(res);

    return 0;
}