TreeNode* bst(vector<int>&A , int& i , int bound){
        if(i == A.size() or A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = bst(A , i , root->val);
        root->right = bst(A , i , bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder , i , INT_MAX);
    }
