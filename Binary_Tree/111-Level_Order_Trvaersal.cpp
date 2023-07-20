vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
      vector<int> ans;
      if(root == NULL) return ans;
      queue<BinaryTreeNode<int>*>q;
      q.push(root);
      while(!q.empty()){
          int n = q.size();
          for(int i=0; i<n; i++){
              BinaryTreeNode<int> *temp = q.front();
               q.pop();
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
               ans.push_back(temp->val);
          }
      }
      return ans;
}
