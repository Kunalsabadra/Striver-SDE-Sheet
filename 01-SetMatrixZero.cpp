#include<bits/stdc++.h>

 //brute Force Approach------------------------------------------------------------------------------
//T.C:  O((N*M)*(N + M)) + O(N*M)  WHERE N=> NO OF ROWS , M => NO OF COLUMNS
//S.C: O(1)
 void markRow(vector<vector<int>> &matrix , int m , int n , int i){
         
		 for(int j=0; j<n; j++){
			 if(matrix[i][j] != 0)  matrix[i][j] = -1;
		 }

 }
  void markCol(vector<vector<int>> &matrix , int m , int n , int j){
           for(int i=0; i<m; i++){
			  if(matrix[i][j] != 0) matrix[i][j] = -1;
		 }
 }

void setZeros(vector<vector<int>> &matrix)
{  
	 int m = matrix.size();
	 int n = matrix[0].size();

	 for(int i=0; i<m; i++){
		  for(int j=0; j<n; j++){
			   if(matrix[i][j] == 0){
				    markRow(matrix , m , n , i);
                    markCol(matrix , m , n , j);
			   }
		  }
	 }

	 for(int i=0; i<m; i++){
		 for(int j=0; j<n; j++){
			 if(matrix[i][j] == -1) matrix[i][j] = 0;
		 }
	 }
	
}
//---------------------------------------------------------------------
 //better Approach--------------------------------------------------
//T.C: O(2*(N*M))      WHERE N=> NO OF ROWS , M => NO OF COLUMNS
//S.C : O(N+M)         WHERE N=> NO OF ROWS , M => NO OF COLUMNS
void setZeros(vector<vector<int>> &matrix)
{    
    int n = matrix.size();
    int m = matrix[0].size();
	 vector<int> row(n , 0);
     vector<int> col(m , 0); 
       
       for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
       }

       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
                if(row[i] == 1 or col[j] == 1) matrix[i][j] = 0;
           }
       }
}
//-------------------------------------------------------------------------------------
//Optimal Approach----------------------------------------------------------
//T.C:  O(2*(N*M)),  WHERE N=> NO OF ROWS , M => NO OF COLUMNS
//S.C: O(1)
void setZeros(vector<vector<int>> &matrix)
{    
      int n = matrix.size();
      int m = matrix[0].size();
      int col0 = 1;
      for(int i=0; i<n; i++){
           for(int j =0; j<m; j++){
                if(matrix[i][j] == 0){

                    //marking ith row
                     matrix[i][0] = 0;

                     //marking jth column
                     if (j != 0) {
                         matrix[0][j] = 0;
                     }
                     else col0 = 0;
                }

           }
      }

        for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
              
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
      // mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    } 
     
}
 
 
 
 
 
 
 
 
 
 
