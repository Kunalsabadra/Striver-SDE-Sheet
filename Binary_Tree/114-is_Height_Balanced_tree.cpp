
 int findHeight(BinaryTreeNode<int>* root){
      if(root == NULL) return 0;
      int lh = findHeight(root->left);
      int rh = findHeight(root->right);

      return 1+max(lh , rh);
 }

bool isBalancedBT(BinaryTreeNode<int>* root) {
      if(root == NULL) return true;

      int lh = findHeight(root->left);
      int rh = findHeight(root->right);

      if(abs(lh-rh) > 1) return false;

      bool left = isBalancedBT(root->left);
      if(!left) return false;
       
       bool right = isBalancedBT(root->right);
       if(!right) return false;
 return true;
}
