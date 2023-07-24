int findCeil(BinaryTreeNode<int> *root, int x){
     BinaryTreeNode<int>*temp = NULL;
     while(root != NULL){
         if(root->data >= x){
              temp = root;
              root = root->left;
         }
         else{
              root= root->right;
         }
     }
     int ans = -1;
     if(temp != NULL) ans = temp->data;
     return ans;
}
