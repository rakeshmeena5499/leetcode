/*************************************************
    class Node {
        public :
            int data;
            Node *next;

            Node(int data) {
                this -> data = data;
                this -> next = NULL;
            }
    };
*************************************************/
Node *removeLoop(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){                 // Cycle Exists
            slow = head;
            while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
            }                           // Slow is the start of cycle
            while(fast->next!=slow){
                fast = fast->next;
            }                           
            fast->next = NULL;          // Remove cycle from fast->next
        }
    }
    return head;
}