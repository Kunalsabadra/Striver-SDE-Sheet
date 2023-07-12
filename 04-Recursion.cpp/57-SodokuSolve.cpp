//Using Recursion and Backtracking
// Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
// Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.

  
bool isValid(int matrix[9][9] , int r , int c , int no){
       
       for(int i=0; i<9; i++){
            if(matrix[i][c] == no) return false;
            if(matrix[r][i] == no) return false;

            if(matrix[3*(r/3)+i/3] [3*(c/3)+i/3] == no) return false;
       }
       return true;
}
 
bool isItSudoku(int matrix[9][9]) {
      for(int i=0; i<9; i++){
           for(int j=0; j<9; j++){
                 if(matrix[i][j] == 0){
                      for(int k=1; k<=9; k++){
                          if(isValid(matrix , i , j ,k )){
                               matrix[i][j] = k;

                               if(isItSudoku(matrix)) return true;

                               else matrix[i][j] = 0;
                          }     
                      }
                      return false;
                 }
           }
      }
      return true;      
} 
