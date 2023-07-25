string serializeTree(TreeNode<int> *root)
{  
    if(root == NULL) return "";
    string ans = "";
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
         TreeNode<int> *curr = q.front();
         q.pop();
         if(curr == NULL) ans += "-1,";
         else ans += (to_string(curr->data) + ',');
         if(curr != NULL){
              q.push(curr->left);
              q.push(curr->right);
         }
    }
   return ans;
}



TreeNode<int>* deserializeTree(string &data)
{
   if(data.size() == 0) return NULL;
   stringstream s(data);
   string str;
   getline(s , str , ',');
   TreeNode<int> *root = new TreeNode<int>(stoi(str));
   queue<TreeNode<int>*> q;
   q.push(root);
   while(!q.empty()){
        
      TreeNode<int> *curr = q.front();
    q.pop();

    getline(s , str , ',');
    if(str == "-1") curr->left =NULL;
    else{
         TreeNode<int>* leftNode = new TreeNode<int>(stoi(str));
          curr->left = leftNode;
          q.push(leftNode);
    }

       getline(s , str , ',');
    if(str == "-1") curr->right = NULL;
    else{
         TreeNode<int>* rightNode = new TreeNode<int>(stoi(str));
          curr->right = rightNode;
          q.push(rightNode);
    }

   }
    return root;
}
