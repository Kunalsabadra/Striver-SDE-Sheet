//Brute Force Approach
bool isValid(string str){
          int n = str.length();
          int i=0 , j=n-1;
          while(i<=j){
              if(str[i] != str[j]) return false;
              i++;
              j--;
          }
          return true;
     }

    string longestPalindrome(string s) {
          int n = s.length();
          string res= "";
          for(int i=0; i<n; i++){
                for(int j=i;j<n;j++){
                  string str = s.substr(i , j-i+1);
                 if(isValid(str) and res.length() < str.length()) res= str;
                }
          }
          return res;



//Optimised Approach Using DP
bool isValid(string str){
  int n = s.length();
        string res;
        int maxlength = 0;

        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int diff = 0; diff<n;diff++){                              //for diagonally checking
             for(int i=0,j=i+diff;j<n;i++,j++){
                
                if(i == j) dp[i][j] = 1;

                else if(diff == 1){
                     if(s[i] == s[j]) dp[i][j] = 2;
                     else dp[i][j] = 0;
                }
                else{
                      if(s[i] == s[j] and dp[i+1][j-1]){
                           dp[i][j] = dp[i+1][j-1]+2;
                      }
                }
            
                     if(dp[i][j] > maxlength){
                          maxlength = dp[i][j];
                        res = s.substr(i , j-i+1);
                     } 
             }
        }
        return res;
}
