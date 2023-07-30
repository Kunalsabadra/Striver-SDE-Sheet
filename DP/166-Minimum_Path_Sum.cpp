//Recursive Approach
#include <bits/stdc++.h>  
 int solve(int r , int c,int n , int m ,vector<vector<int>> &grid){
      if(r == n-1 and c == m-1) return grid[r][c];
       if(r < 0 or c < 0 or r >= n or c >= m) return 1e9;

       int right = grid[r][c] + solve(r , c+1 , n , m , grid);
       int down = grid[r][c] + solve(r+1 , c, n , m , grid);
       return min(right , down);
 }

int minSumPath(vector<vector<int>> &grid) {
       int n = grid.size()  , m = grid[0].size();
       return solve(0 , 0 , n , m, grid);
}

//Memoization
#include <bits/stdc++.h> 
 
 int solve(int r , int c,int n , int m ,vector<vector<int>> &grid , vector<vector<int>> &dp){
      if(r == n-1 and c == m-1) return grid[r][c];
       if(r < 0 or c < 0 or r >= n or c >= m) return 1e9;
         if(dp[r][c] != -1) return dp[r][c];
       int right = grid[r][c] + solve(r , c+1 , n , m , grid , dp);
       int down = grid[r][c] + solve(r+1 , c, n , m , grid , dp);
       return dp[r][c] = min(right , down);
 }

int minSumPath(vector<vector<int>> &grid) {
       int n = grid.size()  , m = grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
       return solve(0 , 0 , n , m, grid , dp);
}

//Tabulation
int minSumPath(vector<vector<int>> &matrix) {
       int n = matrix.size()  , m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
    //    return solve(0 , 0 , n , m, grid , dp);

     for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}





