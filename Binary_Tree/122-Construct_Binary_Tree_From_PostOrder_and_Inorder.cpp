 TreeNode<int>* Construct(vector<int> &postOrder , int postStart, int postEnd ,vector<int> &inorder ,  int inStart , int inEnd , map<int,int> mp){
             
             if(postStart > postEnd or inStart > inEnd) return NULL;

             TreeNode<int>* root =new TreeNode<int> (postOrder[postEnd]);
             int nnode = mp[root->data];
             int nleft = nnode-inStart;

     root->left = Construct(postOrder , postStart , postStart+nleft-1 ,inorder, inStart , nnode-1, mp);
     root->right = Construct(postOrder , postStart+nleft , postEnd-1 ,inorder ,nnode+1 , inEnd , mp);
     return root;
  }



TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{    
     int n = inOrder.size();
     if(n == 0) return NULL;
	int postStart = 0 , postEnd = postOrder.size()-1;
     int inStart = 0 , inEnd = inOrder.size()-1;
     map<int, int> mp;
     for(int i=0; i<inOrder.size();i++){
          mp[inOrder[i]] = i; 
     }
     return Construct(postOrder , postStart , postEnd , inOrder , inStart , inEnd , mp);

}
