vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>ans(3 , vector<int>());
     if(root == NULL) return ans;
      stack<pair<BinaryTreeNode<int> * , int>> st;
      st.push({root , 1});
       
       while(!st.empty()){
             auto it = st.top();
             BinaryTreeNode<int> *temp = it.first;
             int cnt = it.second;
              st.pop();
             if(cnt == 1){
                  ans[1].push_back(temp->data);
                  cnt++;
                  st.push({temp , cnt});
                  if(temp->left !=  NULL){ 
                      st.push({temp->left , 1});
                  }
             }

            else  if(cnt == 2){
                  ans[0].push_back(temp->data);
                  cnt++;
                  st.push({temp , cnt});
                  if(temp->right != NULL){
                      st.push({temp->right , 1});
                  }
             }
             else{
                  ans[2].push_back(temp->data);
             }
       }
         return ans;
}
