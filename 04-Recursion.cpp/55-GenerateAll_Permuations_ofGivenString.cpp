//Using Recursion and Backtracking
// Time Complexity: O(N! X N)
// Space Complexity: O(1)

  
#include <bits/stdc++.h>
void solve(int index , int n , string &s , vector<string> &ans){
     if(index == n){
          ans.push_back(s);
          return;
     }

     for(int i=index; i<n; i++){
          swap(s[i] , s[index]);
          solve(index+1 , n , s, ans);
          swap(s[i] , s[index]);
     }
     return;
}

vector<string> findPermutations(string &s) {
      int n = s.length();
      vector<string> ans;
      solve(0,n , s , ans);
      return ans;
}
