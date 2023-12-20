struct Node{
    Node* links[26];
    bool flag;

    bool containsKey(char ch){
        return (links[ch - 'a']!=NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    bool getEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }
}

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        bool checkIfPrefixExists(string word){
            Node* node = root;
            bool flag = true;
            for(int i=0;i<word.size();i++){
               if(node->containsKey(word[i])){
                   node = node->get(word[i]);
                   if(node->getEnd() == false){
                       return false;
                   }
               }
            }
            return true;
        }
};

string completeString(vector<string>& words, int n){
    Trie trie;
    for(auto& word : words){
        trie.insert(word);
    }

    string longest = "";
    for(auto& word : words){
        if(checkIfPrefixExists(word)){
            if(word.size() > longest.size()){
                longest = word;
            }
            else if(word.size() == longest.size() && word < longest){
                longest = word;
            }
        }
    }

    if(longest == "")
        return "None";
    
    return longest;
}