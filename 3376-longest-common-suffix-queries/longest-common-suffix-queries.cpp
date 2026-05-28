class Solution {
public:
    struct Node {
        int nxt[26];
        int idx;
        Node() {
            fill(nxt, nxt + 26, -1);
            idx = -1;
        }
    };

    vector<Node> trie;

    int newNode() {
        trie.push_back(Node());
        return (int)trie.size() - 1;
    }

    vector<int> stringIndices(vector<string>& wC, vector<string>& wQ) {
        for (auto &it : wC) reverse(it.begin(), it.end());
        for (auto &it : wQ) reverse(it.begin(), it.end());

        int n = (int)wC.size();
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);

        sort(v.begin(), v.end(), [&](int a, int b) {
            int l1 = wC[a].length();
            int l2 = wC[b].length();
            if (l1 == l2) return a > b;
            return l1 > l2;
        });

        trie.clear();
        trie.reserve(1 + 500000);   // total length upper bound
        newNode();                  // root = 0

        for (int id : v) {
            int p = 0;
            string &s = wC[id];
            for (char c : s) {
                int next = c - 'a';
                if (trie[p].nxt[next] == -1) {
                    trie[p].nxt[next] = newNode();
                }
                p = trie[p].nxt[next];
                trie[p].idx = id;
            }
        }

        trie[0].idx = v.back();

        vector<int> ans;
        ans.reserve(wQ.size());

        for (auto &s : wQ) {
            int p = 0;
            for (char c : s) {
                int next = c - 'a';
                if (trie[p].nxt[next] == -1) break;
                p = trie[p].nxt[next];
            }
            ans.push_back(trie[p].idx);
        }

        return ans;
    }
};