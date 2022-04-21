#include <stdio.h>
#include "Math.h"

typedef struct {
  int row;
  int col;
  float entries[3][3];
}Mat;

Mat newmat(int r,int c,float data[9]){
  Mat M;
  M.row = r;
  M.col = c;
  int count = 0;
  for(int i=0 ; i<r; i++)
  {
    for(int j=0; j<c; j++)
    {
      M.entries[i][j] = data[count];
      count++;
    }
  }
  return M;
}

void set(Mat M,int r,int c,float d){
  M.entries[r][c]=d;
}

Mat sum(Mat A,Mat B){
  Mat M;
  M.row = A.row;
  M.col = A.col;
  float dataM[9] = {0};
  M = newmat(A.row, A.col, dataM);
  for(int i = 0; i < A.row; i++)
  {
    for(int j = 0; j< A.col; j++)
    {
      M.entries[i][j] = A.entries[i][j] + B.entries[i][j];
    }
  }
  return M;
}

Mat minus(Mat A,Mat B){
  Mat M;
  M.row = A.row;
  M.col = A.col;
  float dataM[9] = {0};
  M = newmat(A.row, A.col, dataM);
  for(int i = 0; i < A.row; i++)
  {
    for(int j = 0; j < A.col; j++)
    {
      M.entries[i][j] = A.entries[i][j] - B.entries[i][j];
    }
  }
  return M;
}

Mat multiply(Mat A,Mat B){
  Mat M;
  M.row = A.row;
  M.col = B.col;
  float dataM[9] = {0};
  M = newmat(A.row, B.col, dataM);
  for(int i = 0; i < A.row; ++i)
  {
    for(int j = 0; j < B.col; ++j)
    {
      for(int k = 0; k < A.col; ++k)
      {
        M.entries[i][j] += A.entries[i][k] * B.entries[k][j];
      }
    }
  }
  return M;
}

Mat transpose(Mat A){
  Mat M;
  M.row = A.col;
  M.col = A.row;
  float dataM[9] = {0};
  M = newmat(A.col, A.row, dataM);
  for(int i = 0; i < A.row; ++i)
  {
    for(int j = 0; j < A.col; ++j)
    {
      M.entries[j][i] = A.entries[i][j];
    }
  }
  return M;
}
