TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	   if(root == NULL) return root;
       int curr = root->data;
       if(curr > P->data and curr > Q->data){
          return  LCAinaBST(root->left, P, Q);
       }
       if(curr < P->data and curr < Q->data){
          return LCAinaBST(root->right, P, Q);
       }
       return root;
}
