//Recursion: (Pick and not pick each element)
// Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. 
//   So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

// Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

 void solve(int ind , vector<int> &ans ,vector<int> &nums, int n , int sum){
         if(ind == n){
			 ans.push_back(sum);
             return;
		 }
		  solve(ind+1 , ans ,nums , n ,  sum+nums[ind]);
		  solve(ind+1 , ans ,nums , n ,  sum);
      return;
  }

vector<int> subsetSum(vector<int> &num){
		vector<int> ans;
		int n = num.size();
		int sum = 0;
		solve(0 , ans ,num ,  n , sum);
		sort(ans.begin() , ans.end());
		return ans;
}
