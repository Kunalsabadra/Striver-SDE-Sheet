//Recursion Code
#include <bits/stdc++.h> 
int f(vector<int>& arr, int i, int j){ 
    // base condition
    if(i == j)   return 0;    
int mini = INT_MAX;
    // partioning loop
    for(int k = i; k<= j-1; k++){
        int ans = f(arr,i,k) + f(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini,ans);  
    }
    return mini;
}
int matrixMultiplication(vector<int>& arr, int N){ 
    int i =1;
    int j = N-1; 
    return f(arr,i,j); 
}
//Memoization Code
#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    
    // base condition
    if(i == j)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = 1e9;
    
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f(arr,i,k,dp) + f(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    
    vector<vector<int>> dp(N,vector<int>(N,-1));
    
    int i =1;
    int j = N-1;
    
    
    return f(arr,i,j,dp);
    
    
}
