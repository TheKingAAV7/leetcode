class WordDictionary {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord = false;
    };
    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index) {
        if (index == word.size())
            return node->isEndOfWord;
        
        char ch = word[index];
        if (ch == '.') {
            for (auto& [key, child] : node->children) {
                if (dfs(child, word, index + 1))
                    return true;
            }
        } else {
            if (node->children.count(ch) && dfs(node->children[ch], word, index + 1))
                return true;
        }
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
