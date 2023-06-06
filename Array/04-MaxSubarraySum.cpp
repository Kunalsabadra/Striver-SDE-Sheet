#include <bits/stdc++.h> 
 //Better Approach
 //T.C: O(N^2);
//S.C: O(1);

long long maxSubarraySum(int arr[], int n)
{     
       long long sum = 0;
       long long maxi =0;
       for(int i=0; i<n; i++){
             sum  = 0;
            for(int j =i; j<n; j++){
                  sum += arr[j];

                  maxi = max(sum , maxi);
            }
       }
         return maxi;
}

//Optimal Approach----------------------------------------------
//Kadanes Algorithm
//T.C: O(N
//S.C:O(1)
long long maxSubarraySum(int arr[], int n)
{     
    //Kadanes Algorithm
     long long maxi = 0 , sum  = 0;
     for(int i=0; i<n; i++){
          sum += arr[i];
        maxi = max(maxi , sum);
        if(sum < 0) sum= 0;
     }
return maxi;
}
