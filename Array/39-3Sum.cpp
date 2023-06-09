//Brute Force
// T.C:O(N^3)
// S.C:O(M)

vector < vector < int >> threeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}


// --------------------------------------------------------------------------------------------------------
//Optimal Approach using Set and Sorting
// T.C:O(N^2 * logM)        where logM-> time to insert and find in set
// S.C:O(M)+O(N)

vector<vector<int>> threeSum(vector<int>& nums) {
         int n = nums.size();
          set<vector<int>> s;
          for(int i=0; i<n; i++){
               int num1 = nums[i];
                   set<int> st;
               for(int j=i+1; j<n; j++){
                    int num2 = nums[j];
                    int num3 = -(num1+num2);
                    if(st.find(num3) != st.end()){
                         vector<int> temp = {num1, num2 , num3};
                         sort(temp.begin() , temp.end());
                         s.insert(temp);
                    }
                    st.insert(num2);
               }
          }
            vector<vector<int>> ans(s.begin() , s.end());
            return ans;
    }
// -------------------------------------------------------------------------------------------------------
//Optimised Approach using Two Pointer
//T.C: O(N*N)+ O(NlogN)
// S.C:O(M)

vector<vector<int>> findTriplets(vector<int>num, int n, int K) {
        // int n = arr.size();
		 vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = K - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
}








