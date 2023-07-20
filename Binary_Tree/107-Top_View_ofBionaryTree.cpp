vector<int> getTopView(TreeNode<int> *root) {
      vector<int> ans;
       if(root == NULL) return ans;
    queue<pair<TreeNode<int>* , int>> q;
    map<int , int>mp;
    q.push({root , 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int>*temp = it.first;
        int line = it.second;

        if(mp.find(line) == mp.end()){
            mp[line] = temp->val;
        }
        if(temp->left != NULL){
            q.push({temp->left , line-1});
        }

        if(temp->right != NULL){
            q.push({temp->right, line+1});
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}
