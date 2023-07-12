// Time Complexity: O( (2^n) *k*(n/2) )
// Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for
// inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

// Space Complexity: O(k * x)
// Reason: The space complexity can vary depending upon the length of the answer.
// k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. 
// The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

bool is_Palindrome(int l , int r , string s){
     while(l <= r){
          if(s[l] != s[r]) return false;
          else {
              l++;
              r--;
          }
     }
     return true;
}

void solve(int ind , int n , string s , vector<vector<string>> &ans , vector<string> temp){
     if(ind == n){
          ans.push_back(temp);
          return;
     }
     for(int i=ind; i<n; i++){
          if(is_Palindrome(ind , i , s)){
               temp.push_back(s.substr(ind , i-ind+1));
               solve(i+1 , n , s ,ans, temp);
               temp.pop_back();
          }
     }
       return;
}

vector<vector<string>> partition(string s) {
     int n = s.length();
     vector<vector<string>> ans;
     vector<string> temp;
     solve(0 , n , s , ans , temp);
     return ans;
}
