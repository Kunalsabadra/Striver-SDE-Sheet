vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
     vector<int> ans;
     if(root == NULL) return ans;
     queue<BinaryTreeNode<int>*>q;
     q.push(root);
      bool left_to_right = true; 

     while(!q.empty()){
         int n = q.size();
         vector<int> row(n);
         for(int i=0; i<n;i++){
              BinaryTreeNode<int>* temp = q.front();
              q.pop();

              int index = (left_to_right) ? i : n-i-1;
              row[index] = temp->data;
              if(temp->left){
                   q.push(temp->left);
              }
              if(temp->right){
                  q.push(temp->right);
              }
         }
         left_to_right = !left_to_right;
         for(auto it:row){
             ans.push_back(it);
         }
     }
         return ans;
}
