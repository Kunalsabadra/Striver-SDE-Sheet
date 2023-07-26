#include <bits/stdc++.h> 
vector<int> BFS(int v, vector<pair<int, int>> edges)
{
      vector<vector<int>> graph(v);

      for(auto it:edges){
           int a = it.first;
           int b = it.second;
           graph[a].push_back(b);
           graph[b].push_back(a);
      }

      vector<bool> vis(v,false);
      queue<int> q;
      q.push(0);
      vis[0] = true;
      vector<int> ans;
       
       while(!q.empty()){
                int curr = q.front();
                 q.pop();
                 ans.push_back(curr);
            
               
                 for(auto it:graph[curr]){
                      if(!vis[it]){
                           q.push(it);
                           vis[it] = true;
                      }
                 }
            
       }
        return ans;
}
