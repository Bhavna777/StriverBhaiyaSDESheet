// Problem Link :- https://leetcode.com/problems/implement-trie-prefix-tree/


class TrieNode {
public:
    bool isWord;
    TrieNode *children[26];
    
    TrieNode(){
        isWord = false;
        
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        int k = 0;
        TrieNode *curr = root;
        
        for (int i = 0; i < n; i++){
            k = word[i] - 'a';
            
            if (curr -> children[k] == NULL){
                curr -> children[k] = new TrieNode();
            }
            
            curr = curr -> children[k];
        }
        
        curr -> isWord = true;
    }
    
    bool search(string word) {
        int n = word.length();
        int k = 0;
        TrieNode *curr = root;
        
        for (int i = 0; i < n; i++){
            k = word[i] - 'a';
            curr = curr -> children[k];
            
            if (curr == NULL){
                return false;
            }
        }
        
        return curr -> isWord;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        int k = 0;
        TrieNode *curr = root;
        
        for (int i = 0; i < n; i++){
            k = prefix[i] - 'a';
            curr = curr -> children[k];
            
            if (curr == NULL)
                return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */