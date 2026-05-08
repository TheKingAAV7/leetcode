class Solution {
public:
    vector<int>sieve;
    bool built=false;
    void build(int MX){
        // cout<<"BUIL"<<endl;
        // int MX= 1e6;
        sieve.resize(MX+1,1);
        sieve[0]=sieve[1]=0;
        for(int i=2;i<=MX;i++){
            if(sieve[i]==1){
                for(int j=2*i;j<=MX;j+=i){
                    if(sieve[j]==1)
                    sieve[j]=i;
                }
                sieve[i]=i;
            }
        }
        built=true;

    }
    int minJumps(vector<int>& nums) {
        int MX= *max_element(nums.begin(),nums.end());
        if(!built) build(MX);
        // for(int i=2;i<=MX;i++){ 
        // if(sieve[i])  cout<<sieve[i]<<" ";
        // }
        // cout<<endl;
        /*



        */
        
        int n= nums.size();
        // vector<int>ps;
        set<int>primes;
        for(int &i:nums){
            if(sieve[i]==i){
                // cout<<i<<endl;
                primes.insert(i);
            }
        }
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(primes.find(nums[i])!=primes.end()) mp[nums[i]].push_back(i);
        }
        // set<int>p(primes.begin(),primes.end());

        queue<array<int,2>>q;
        // queue<array<int,2>>q;
        vector<int>vis(n,INT_MAX);
        vis[n-1]=0;
        q.push({0,n-1});
        while(!q.empty()){
            auto cur= q.front(); q.pop();
            int cost= cur[0];
            int pos= cur[1];
            int ele= nums[cur[1]];
            // cout<<cost<<" "<<pos<<endl;
            // cout<<ele<<endl;
            while(ele>1){
                int p= sieve[ele];
                if(primes.find(p)!= primes.end()){
                for(int idx: mp[p]){
                    // cout<<idx<<endl;
                        if(cost+1<vis[idx]){
                        q.push({cost+1,idx});
                        vis[idx]= cost+1;
                        }
                 }
                 primes.erase(p);
                }
                while(ele>1 and ele%p==0) ele/=p;
            }
            if(pos-1>=0 and vis[pos-1]==INT_MAX){ 
            q.push({cost+1,pos-1});
            vis[pos-1]= cost+1;
            }
            if(pos+1<n and vis[pos+1]==INT_MAX){
             q.push({cost+1,pos+1});
             vis[pos+1]= cost+1;
            }
        }
        // for(int i:vis) cout<<i<<" ";
        // cout<<endl;
        return vis[0];

    }
};