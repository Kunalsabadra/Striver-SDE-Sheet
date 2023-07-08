//Brute Force Approach using set and nested for loop
//T.c:O(N^2)
// S.C:O(N)

#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int n = s.length();
    int len = 0;

    for (int i = 0; i < n; i++) {
      unordered_set<int> st;
         for(int j=i; j<n; j++){
             if(st.find(s[j]) != st.end()){
                 len = max(len , j-i);
                 break;
             }
             st.insert(s[j]);
         }
    }
    return len;
}



//Optimal Approach using Unordered Set and two pointers l and r
// T.C:O(2N)
// S.C:O(N)
include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int n = s.length();
    int len = 0;
    unordered_set<char> st;
   int l =0  , r= 0 ;

   while(r < n){
      
      if(st.find(s[r]) != st.end()){
           while(st.find(s[r]) != st.end() and l <= r){
                st.erase(s[l]);
                l++;
           }   
              }
              st.insert(s[r]);
              len = max(len , r-l+1);
              r++;
   }
return len;
}




//Optimised Approach  -- Uing vector of 256 characters and two pointers l and r
//T.C: O(N)
//S.C:O(256)

#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; i++){
        int xr = 0;
        for(int j=i; j<n; j++){
            xr = xr^arr[j];
            if(xr == k )count++;
        }
    }
    return count;
}
