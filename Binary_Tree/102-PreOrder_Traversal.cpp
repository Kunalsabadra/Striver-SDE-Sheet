   vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
       // vector<int> ans;
        if(root == NULL) return ans;
        else{ 
         ans.push_back(root->val);
         preorderTraversal(root->left);
         preorderTraversal(root->right);
        }
        return ans;
    }
