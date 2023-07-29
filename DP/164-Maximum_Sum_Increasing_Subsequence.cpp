//Recursive
#include <bits/stdc++.h> 

 int solve(int idx ,int prev ,  vector<int> &rack , int n){
	  if(idx == n) return 0;

      int nottake = 0 + solve(idx+1 , prev , rack , n);
	  int take = 0;
	  if(prev == -1 or rack[idx] > rack[prev]){
		   take = rack[idx] + solve(idx+1 , idx , rack , n);
	  }
       return max(take , nottake);
 }

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	return solve(0 ,-1, rack ,  n);
}


//Memoization
#include <bits/stdc++.h> 

 int solve(int idx ,int prev ,  vector<int> &rack , int n , vector<vector<int>> &dp){
	  if(idx == n) return 0;
      if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
      int nottake = 0 + solve(idx+1 , prev , rack , n, dp);
	  int take = 0;
	  if(prev == -1 or rack[idx] > rack[prev]){
		   take = rack[idx] + solve(idx+1 , idx , rack , n, dp);
	  }
       return dp[idx][prev+1] =  max(take , nottake);
 }

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{    
	vector<vector<int>> dp(n , vector<int>(n+1 , -1));
	return solve(0 ,-1, rack ,  n , dp);
}

/*********************************************************************/
//Tabulation Code

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{    
	vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
	 for(int idx = n-1; idx>=0; idx--){
		  for(int prev = n; prev >=-1; prev--){
	   int nottake = 0 + dp[idx+1][prev+1];
	  int take = 0;
	  if(prev == -1 or rack[idx] > rack[prev]){
		   take = rack[idx] + dp[idx+1][idx+1];
	  }
	  dp[idx][prev+1] =  max(take , nottake); 
		  }
	 }
     return dp[0][0];
}



