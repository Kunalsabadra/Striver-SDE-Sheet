#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
      vector<int> ans;
      priority_queue<int , vector<int> , greater<int>> pq;
      for(auto it:kArrays){
              vector<int> temp = it;
              for(int i=0;i<temp.size();i++){
                  pq.push(temp[i]);
              }
      }

      while(!pq.empty()){
          auto n = pq.top();
          pq.pop();
          ans.push_back(n);
      }
      return ans; 
}
