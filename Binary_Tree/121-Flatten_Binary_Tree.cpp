//Approach1 : Using Stack

//Approach: Using recursion
//Approach 3: Iterative
 void solve(TreeNode<int> *cur , TreeNode<int>* prev){
     while(cur){
            if(cur->left){
                TreeNode<int>* pre = cur->left;
                while(pre->right){
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left= NULL;
            }
            cur = cur->right;
        }
    
 }

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{      
   TreeNode<int> *head = root;
  TreeNode<int> *prev = NULL;
      solve(root , prev);
      return head;
}
