 int solve(TreeNode<int>* root , int &dia){
      if(root == NULL) return 0;

      int lh = solve(root->left, dia);
      int rh = solve(root->right , dia);
      dia = max(dia , lh+rh);

      return 1+max(lh , rh);
 }

int diameterOfBinaryTree(TreeNode<int> *root)
{
	if(root == NULL) return 0;
    int dia = 0;
      solve(root , dia); 
      return dia;  
}
