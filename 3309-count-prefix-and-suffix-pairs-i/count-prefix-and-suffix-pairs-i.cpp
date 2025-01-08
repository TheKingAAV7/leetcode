class Solution {
private:
 
    long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            long long hash=compute_hash(words[i]);
            int m=words[i].size();
            
            for(int j=i+1;j<n;j++){
                if(i!=j){
                    if(words[j].length()>=words[i].length()){
                        int t=words[j].length();
                        long long hash1=compute_hash(words[j].substr(0,m));
                        long long hash2=compute_hash(words[j].substr(t-m,m));
                      //  cout<<hash1<<" "<<hash2<<" "<<hash<<endl;
                        if(hash1==hash and hash2==hash){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};