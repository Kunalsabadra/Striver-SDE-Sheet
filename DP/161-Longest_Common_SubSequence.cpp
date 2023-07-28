//Recursive Approach

  int solve(int idx1 , int idx2 , string s , string t){
	   if(idx1 < 0 or idx2 < 0) return 0;

       if(s[idx1] == t[idx2]) return 1 + solve(idx1-1 , idx2-1 , s , t);
	   else{
		    return max(solve(idx1-1 , idx2 , s , t) , solve(idx1 , idx2-1 , s , t));
	   }
	    return 0;
  }

int lcs(string s, string t)
{    
	int n = s.length() ,m = t.length();
     return solve(n-1 , m-1 , s , t);

}

/**********************************************************************************/
//Memoization Approach
 #include<bits/stdc++.h>
  int solve(int idx1 , int idx2 , string s , string t , vector<vector<int>> &dp){
	   if(idx1 < 0 or idx2 < 0) return 0;
       if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

       if(s[idx1] == t[idx2]) return dp[idx1][idx2] = 1 + solve(idx1-1 , idx2-1 , s , t,dp);
	   else{
		    return dp[idx1][idx2] =  max(solve(idx1-1 , idx2 , s , t , dp) , solve(idx1 , idx2-1 , s , t, dp));
	   }
	    return 0;
  }

int lcs(string s, string t)
{    
	int n = s.length() ,m = t.length();
	vector<vector<int>> dp(n , vector<int>(m , -1));
     return solve(n-1 , m-1 , s , t , dp);

}

/**********************************************************************************************/













