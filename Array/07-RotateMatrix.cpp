#include<bits/stdc++.h>

//Optimal Approach:---------------------------------------------------------------------------------------------------
//T.C: O(N*N) + O(N*N).      Where: One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
//S.C:O(1)
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
