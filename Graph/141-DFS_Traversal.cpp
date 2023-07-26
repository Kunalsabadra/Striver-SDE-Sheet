void dfs(vector<vector<int>> &graph , int V, vector<bool> &vis , vector<int> &temp){
    vis[V] = true;
    temp.push_back(V);
   
    for(auto it:graph[V]){
          if(!vis[it])
         dfs(graph ,it , vis , temp);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(V);
    vector<vector<int>> ans;

    for(auto it:edges){
         graph[it[0]].push_back(it[1]);
         graph[it[1]].push_back(it[0]);
    }

    vector<bool> vis(V , false);
     
         
        
      for(int i=0;i<V;i++){
          
           if(!vis[i]){
              vector<int> temp;
                dfs(graph , i, vis , temp);
                // sort(temp.begin() , temp.end());
                ans.push_back(temp);
           }
      }
return ans;
}
