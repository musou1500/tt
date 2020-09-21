#ifndef DIM2_PARTIAL_SUM_HH
#define DIM2_PARTIAL_SUM_HH

#include <vector>

namespace tt
{
 
std::vector<std::vector<int>> Dim2PartialSum(std::vector<std::vector<int>> &mat, int w, int h) {
  std::vector<std::vector<int>> psum(h + 1, std::vector<int>(w + 1, 0));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      psum[i + 1][j + 1] =
          psum[i + 1][j] + psum[i][j + 1] + mat[i][j] - psum[i][j];
    }
  }

  return psum;
}

int Dim2PartialSumArea(std::vector<std::vector<int>> &psum, int x, int y, int w, int h) {
  return psum[y + h][x + w] - psum[y + h][x] - psum[y][x + w] + psum[y][x];
}
 
} /* tt */ 

#endif
