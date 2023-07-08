//Optimised Approach
// Time Complexity: O(1)
// Space Complexity: O(1)

void deleteNode(LinkedListNode<int> * node) {
     LinkedListNode<int> *prev;
     if(node == NULL ) return;
     else{
       while (node->next != NULL) {
         node->data = node->next->data;
         prev = node;
         node = node->next;
       }
    //    delete (prev);
    prev->next = NULL;
     }
}
