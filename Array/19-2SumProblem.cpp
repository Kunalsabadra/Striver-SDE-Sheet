//Optimised Approach Using HashMap
//T.C: O(N) and in worst case O(N^2) Since we are using unordered_map if we map in best case and worst case iit O(N*logN)
//S.C:O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            map<int , int> mp;
            vector<int> ans;
            for(int i=0; i<n; i++){
                 if(mp.find(target-nums[i]) != mp.end()){
                     ans.push_back(i);
                     ans.push_back(mp[target-nums[i]]); 
                     return ans;
                 }
                 else{
                      mp[nums[i]] = i;
                 }
            }
            return ans;
    }
