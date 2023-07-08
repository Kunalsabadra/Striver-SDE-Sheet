//Brute Force Approach using nested for loop
// T.C:O(N^2)
// S.C:O(1)

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



//Optimised Approach Using map
//T.C: O(NlogN)
// S.C:O(1)
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int k)
{   
      int n = arr.size();
      int cnt =0 , xr  =0 ;
      
      map<int , int> mp;
      mp[xr]++;
      for(int i=0; i<n; i++){
             xr = xr^arr[i];
             int x = xr^k;
             cnt += mp[x];
             mp[xr]++;
      }
      return cnt;
}
