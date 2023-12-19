/**
    @author [mst]
    @brief  leetcode series
    661_image_smoother
    An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
    
    gains:
    -

    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// snipped
//
//
class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int height = img.size();
    int width = img.size();

    for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {
      }
    }
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> res = s.imageSmoother(img);


    return 0;
}