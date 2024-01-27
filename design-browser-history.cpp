struct Node{                // Just create a custom structure with url, prev and next pointers
    string val = "";        // similar to deque and do the needful as necessary.
    Node* prev = NULL;      
    Node* next = NULL;
    Node(string url){
        val = url;
    }
};

class BrowserHistory {
public:
    Node* curr = NULL;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps>0){
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL && steps>0){
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/*
*********************************** Alternate Implementation ***********************************

Here we keep track of backward and forward urls you can visit or have visited in two stacks.
and whenever a new url is visited we remove all previous options to visit forward urls.
If user wants to go back some steps you remove those many urls from first stack and put them in 
second stack. If they wanted to go to forward you remove the urls from second stack and put them 
in first one. And at the end you always return the url on top of first stack. Always make sure
first stack has atleast one element for that matter.

class BrowserHistory {
private:
    stack<string> backward, forwardSt;
public:
    BrowserHistory(string homepage) {
        forwardSt.push(homepage);
    }
    
    void visit(string url) {
        forwardSt.push(url);
        while (!backward.empty()) {
            backward.pop();
        }
    }
    
    string back(int steps) {
        while(forwardSt.size()>1 && steps>0){
            backward.push(forwardSt.top());
            forwardSt.pop();
            steps--;
        }
        return forwardSt.top();
    }
    
    string forward(int steps) {
        while(!backward.empty() && steps>0){
            forwardSt.push(backward.top());
            backward.pop();
            steps--;
        }
        return forwardSt.top();
    }
};
*/