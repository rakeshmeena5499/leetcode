struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
};

int countDistinctSubstring(string word){
    int n = word.size();
    int count = 0;
    Node* root = new Node();
    for(int i=0;i<n;i++){
        Node* node = root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(word[j])){
                node->put(word[j], new Node());
                count++;
            }
            node = node->get(word[j]);
        }
    }
    return count + 1; 
}