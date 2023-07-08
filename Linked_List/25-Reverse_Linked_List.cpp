//Optimised Approach Traversing Linked lIst using three nodes head , dummy  and next
// T.C:O(N)
// S.C:O(1)

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
     LinkedListNode<int> *dummy = NULL;
     while (head != NULL) {
       LinkedListNode<int> *next = head->next;
       head->next = dummy;
       dummy = head;
       head = next;
     }
     return dummy;
}
