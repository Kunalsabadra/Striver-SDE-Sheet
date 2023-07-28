class DisjointSet{
 vector<int> rank , parent , size;
public:

DisjointSet(int n){
  rank.resize(n+1,0);
  parent.resize(n+1);
  size.resize(n+1);
  for(int i=0; i<=n; i++){
     parent[i] = i;
     size[i] = 1;
  }
}

int find_parent(int node){
    if(node == parent[node]) return node;
  return parent[node] = find_parent(parent[node]);
}

void unionByRank(int u , int v){
     int p1 = find_parent(u)
     int p2 = find_parent(v);
    if(rank[p1] < rank[p2]){
       parent[p1] = p2;
    }
  else if(rank[p2] < rank[p1]){
    parent[p2] = p1;
  }
  else{
      parent[p1] = p2;
    rank[p2]++;
  }  
}
};
