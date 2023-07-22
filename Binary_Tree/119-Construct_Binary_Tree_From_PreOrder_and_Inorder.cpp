  TreeNode<int> *solve(vector<int> &inorder , int inStart , int inEnd , vector<int> &preorder , int preStart , int preEnd , map<int , int> &mp){
            if(preStart > preEnd or inStart > inEnd) return NULL;

            TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
            int innode = mp[root->data];
            int nleftElements = innode - inStart;
            root->left = solve(inorder , inStart , innode-1 , preorder , preStart+1 , preStart+nleftElements,mp);
            root->right = solve(inorder , innode+1 , inEnd , preorder , preStart+nleftElements+1 , preEnd , mp);

            return root;   
  }

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{      int n = inorder.size();
      if(n == 0) return NULL;
	int preStart = 0 , preEnd = preorder.size()-1;
    int inStart = 0 , inEnd = inorder.size()-1;
     map<int , int> mp;
    
     for(int i=0; i<n; i++){
          mp[inorder[i]]= i;
     }

     return solve(inorder , inStart , inEnd , preorder , preStart , preEnd , mp);

}
