void inord(TreeNode<int>*root , vector<int> &inorder){
      if(root == NULL) return;
      inord(root->left , inorder);
      inorder.push_back(root->data);
      inord(root->right , inorder);
 }

int KthLargestNumber(TreeNode<int>* root, int k) 
{
     vector<int> inorder;
     
     inord(root , inorder);
    //   for(auto it:inorder){
    //        cout<<it<<" ";
    //   }
      int n = inorder.size();
      if(k > n) return -1;
     return inorder[n-k];
}
