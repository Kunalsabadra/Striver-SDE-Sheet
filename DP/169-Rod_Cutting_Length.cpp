//Recursive Approach
.
int solve(int ind , int n , vector<int> &price){
	  
	  if(ind == 0) return n*price[0];

	  int nottake = 0+solve(ind-1 , n , price);
	  int take = INT_MIN;
	  int rodlength = ind+1;
	  
	  if(rodlength <= n){
		   take = price[ind] + solve(ind , n-rodlength , price);
	  }
	  return max(take , nottake);
}

int cutRod(vector<int> &price, int n)
{
	return solve(n-1, n , price);
}

/********************************************************************************************/
//Memoization Approach
int solve(int ind , int n , vector<int> &price, vector<vector<int>> &dp){
	  
	  if(ind == 0) return n*price[0];
      if(dp[ind][n] != -1) return dp[ind][n];
	  int nottake = 0+solve(ind-1 , n , price ,dp);
	  int take = INT_MIN;
	  int rodlength = ind+1;
	  
	  if(rodlength <= n){
		   take = price[ind] + solve(ind , n-rodlength , price,dp);
	  }
	  return dp[ind][n] = max(take , nottake);
}

int cutRod(vector<int> &price, int n)
{    
	vector<vector<int>> dp(n ,vector<int>(n+1 , -1));
	return solve(n-1, n , price ,dp);
}
/*****************************************************************************************/
//Tabulation Approach

int cutRod(vector<int> &price, int n)
{    
	vector<vector<int>> dp(n ,vector<int>(n+1 , 0));
     for(int i=0; i<=n;i++){
		  dp[0][i] = i*price[0];
	 }

	 for(int i=1; i<n; i++){
		  for(int j=0; j<=n; j++){
	  int nottake = dp[i-1][j];
	  int take = INT_MIN;
	  int rodlength = i+1;
	  
	  if(rodlength <= j){
		   take = price[i] + dp[i][j-rodlength];
	  }
	  dp[i][j] = max(take , nottake);
		  }
	 }

	return dp[n-1][n];
}
