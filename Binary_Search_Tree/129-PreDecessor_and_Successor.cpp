//Finding Successor
 int successor(BinaryTreeNode<int>* root , int key){ 
       BinaryTreeNode<int> *succ = NULL;
       while(root != NULL){
         if (key < root->data) {
           succ = root;
           root = root->left;
         } else
           root = root->right;
       }

       int ans;
       if (succ == NULL)
         ans = -1;
       else
         ans = succ->data;
       return ans;
 }

//Finding Predecessor
 int predecessor(BinaryTreeNode<int>* root , int key){
       BinaryTreeNode<int> *pred = NULL;
       while(root != NULL){
           if(key <= root->data){
                root = root->left;
           }
           else{
               pred = root;
               root = root->right;
           }
       }

       int ans;
       if(pred ==NULL) ans = -1;
       else ans = pred->data;
       return ans;
 }

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
     pair<int, int> ans;
     ans.first = predecessor(root , key);
     ans.second = successor(root , key);
     return ans;
}
