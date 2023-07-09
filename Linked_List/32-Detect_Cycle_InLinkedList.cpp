//Optimised Solution: Using Two Pointer Fast and slow 
// T.C:O(N)        Where N is the length of the linked list
// S.C:O(1)

bool detectCycle(Node *head)
{
	 if(head == NULL) return false;
     Node *fast =head , *slow = head;
     while(fast != NULL and fast->next != NULL){
           fast = fast->next->next;
           slow = slow->next;
          if(fast == slow) return true;
     }
    return false;
}
// ----------------------------------------------------------------------------
//Optimal Approach Using Hash Set
// T.C:O(N)        Where N is the length of the linked list
// S.C:O(N)

bool detectCycle(Node *head)
{
	set<Node*> st;
    while(head != NULL){
         if(!st.empty() and st.find(head) != st.end()) return true;
         st.insert(head);
         head = head->next;
    }
    return false;
}
