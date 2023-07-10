//Optimised Approach
//T.C:O(N)+O(N-(N%K)) = O(N)
//S.C:O(1)

Node *rotate(Node *head, int k) {
     if(head == NULL or head->next == NULL or k == 0) return head;
          Node* curr= head;
          int len = 1;
          while(curr->next){
               len++;
               curr = curr->next;
          }

          curr->next = head;
          k = k%len;
          k = len-k;
          while(k--) curr = curr->next;
          head = curr->next;
          curr->next = NULL;
        return head;
}
