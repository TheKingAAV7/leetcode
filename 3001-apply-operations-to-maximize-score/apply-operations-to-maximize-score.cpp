class Solution {
private:
int mod=1e9+7;
 vector<int> sieve(int n) {
        vector<int> spf(n + 1);
        for (int i = 0; i <= n; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        return spf;
    }
int binpowmod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;  

    while (exp > 0) {
        if (exp & 1) { 
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  
        exp >>= 1;  
    }
    return result;
}
public:
    int maximumScore(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<long long>right(n,n);
        vector<long long>left(n,-1);
        vector<long long>ps(n,0);
        int maxi=*(max_element(nums.begin(),nums.end()));
        vector<int>spf=sieve(maxi);

          auto f = [&](long long x) -> int {
            if (x == 1) return 0;
            int cnt = 0;
            int prev = -1;
            while (x != 1) {
                int p = spf[x];
                if (p != prev) {
                    cnt++;
                    prev = p;
                }
                x /= p;
            }
            return cnt;
        };
        
        for(int i=0;i<n;i++){
            int tmp= f(nums[i]);
            ps[i]=tmp;
        }
        // for(int i:ps) cout<<i<<" "; cout<<endl;
        stack<long long>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and ps[i]>ps[st.top()]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<right[i]-i<<" ";
        // }
        // cout<<endl;
        stack<long long>st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() and (( ps[i] >=ps[st1.top()] ))){
                left[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }
        for(int i=0;i<n;i++) right[i]=(right[i]-i-1);
        for(int i=0;i<n;i++) left[i]=i-left[i];
        map<long long,long long>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]+=((right[i]+left[i])+(right[i]*(left[i]-1)));
            //cnt+=(right[i]+left[i]+(right[i]*(left[i]-1)));
        }
        vector<pair<long long,long long>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),greater<>());
        //for(auto it:v) cout<<it.first<<"->"<<it.second<<endl;
        long long pos=0;
        long long ans=1;
        while(k>0){
            //cout<<pos<<endl;
            long long  bas=v[pos].first;
            
            long long pov=min(k,v[pos].second);
           
            long long tm=binpowmod(bas,pov,mod);
            ans= (ans%mod * tm)%mod;
            k-= min(k,v[pos].second);
            //cout<<k<<endl;
            pos++;
        }
        
        return ans%mod;
    }
};