
 int find_parent(int i , vector<int> &parent){
        
        if(i == parent[i]){
               return i;
        }
        
         return parent[i] =  find_parent(parent[i] , parent);
 }

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{      
        vector<int> parent(n+1 ,0);
        vector<int> rank(n+1 , 1);

        for(int i=1; i<=n;i++){
               parent[i] = i;
        }
        
        for(auto it:edges){
               int u = it[0];
               int v = it[1];

               int p1 = find_parent(u , parent);
               int p2 = find_parent(v , parent);

               if(p1 != p2){
                      if(rank[p1] > rank[p2]){
                            parent[p2] = p1;
                      }
                      else if(rank[p2] > rank[p1]){
                            parent[p1] = p2;
                      }
                      else{
                             parent[p1] = p2;
                             rank[p2]++;
                      }
               }
               else return "Yes";    
        }
         return "No";
}
