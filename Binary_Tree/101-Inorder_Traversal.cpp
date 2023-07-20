  vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
      if(root == NULL) return ans;
        else{
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
       return ans; 
    }
