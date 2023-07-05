//Optimised Approach: Using Moore Voting Algo
//T.C:O(N)
//S.C:O(1)

#include <bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr)
{      
      int n = arr.size();
      int num1 = -1 , num2 = -1 , cnt1=0 , cnt2 =0;
      for(int i=0; i<n; i++){
           if(arr[i] == num1) cnt1++;
           else if(arr[i] == num2) cnt2++;

           else if(cnt1 == 0){
                cnt1 = 1;
                num1 = arr[i];
           }
           else if(cnt2 == 0){
                cnt2 =1;
                num2 = arr[i];
           }
           else {
                cnt1--;
                cnt2--;
           }
      }
       int ct1 =0  , ct2 = 0;
      for(int i=0; i<n; i++){
           if(arr[i] == num1) ct1++;
           else if(arr[i] == num2) ct2++;
      }
      vector<int> ans;
      if(ct1 > n/3) ans.push_back(num1);
      if(ct2 > n/3) ans.push_back(num2);
      return ans;
}
