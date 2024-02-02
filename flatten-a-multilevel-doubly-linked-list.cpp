/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return head;
        Node* dummy = new Node(0, NULL, head, NULL);
        Node* prev = dummy;
        Node* curr = dummy;
        stack<Node*> st;
        st.push(head);
        while(!st.empty()){
            curr = st.top();
            st.pop();
            prev->next = curr;
            curr->prev = prev;
            if(curr->next!=NULL){
                st.push(curr->next);
            }
            if(curr->child!=NULL){
                st.push(curr->child);
                curr->child = NULL;
            }
            prev = curr;
        }
        head->prev = NULL;
        return dummy->next;
    }
};