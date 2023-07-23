  bool isValid(BinaryTreeNode<int>* root , int mini , int maxi){
        if(root == NULL) return true;
         if(root->data > maxi or root->data < mini) return false;
        return  isValid(root->left ,mini , root->data) and isValid(root->right , root->data , maxi);
  }


bool validateBST(BinaryTreeNode<int> *root) {
      if(root == NULL) return true;
      return isValid(root , INT_MIN , INT_MAX);
}
