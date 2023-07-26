#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
      vector<vector<int>> graph(v);
      vector<int> indegree(v , 0);

      for(auto it:edges){
           graph[it[0]].push_back(it[1]);
           indegree[it[1]]++;
      }
      vector<int> ans;
      queue<int> q;
      for(int i=0; i<v;i++){
           if(indegree[i] == 0) q.push(i);
            
      }

      while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it:graph[curr]){
                  indegree[it]--;
                 if(indegree[it] == 0){
                      q.push(it);
                 }
            }
      }
     return ans;
}
