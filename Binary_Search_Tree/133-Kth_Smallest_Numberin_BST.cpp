void inord(TreeNode<int>*root , vector<int> &inorder){
      if(root == NULL) return;
      inord(root->left , inorder);
      inorder.push_back(root->data);
      inord(root->right , inorder);
 }

int kthSmallest(TreeNode<int> *root, int k)
{    
     vector<int> inorder;
	 inord(root , inorder);
    //  for(auto it:inorder){
    //      cout<<it<<" ";
    //  }
    // cout<<endl;

     return inorder[k-1];
}
