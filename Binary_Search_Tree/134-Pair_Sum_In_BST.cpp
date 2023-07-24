
  void inord(BinaryTreeNode<int> *root ,vector<int> &inorder){
        if(root == NULL) return;
        inord(root->left , inorder);
        inorder.push_back(root->data);
        inord(root->right, inorder);
  }

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
         vector<int> inorder;
         inord(root , inorder);
          int n = inorder.size();
         int i=0, j=n-1;

         while(i < j){
              if(inorder[i] + inorder[j] == k) return true;
              else if(inorder[i] + inorder[j] < k) i++;
              else j--;
         }
       return false;
}
