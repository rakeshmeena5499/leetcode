class Node{
    public:
        int val;
        int min;
        Node* next;
        Node(int val, int min, Node* next){
            this->val = val;
            this->min = min;
            this->next = next;
        }
};

class MinStack {
public:
    Node* head;
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        if(head == NULL){
            head = new Node(val, val, NULL);
        }
        else{
            head = new Node(val, min(head->min, val), head);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};