class BSTiterator
{   
    public:
    stack<TreeNode<int>*> st;
    
    void pushAll(TreeNode<int> * root){
         while(root != NULL){
              st.push(root);
              root = root->left;
         }
    }

    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
         TreeNode<int> *root = st.top();
         st.pop();
         pushAll(root->right);
        return root->data;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
};
