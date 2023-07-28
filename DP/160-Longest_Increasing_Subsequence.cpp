//Recursive Approach
   int solve(int idx , int arr[] , int n){
        if(idx == n-1) return 1;
         
         int take = 0;
         if( arr[idx] < arr[idx+1]){ 
         take  = 1 + solve(idx+1 , arr , n);
         }
        int notTake = 0 + solve(idx + 1 , arr , n);

        return max(take , notTake);
   }

int longestIncreasingSubsequence(int arr[], int n)
{
     return solve(0,arr,n);
}

/**************************************************************************************/

//Memoization
#include<bits/stdc++.h>
   int solve(int idx ,int prev_idx , int arr[] , int n ,vector<vector<int>> &dp){
        if(idx == n) return 0;
          if(dp[idx][prev_idx+1] != -1)  return dp[idx][prev_idx+1];
         
       int  len = 0 + solve(idx + 1 ,prev_idx, arr , n ,dp);

         if( arr[prev_idx] < arr[idx] or prev_idx == -1){ 
         len  = max(len , 1 + solve(idx+1 ,idx ,  arr , n,dp));
         }

        return dp[idx][prev_idx+1] = len;
   }

int longestIncreasingSubsequence(int arr[], int n)
{      
     vector<vector<int>> dp(n , vector<int>(n+1 , -1));
     return solve(0,-1,arr,n , dp);
}

/**********************************************************************************************/
//Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{      
     vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
   
      for(int ind = n-1; ind >=0;ind--){
           for(int prev_ind = ind-1; prev_ind>=-1;prev_ind--){
                int len = 0+dp[ind+1][prev_ind+1];
                if(prev_ind == -1 or arr[ind] > arr[prev_ind]){
                    len = max(len, 1+dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1] = len;
           }
      }
      return dp[0][0];
}

/*******************************************************************************************/
//Space Optimisation
















