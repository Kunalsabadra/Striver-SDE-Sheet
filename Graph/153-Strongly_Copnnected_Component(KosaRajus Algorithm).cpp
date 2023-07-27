#include<bits/stdc++.h>
void dfs(int node , vector<vector<int>> &graph, vector<int> &vis , stack<int> &st){
      vis[node] = 1;

      for(auto it:graph[node]){
           if(!vis[it]){
                dfs(it , graph , vis ,st);
           }
      }
      st.push(node);
}

void dfs2(int node , vector<vector<int>> &transpose , vector<int> &vis , vector<int> &temp){
      vis[node] = 1;
      temp.push_back(node);
      for(auto it:transpose[node]){
           if(!vis[it]){
                dfs2(it , transpose , vis , temp);
           }
      }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);

    for(auto it:edges){
         graph[it[0]].push_back(it[1]);
    }

    vector<int> vis(n , 0);
    stack<int> st;
    for(int i=0;i<n;i++){
         if(!vis[i]){
              dfs(i , graph , vis, st);
         }
    }

    vector<vector<int>> transpose(n);
     for(int i=0; i<n;i++){
         vis[i] = 0;
          for(auto it:graph[i]){
               transpose[it].push_back(i);
          }
     }
      
      int scc = 0;
     while(!st.empty()){
           int curr = st.top();
           st.pop();
           
        if(!vis[curr]){
            scc++;
            vector<int> temp;
             dfs2(curr ,transpose , vis, temp);
          //    for(auto it:temp){
          //          cout<<it<<" ";
          //    }
             ans.push_back(temp);
          //    temp.clear();
        }
        cout<<endl;
     }

     return ans;

}



