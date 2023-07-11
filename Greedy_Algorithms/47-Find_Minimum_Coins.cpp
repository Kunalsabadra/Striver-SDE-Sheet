//Optimised Approach
//T.C:O(AMOUNT)
//S.C:O(1)
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{     
    vector<int> arr ={1,2,5,10,20,50,100,500,1000};
     int n = arr.size();
     int i;
     for(i=0;i<n; i++){
          if(arr[i] > amount) break;
     }
    //  cout<<i<<" ";
int count = 0;
int j = i-1;
     while(j >= 0){
          if(arr[j] <= amount and amount > 0){ 
               amount -= arr[j];
               count++;
          }
          else if(arr[j] > amount) j--;
          if(amount == 0) break; 
     }
     return count;
}
