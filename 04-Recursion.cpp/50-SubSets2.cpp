//Using Redcursion

// Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. 
// Overall O(k * 2^n).

// Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.

#include <bits/stdc++.h> 
 void solve(int ind , int n , vector<int> &arr , vector<int> temp, vector<vector<int>> &ans){
            ans.push_back(temp);

            for(int i=ind; i<n; i++){
                 if(i != ind and arr[i] == arr[i-1]) continue;
                 temp.push_back(arr[i]);
                 solve(i+1 ,n, arr , temp , ans);
                 temp.pop_back();
            }
            return;
 }

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{  
     sort(arr.begin() , arr.end());
     vector<int>temp;
     vector<vector<int>> ans;
     solve(0 , n , arr , temp , ans);
     return ans;
    
}
