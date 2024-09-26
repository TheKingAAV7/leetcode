class TrieNode{
public:
vector<TrieNode*>children;
bool isendofword;

TrieNode(){
    isendofword=false;
    children.resize(26,NULL);
}

};

class Trie {
TrieNode* root;


public:
    Trie() {
       root= new TrieNode();
        
    }
    

    void insert(string word) {
        TrieNode* crawl=root;
        for(auto ch: word){
            int idx= ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]= new TrieNode();
            }
            crawl= crawl->children[idx];

        }
        crawl->isendofword=true;


        
    }
    
    bool search(string word) {
        TrieNode * crawl=root;
        for(auto ch: word){
            int idx= ch-'a';
            if(crawl->children[idx]==NULL) return false;
            crawl=crawl->children[idx];
        }
        return crawl->isendofword==true;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode * crawl=root;
        for(auto ch:prefix){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL) return false;
            crawl=crawl->children[idx];
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