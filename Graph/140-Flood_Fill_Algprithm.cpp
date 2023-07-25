 void dfs(vector<vector<int>> &image , vector<vector<int>> &ans , int x, int y, int newColor , int col){
      ans[x][y] = newColor;
      int dr[4] = {-1,+1,0,0};
      int dc[4] = {0,0,-1,+1};

      for(int i=0;i<4;i++){
           int nr = x+dr[i];
           int nc = y+dc[i];

           if(nr >= 0 and nr < image.size() and nc >=0 and nc < image[0].size() and image[nr][nc] == col and ans[nr][nc] != newColor){
               dfs(image , ans , nr , nc , newColor , col);
           }
      }

 }

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
       vector<vector<int>> ans = image;
       int col = image[x][y];
       dfs(image , ans , x , y , newColor , col);
       return ans;
}
