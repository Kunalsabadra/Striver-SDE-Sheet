//Rotate Matrix by 90deg Clockwise
#include<bits/stdc++.h>

//Optimal Approach:---------------------------------------------------------------------------------------------------
//T.C: O(N*N) + O(N*N).      Where: One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
//S.C:O(1)

//Take the transpose of the matrix and reverse each row of the matrix 
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
          
  //taking transpose of the matrix
          for(int i=0; i<n; i++){
               for(int j=0; j<i; j++){

                   swap(matrix[i][j] , matrix[j][i]);
               }
          }
          
  //reversing each row of the transposed matrix
           for(int i=0; i<n; i++){
               reverse(matrix[i].begin() , matrix[i].end());
           } 

    }
// --------------------------------------------------------------------------------------------------------------------------------------
//Rotate Matrix by 90 Deg Anticlockwise

//Optimal Approach: Get the transpose of the matrix and reverse each column of the matrix
//T.C: O(N*N) + O(N*N).      Where: One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
// S.C:O(1)

#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();

//Reverse Eaach Row
       for(int i=0; i<n;i++){
          for(int j=0; j<=i;j++){
              swap(matrix[i][j] , matrix[j][i]);
          }
       }

     /* Reverse every column */
  int ind = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      int temp = matrix[j][i];
      matrix[j][i] = matrix[ind][i];
      matrix[ind][i] = temp;
      ind--;
    }
    ind = n - 1;
  }
}









