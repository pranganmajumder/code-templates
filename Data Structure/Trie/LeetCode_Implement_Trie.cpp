
// problem link : https://leetcode.com/problems/implement-trie-prefix-tree/


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    struct node{
        bool isEnd ;
        node* edge[26] ;
        node(){
            isEnd = 0 ;
            for(int i = 0 ; i<26 ; i++)edge[i] = nullptr ;
        }
    };
    node* root = new node() ;
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* curr = root ;
        for(int i = 0 , len = word.size() ; i<len ; i++){
            if(curr->edge[word[i]-'a'] == nullptr){
                curr->edge[word[i]-'a'] = new node() ;
            }
            curr = curr->edge[word[i]-'a'] ;
        }
        curr->isEnd = 1 ;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node*curr = root ;
        for(int i = 0 , len = word.size() ; i<len ; i++){
            if(curr->edge[word[i]-'a'] == nullptr)return false ;
            curr = curr->edge[word[i] - 'a'] ;
        }
        return (curr->isEnd) ;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* curr = root ;
        for(int i = 0 , len = prefix.size() ; i<len ; i++){
            if(curr->edge[prefix[i] - 'a'] == nullptr)return false ;
            curr = curr->edge[prefix[i] - 'a'] ;
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */