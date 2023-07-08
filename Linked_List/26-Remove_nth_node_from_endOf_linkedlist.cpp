// Optimised Approach   using fast and slow pointer
// Time Complexity: O(N)
// Space Complexity: O(1)

Node* removeKthNode(Node* head, int k)
{   
     Node* start = new Node();
    start->next = head;
     Node* fast = start;
     Node* slow = start;

     for(int i=1; i<=k;i++){
          fast = fast->next;
     }
     while(fast->next != NULL){
          fast = fast->next;
          slow = slow->next;
     }
slow->next = slow->next->next;
  return start->next;
}
