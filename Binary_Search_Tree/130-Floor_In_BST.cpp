int solve(TreeNode<int> *root , int X){
      TreeNode<int> *next = NULL;
       while(root != NULL){
           if(root->val <= X){
                next = root;
               root =  root->right;
           }
           else root = root->left;
       }
         
         int ans = -1;
       if(next != NULL) ans = next->val;
       return ans;
 }
 

int floorInBST(TreeNode<int> * root, int X)
{     
   
     return solve(root , X);
}
