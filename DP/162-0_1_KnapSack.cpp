//Recursion Code
#include<bits/stdc++.h>
int solve(int ind , int w , vector<int> &values , vector<int> &weights){
	
	if(ind == 0){
		 if(weights[0] <= w)  return values[0];
		 else return 0;
	}
	int nottake = 0 + solve(ind-1 , w,values , weights);
	int take = INT_MIN;
	if(weights[ind] <= w){
		 take = values[ind] + solve(ind-1 , w-weights[ind] , values , weights);
	}
	 return max(take , nottake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{ 
       return solve(n-1 , w , values , weights);

}


//memoization Code
#include<bits/stdc++.h>
int solve(int ind , int w , vector<int> &values , vector<int> &weights , vector<vector<int>>&dp){
	
	if(ind == 0){
		 if(weights[0] <= w)  return values[0];
		 else return 0;
	}

	if(dp[ind][w] != -1) return dp[ind][w];
	int nottake = 0 + solve(ind-1 , w,values , weights,dp);
	int take = INT_MIN;
	if(weights[ind] <= w){
		 take = values[ind] + solve(ind-1 , w-weights[ind] , values , weights,dp);
	}
	 return dp[ind][w] =  max(take , nottake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{       
	  vector<vector<int>> dp(n , vector<int>(w+1 , -1));
       return solve(n-1 , w , values , weights , dp);

}

//Tabulation Code

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{       
	//   vector<vector<int>> dp(n , vector<int>(w+1 , -1));
    //    return solve(n-1 , w , values , weights , dp);

	vector<vector<int>> dp(n, vector<int> (w+1 , 0));

	for(int i=weights[0]; i<= w;i++){
		 dp[0][i] = values[0];
	}

	for(int ind=1; ind<n;ind++){
		 for(int j =0; j<=w; j++){
	 int nottake = 0 + dp[ind-1][j];
	int take = INT_MIN;

	if(weights[ind] <= j){
		 take = values[ind] + dp[ind-1][j-weights[ind]];
	       }
		   dp[ind][j] = max(take ,nottake);

		 }
	}
      return dp[n-1][w];
}
