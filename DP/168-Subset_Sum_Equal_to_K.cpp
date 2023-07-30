//Recursice Approach
#include <bits/stdc++.h> 
 bool solve(int idx , int k , vector<int> &arr , int n){
      if(idx >= n) return false;
      if(idx == n-1){
          if(arr[idx] == k) return true;
          else return false;
      }

      bool nottake = solve(idx+1 , k , arr ,n);
       bool take  = false;
       if (arr[idx] <= k) {
         take = solve(idx + 1, k - arr[idx], arr, n);
       }
       return nottake or take;
 }

bool subsetSumToK(int n, int k, vector<int> &arr) {
      
      return solve(0 , k , arr , n);
}

/***********************************************************************/
//Memoization Approach
#include <bits/stdc++.h> 

 bool solve(int idx , int k , vector<int> &arr , int n,vector<vector<int>>&dp){
     if(k == 0) return true;
      if(idx == n-1){
          if(arr[idx] == k) return true;
          else return false;
      }
      if(dp[idx][k] != -1) return dp[idx][k];
      bool nottake = solve(idx+1 , k , arr ,n ,dp);
       bool take  = false;
       if (arr[idx] <= k) {
         take = solve(idx + 1, k - arr[idx], arr, n,dp);
       }
       return dp[idx][k] =  nottake or take;
 }

bool subsetSumToK(int n, int k, vector<int> &arr) {
       vector<vector<int>> dp(n,vector<int>(k+1 ,-1));
      return solve(0 , k , arr , n,dp);
}

/**************************************************************************************/
//Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
       vector<vector<int>> dp(n,vector<int>(k+1 ,-1));
      return solve(0 , k , arr , n,dp);
    
    for(int i=0; i<n;i++){
         dp[i][0] = true;
    }

    for(int i=0; i<=k;i++){
         dp[n-1][i] = (arr[n-1] == k);
    }

    for(int i=n-2; i>=0; i--){
         for(int j=0; j<=k;j++){
        bool nottake = dp[i+1][j];
       bool take  = false;
       if (arr[i] <= j) {
         take =dp[i + 1][k - arr[i]];
       }
        dp[i][k] =  nottake or take;
         }
    }
        return dp[0][0];
}
