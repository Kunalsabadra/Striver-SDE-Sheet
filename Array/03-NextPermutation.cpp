#include <bits/stdc++.h> 

//Using Inbuilt NextPermutation function------------------------
//T.C: O(N)       //Number of Elements
//S.C: O(1)
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //using in built function;
  vector<int> ans(permutation.begin() , permutation.end());

 next_permutation(ans.begin() , ans.end());
return ans;
     
}


//Optimal Approach----------------------------------------------------
//T.C: O(N)       //Number of Elements
//S.C: O(1)
void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int i ,j;
        for(i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        if(i<0){
            reverse(nums.begin() ,nums.end());
        }
        else{
            for(j=n-1; j>i; j--){
                if(nums[j] > nums[i]){
                    break;
                }
            }
            swap(nums[i] , nums[j]);
            reverse(nums.begin()+i+1 , nums.end());
        }
    }
