class Solution {
private:
    vector<int> fact;

    unordered_set<string> visited;
    
  
    string encode(const vector<int>& mp) {
        string key;
        for (int i = 0; i <= 9; i++) {
            key += to_string(mp[i]) + ",";
        }
        return key;
    }
    
    void f(int len, bool flag, string &tmp, int k, long long &ans, vector<int>& mp) {
        if (tmp.length() == len) {
            string final1 = tmp;
            reverse(final1.begin(), final1.end());
            if (flag) {
                for (int d = 0; d <= 9; d++) {
                    mp[d]++;
                    string stmp = tmp + to_string(d) + final1;
                    long long num = stoll(stmp);
                    if (num % k == 0) {
                   
                        string key = encode(mp);
                        if (visited.find(key) == visited.end()) {
                            visited.insert(key);
                            int len1 = stmp.length();
                            long long T = fact[len1];
                            for (int j = 0; j <= 9; j++) {
                                T /= fact[mp[j]];
                            }
                     
                            long long invalid = 0;
                            if (mp[0] > 0) {
                                invalid = fact[len1 - 1];
                                invalid /= fact[mp[0] - 1];
                                for (int j = 1; j <= 9; j++) {
                                    invalid /= fact[mp[j]];
                                }
                            }
                            ans += (T - invalid);
                        }
                    }
                    mp[d]--;
                }
            } else {
                string stmp = tmp + final1;
                long long num = stoll(stmp);
                if (num % k == 0) {
                  
                    string key = encode(mp);
                    if (visited.find(key) == visited.end()) {
                        visited.insert(key);
                        int len1 = stmp.size();
                        long long T = fact[len1];
                        for (int j = 0; j <= 9; j++) {
                            T /= fact[mp[j]];
                        }
                        long long invalid = 0;
                        if (mp[0] > 0) {
                            invalid = fact[len1 - 1];
                            invalid /= fact[mp[0] - 1];
                            for (int j = 1; j <= 9; j++) {
                                invalid /= fact[mp[j]];
                            }
                        }
                        ans += (T - invalid);
                    }
                }
            }
            return;
        }

        int lo = (tmp.size() == 0) ? 1 : 0;
        for (int i = lo; i <= 9; i++) {
            tmp.push_back((i + '0'));
            mp[i] += 2;
            f(len, flag, tmp, k, ans, mp);
            mp[i] -= 2;
            tmp.pop_back();
        }
        return;
    }
    
public:
    long long countGoodIntegers(int n, int k) {
        // if (n == 1) {
        //     if(k==1) return 9;
        // return 2;
        // }
        
       
        fact.resize(n + 1, 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        long long ans = 0;
        vector<int> mp(11, 0);
        int len = n / 2;
        bool flag = (n % 2);
        string num = "";
       
        visited.clear();
        f(len, flag, num, k, ans, mp);
        return ans;
    }
};
