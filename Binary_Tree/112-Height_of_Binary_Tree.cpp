 int maxDepth(TreeNode* root) {
        int res = 0;
      if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n  = q.size();
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!= NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            res++;
        }
        return res;
    }
