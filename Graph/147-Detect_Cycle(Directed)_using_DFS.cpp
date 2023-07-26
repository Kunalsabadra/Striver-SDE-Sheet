

 bool dfs(int i,vector<vector<int>> &graph , vector<bool> &vis , vector<bool> &pathvis){
          vis[i] = true;
          pathvis[i] = true;

          for(auto it:graph[i]){
              if(!vis[it]){
                 if(dfs(it , graph , vis , pathvis) == true) return true;;
              }
              else if(pathvis[it]) return true;
          }
          pathvis[i] = false;
          return false;
 }


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
          
           vector<vector<int>> graph(n+1);

           for(auto it:edges){
              int a = it.first;
              int b = it.second;
               
               graph[a].push_back(b);
           }

           vector<bool> vis(n+1 , 0);
           vector<bool> pathvis(n+1 , 0);

           for(int i=1; i<=n;i++){
              if(!vis[i]){
                 if(dfs(i ,graph , vis , pathvis) == true) return true;
              }

           }
           return false;
 }
