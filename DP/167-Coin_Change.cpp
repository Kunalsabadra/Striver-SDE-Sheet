//Recursive approach

 long solve(int idx , int *denominations , int value){
       if(idx == 0){
            if(value%denominations[0] == 0) return 1;
            else return 0;
       }

       long nottake  = solve(idx-1 , denominations , value);
       long take = 0;
       if(denominations[idx] <= value){
            take = solve(idx , denominations , value - denominations[idx]);
       }
       return take+nottake;
 }
 
long countWaysToMakeChange(int *denominations, int n, int value)
{
      return solve(n-1 , denominations , value);
}

//Memoization Approach
#include<bits/stdc++.h>
 long solve(int idx , int *denominations , int value , vector<vector<long>> &dp){
       if(idx == 0){
            if(value%denominations[0] == 0) return 1;
            else return 0;
       }
       if(dp[idx][value] != -1) return dp[idx][value];

       long nottake  = solve(idx-1 , denominations , value ,dp);
       long take = 0;
       if(denominations[idx] <= value){
            take = solve(idx , denominations , value - denominations[idx] ,dp);
       }
       return dp[idx][value] =  take+nottake;
 }
 
long countWaysToMakeChange(int *denominations, int n, int value)
{     
    vector<vector<long>> dp(n ,vector<long>(value+1 ,-1));
      return solve(n-1 , denominations , value ,dp);
}


//Tabulation
