#include <bits/stdc++.h> 

//Brute Force Approach----------------------------------------------------------------------------
//T.C: O(N^2);
//S.C: O(N)
int maximumProfit(vector<int> &arr){
     int n = arr.size();
     int pro  = 0;
     for(int i=0; i<n; i++){
         for(int j=i+1; j<n; j++){
              if(arr[j] > arr[i]) pro = max(pro , arr[j]- arr[i]);
         }
     }
     return pro;
}
//------------------------------------------------------------------------------------------------------
//Optimal Approach
//T.C:O(N)
//S.C: O(1)
int maximumProfit(vector<int> &arr){
     int n = arr.size();
   int pro = 0 , minPrice = INT_MAX;
     for(int i=0; i<n; i++){
           minPrice = min(minPrice , arr[i]);
           pro = max(pro , arr[i]-minPrice);
     }
     return pro;
}
