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

long countWaysToMakeChange(int *denominations, int n, int value)
{     
    vector<vector<long>> dp(n ,vector<long>(value+1 ,0));
    //   return solve(n-1 , denominations , value ,dp);

       for(int i=0; i<=value;i++){
           if(i%denominations[0] == 0)
            dp[0][i] = 1;
            else dp[0][i] =0;
       }

        for(int i=1; i<n;i++){
              for(int j=0; j<=value;j++){
        long nottake  = dp[i-1][j];
       long take = 0;
       if(denominations[i] <= j){
            take = dp[i][j - denominations[i]];
                  }
                dp[i][j] = take+nottake;
              }
        }
        return dp[n-1][value];
}
