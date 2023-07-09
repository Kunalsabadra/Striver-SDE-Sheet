//Optimised Approach
// Time Complexity: O(N)
// Space Complexity: O(1)


Node *firstNode(Node *head)
{  
    Node* fast = head , *slow = head , *entry = head;

    //Checking for a cycle
    while(fast->next != NULL and fast->next->next != NULL){
            slow= slow->next;
            fast = fast->next->next;

            if(fast == slow){                 //Cycle Found
                while(entry != slow){         //finding the point where cycle begins
                     slow = slow->next;
                     entry = entry->next;
                }
                return entry;
            }

    }
    return NULL;
}
