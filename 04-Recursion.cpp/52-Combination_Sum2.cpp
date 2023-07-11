//Using Recursion
// Time Complexity:O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). 
//   we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

// Space Complexity:O(k*x)
// Reason: if we have x combinations then space will be x*k where k is the average length of the combination.


#include<bits/stdc++.h>
 void solve(int ind , int n , int target , vector<int> &arr , vector<int> temp , vector<vector<int>> &ans){
	   if(target == 0){
		    ans.push_back(temp);
			return;
	   }

	   for(int i=ind; i<n; i++){
		    if(i > ind and arr[i] == arr[i-1]) continue;
			if(arr[i] > target) break;
			temp.push_back(arr[i]);
			solve(i+1 ,n , target-arr[i] , arr, temp,ans);
			temp.pop_back();
	   }
	   return;
 }

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
     sort(arr.begin() , arr.end());
	 vector<int> temp;
	 vector<vector<int>> ans;
	 solve(0 , n , target , arr , temp , ans);
	 return ans;	
}
