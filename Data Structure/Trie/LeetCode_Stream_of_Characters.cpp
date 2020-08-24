// problem link : https://leetcode.com/problems/stream-of-characters/





class StreamChecker {
public:
    
    struct Node{
        Node* edge[26];
        bool isEnd;
        Node(){
            for(int i=0;i<26;i++)edge[i]=NULL;
            isEnd= false ;
        }
    };
    Node* root;
    string pattern;
    void initTrie(){
        root = new Node() ;
    }
    
    void INSERT(string st){
        Node* currNode = root;
        for(int i=st.size()-1; i>=0; i--){ // reverse order
            if(currNode->edge[st[i]-'a'] == NULL)
                currNode->edge[st[i]-'a'] = new Node() ;
            currNode = currNode->edge[st[i]-'a'] ;
        }
        currNode->isEnd = true ;
    }
    
    StreamChecker(vector<string>& words) {
        initTrie() ;
        pattern="" ;        // init pattern string
        for(auto word:words)
            INSERT(word) ;
    }
    
    
    bool query(char letter) {
        Node* currNode = root;
        pattern+=letter;
    
        for(int i = pattern.size()-1; i>=0 ; i--){                  //check pattern string remain or not
            if(currNode->edge[pattern[i]-'a'] == NULL)return false;
            currNode = currNode->edge[pattern[i]-'a'] ;
            if(currNode->isEnd)return true;
        }
        return currNode->isEnd;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */