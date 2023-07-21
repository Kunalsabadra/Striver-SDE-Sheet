//Naive Approach
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

//Optimised Approach
 
 int dfsHeight(BinaryTreeNode<int>* root){
      if(root == NULL ) return 0;
      
      int lh = dfsHeight(root->left);
      if(lh == -1) return -1;

      int rh = dfsHeight(root->right);
      if(rh == -1) return -1;
       
       if(abs(lh-rh) > 1) return -1;
       return max(lh , rh)+1;

      
 }


bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(root == NULL) return true;
     return dfsHeight(root) != -1;
}
