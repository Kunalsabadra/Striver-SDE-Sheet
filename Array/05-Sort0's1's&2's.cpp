//Brute Force Approach Using Inbuilt Sorting Functiom
//T.C:O(NlogN) 
//S.C:O(1)

void sort012(vector<int> &nums){
   sort(nums.begin() , nums.end())
}
/*-------------------------------------------------------------------------------*/
//Better Approach : Mainting Count of three no's i.e 0 , 1 and 2
//T.C:O(N)+O(N)
//S.C:O(1)

void sortColors(vector<int>& nums) {
          int cnt0  = 0 , cnt1  = 0 , cnt2 = 0;

          for(auto it:nums){
               if(it  == 0) cnt0++;
               else if(it == 1) cnt1++;
               else cnt2++;
          }

          int i=0;
          while(cnt0 > 0){
               nums[i] = 0;
               i++;
               cnt0--;
          }
          while(cnt1 > 0){
               nums[i] = 1;
               i++;
               cnt1--;
          }
          while(cnt2 > 0){
               nums[i] = 2;
               i++;
               cnt2--;
          }
          return;
    }
/*---------------------------------------------------------------------------------------------------*/
//Optimal Approach: Dutch National Flag ALGORITHM
//T.C:0(N)
//S.C:O(1)

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
       int low = 0 , mid = 0 , high = n-1;

       while(mid <= high){
           if(arr[mid] == 0){
              swap(arr[mid] , arr[low]);
              mid++;
              low++;
           }
           else if(arr[mid] == 2){
              swap(arr[mid] , arr[high]);
               high--;
              }
              else mid++;
           }
       
}
