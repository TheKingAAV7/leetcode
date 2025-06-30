class Solution {
private:
vector<int>par,rank;

int findpar(int x){
    if(par[x]==x) return x;
    return par[x]=findpar(par[x]);
}
bool uni(int x, int y){
    int parx=findpar(x);
    int pary=findpar(y);
    if(parx==pary) return false;
    if(rank[parx]>rank[pary]){
        par[pary]=parx;
    }
    else if(rank[pary]==rank[parx]){
        par[pary]=parx;
        rank[parx]++;
    }
    else par[parx]=pary;
    return true;
}
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        par.resize(n,0);
        iota(par.begin(),par.end(),0);
        rank.resize(n,0);
        long long mini1=INT_MAX;
        int cnt=0;
        priority_queue<vector<long long>>pq;
        
        for(auto it:edges){
            if(it[3]==1){
                bool f=uni(it[0],it[1]);
                if(!f) return -1;
                mini1=min(1ll*it[2],mini1);
                cnt++;
            }
            else pq.push({it[2],it[0],it[1]});
        }
        vector<long long>st;
        long long mini=INT_MAX;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            bool tmp=uni(it[1],it[2]);
            if(tmp){
                st.push_back(it[0]);
                cnt++;
            }
        }
        sort(st.begin(),st.end());
        for(long long &i:st){
        if(k){
            i=i*2;
            k--;
        }
        else break;
        }
        if(st.size()>0) mini=min(mini,*min_element(st.begin(),st.end()));

        long long ans;
        ans=min(mini, mini1);
        if(cnt!=(n-1) ) return -1;
        return (int)ans;
    }
};