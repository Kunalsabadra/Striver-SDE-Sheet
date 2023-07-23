bool searchInBST(BinaryTreeNode<int> *root, int x) {
      while(root != NULL and root->data != x){
          root = (root->data > x)? root->left : root->right;
      }
      return root;
}
