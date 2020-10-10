// problem Link : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/



class Trie{
    
    //public :                 // all member function & variable is private now
    
        bool checkBit(int num, int pos){
            return (bool)((1<<pos)&num) ;
        }

        struct Node{
          Node* edge[2] ;
          Node(){
              for(int i=0 ; i<2 ; i++)edge[i] = nullptr ;
          }
        };

        Node* root = new Node() ;

        void INSERT(int num){
            Node* curr = root ;
            for(int i=31 ; i>=0 ; i--){
                bool bit = checkBit(num , i) ;
                if(curr->edge[bit] == NULL)
                    curr->edge[bit] = new Node() ;
                curr = curr->edge[bit] ;
            }

        }

        int getMx(int num){
            Node* curr = root ;
            int prev = 0 ;
            for(int i=31 ; i>=0 ; i--){
                bool bit = checkBit(num , i) ;
                if(curr->edge[bit^1]){
                    curr = curr->edge[bit^1] ;
                    bit = bit^1 ;
                }
                else
                    curr = curr->edge[bit] ;
                prev = prev | (bit << i)  ;
            }
            return num ^ prev ;
        }
    friend class Solution ;                // note it 

};



class Solution {
public:
    
    Solution(){
        ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
    }
    
    
    
    
    int findMaximumXOR(vector<int>& nums) {
        Trie trie ;
        
        for(auto num : nums)
            trie.INSERT(num) ;
        
        int ans = 0 ;
        for(auto num : nums)
            ans = max(ans , trie.getMx(num)) ;
            
        return ans ;
    }
};


