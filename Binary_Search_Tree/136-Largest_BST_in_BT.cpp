class NodeValue {
     public:
      int minNode , maxNode , maxSize;

      NodeValue(int minNode ,int maxNode , int maxSize){
          this->minNode = minNode;
          this->maxNode = maxNode;
          this->maxSize = maxSize;
      }
 };
 
 NodeValue largestSize(TreeNode<int>* root){
      //An Empty Binary Search Tree is of size 0.

      if(!root){
           return NodeValue(INT_MAX , INT_MIN , 0);
      }

      //Get size and values from left and right subtree
      auto left = largestSize(root->left);
      auto right = largestSize(root->right);

      if(left.maxNode < root->data and root->data < right.minNode){
           
           return NodeValue(min(root->data , left.minNode) , max(root->data , right.maxNode
           ) , left.maxSize+right.maxSize+1);
      }

      return NodeValue(INT_MIN , INT_MAX , max(left.maxSize , right.maxSize));
 }

int largestBST(TreeNode<int>* root) 
{
       return largestSize(root) .maxSize;
}
