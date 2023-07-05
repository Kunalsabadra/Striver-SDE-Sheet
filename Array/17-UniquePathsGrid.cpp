//Optimised Approach using DP
//  T.C: O(n*m)
//S.C: O(1)

#include <bits/stdc++.h> 
 int solve(int r , int c , vector<vector<int>> &dp){
        if(r == 0 and c == 0) return 1;
		if(r < 0 or c < 0 ) return 0;

		if(dp[r][c] != -1) return dp[r][c];
		int up = solve(r-1 ,c , dp);
    int left = solve(r , c-1 , dp);
		return dp[r][c] = up+left;
 }

int uniquePaths(int m, int n) {
	 vector<vector<int>> dp(m , vector<int>(n,-1));
	 return solve(m-1 ,  n-1, dp);
}
