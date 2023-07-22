  bool solve(BinaryTreeNode<int>* root1 , BinaryTreeNode<int>* root2){
         if(root1 == NULL or root2 == NULL) return root1 == root2;
         
         return ((root1->data == root2->data) and  solve(root1->left , root2->right)  and solve(root1->right , root2->left)); 
         
  }

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL) return true;
    if(solve(root->left , root->right)) return true;
    
