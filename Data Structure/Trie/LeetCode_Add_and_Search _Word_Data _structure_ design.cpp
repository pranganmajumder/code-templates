//problem link : https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3413/








class WordDictionary {
public:
    /** Initialize your data structure here. */
    
    struct trieNode{
        bool isEnd ;
        trieNode* edge[26] ;
        trieNode(){
            isEnd = 0 ;
            for(int i=0;i<26;i++)edge[i]=nullptr ;
        }
    };
    trieNode* root ;
    
    
    
    WordDictionary() {
        root = new trieNode() ;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trieNode* currNode = root ;
        for(int i=0,len=word.size(); i<len ; i++){
            if(currNode->edge[word[i]-'a'] == nullptr)
                currNode->edge[word[i]-'a'] = new trieNode() ;
            currNode = currNode->edge[word[i]-'a'] ;
        }
        currNode->isEnd = true ;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    bool fun(string& word, int pos , trieNode* currNode){
        if(pos == word.size())
            return currNode->isEnd ;
    
        if(word[pos]=='.'){
            for(int i=0;i<26;i++){
                if(currNode->edge[i]){
                    if(fun(word, pos+1, currNode->edge[i]))
                       return true ;
                }
            }
            return false ;
        }
        else{
            if(currNode->edge[word[pos]-'a']){
                if (fun(word, pos+1, currNode->edge[word[pos]-'a']) )
                    return true ;
            }
            return false ;
        }
    }
    
    bool search(string word) {
        return fun(word , 0 , root) ; 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */