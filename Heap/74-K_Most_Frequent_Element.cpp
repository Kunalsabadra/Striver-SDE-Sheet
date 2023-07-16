vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    //   int n = nums.size();
         unordered_map<int , int> mp;
         for(int i=0; i<n; i++){
              mp[nums[i]]++;
         }
          vector<int> ans;

          priority_queue<pair<int , int>> pq;
          for(auto it = mp.begin(); it != mp.end(); it++){
                pq.push({it->second , it->first});
                if(pq.size() > (int)mp.size()-k){
                    ans.push_back(pq.top().second);
                    pq.pop();
                }
          }
          return ans;
}
