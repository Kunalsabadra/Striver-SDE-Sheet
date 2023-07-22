//Optimised Approach

bool isLeaf(TreeNode<int> *root){
     return !root->left and !root->right;
 }

 void add_left(TreeNode<int> * root , vector<int> &ans){
      TreeNode<int> *temp = root->left;
      while(temp){
           if(!isLeaf(temp)) ans.push_back(temp->data);
           if(temp->left) temp = temp->left;
           else  temp = temp->right;
      }
 }

 void add_right(TreeNode<int> *root , vector<int> &ans){
      TreeNode<int> *temp = root->right;
      vector<int> v;
      while(temp){
           if(!isLeaf(temp)) v.push_back(temp->data);
           if(temp->right) temp = temp->right;
           else temp = temp->left;
      }
      for(int i=v.size()-1; i>=0;i--){
          ans.push_back(v[i]);
      }
 }

 void add_Leaves(TreeNode<int> *root , vector<int> &ans){
      if(isLeaf(root)){
          ans.push_back(root->data);
          return;
      }
      if(root->left) add_Leaves(root->left , ans);
      if(root->right) add_Leaves(root->right , ans);
 }

vector<int> traverseBoundary(TreeNode<int>* root){
     vector<int> ans;
     if(root == NULL) return ans;
     if(!isLeaf(root)) ans.push_back(root->data);
     add_left(root , ans);
     add_Leaves(root , ans);
     add_right(root , ans);
     return ans;
}
