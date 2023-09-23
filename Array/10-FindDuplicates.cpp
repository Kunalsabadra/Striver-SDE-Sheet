#include <bits/stdc++.h>

//Better Approach: Using Frequency array
// T.C:O(n)
// S.C:O(n)   where n is the no of elements in array
int findDuplicate(vector<int> &arr, int n){
	  vector<int>v(n+1,0);

	  for(int i=0; i<n; i++){
		   v[arr[i]]++;
	  }
	   int ans;
	  for(int i=1; i<n+1; i++){
            if (v[i] >1) {
              ans = i;
			  break;
            }

          }
		  return ans;
}

//Optimised Approach----------------------------------------------------------
//Using Linkedlist Cycle method
//T.C:O(N)
//S.C:O(1)
   int findDuplicate(vector<int>& nums) {
          int n = nums.size();
          int slow = nums[0];
          int fast = nums[0];

          do{
               slow = nums[slow];
               fast = nums[nums[fast]];
          }while(slow != fast);

         fast = nums[0];
         while(slow != fast){
              slow = nums[slow];
              fast = nums[fast];
         }
        return slow;
    }
