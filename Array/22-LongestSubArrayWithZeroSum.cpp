//Brute Force Approach
//T.C:O(N^2)
//S.C:O(1)

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  int n = arr.size();
  int maxi = 0;
  for(int i=0; i<n; i++){
     int sum =0;
     for(int j=i; j<n; j++){
       sum += arr[j];
       if(sum == 0) maxi = max(maxi , j-i+1);
     }
  }
   return maxi;
}


//Optimised Approach Using Unordered Map
//T.C:O(N)
//S.C:O(N)

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
      int n = arr.size();
      int maxi = 0 , sum = 0;
      unordered_map<int , int>mp;
      for(int i=0; i<n; i++){
        sum+= arr[i];
        if(sum == 0){
           maxi = i+1;
        }
        else if(mp.find(sum) != mp.end()){
           maxi = max(maxi , i-mp[sum]);
        }
        else mp[sum ] = i;
      }
return maxi;

}
