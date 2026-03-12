class Solution {
public:

/*
8 6

I can  double k edges
which edges to pick?
does pq even help;
pick the one with largest 2*s
after k edges are covered just divide the later edges by 2
those who don't form a cycle and need double..

*/

class DSU{
public:
vector<int>par,rank;
int n;
DSU(int n){
this->n=n;
par.resize(n,0);
rank.resize(n,0);
iota(par.begin(),par.end(),0);
}

int findpar(int x){
    if(par[x]==x) return x;
    return par[x]=findpar(par[x]);
}
bool unify(int x,int y){
    int parx=findpar(x);
    int pary=findpar(y);
    if(parx==pary) return false;
    if(rank[parx]>rank[pary]){
        par[pary]= parx;
    }
    else if(rank[pary]>rank[parx]){
        par[parx]= pary;
    }
    else{
        rank[parx]++;
        par[pary]=parx;
    }
    return true;
}
int comp(){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(par[i]==i) cnt++;
    }
    return cnt;
}
};
    int maxStability(int n, vector<vector<int>>& edges, int K) {
        

        auto f=[&](int lim)->bool{
        priority_queue<array<int,3>>pq;
        DSU d= DSU(n);
        int stab=INT_MAX;
        for(auto &it:edges){
            if(it[3]==1){
                stab=min(stab,it[2]);
                if(!d.unify(it[0],it[1])) return false;
                
            }
            else{
                pq.push({2*it[2],it[0],it[1]});
             
            }
        }
        int k=K;
        
        int curstab=stab;
        while(!pq.empty()){
            auto cur= pq.top();pq.pop();
            int cost= cur[0];
            int prev= cost/2;
            bool used=false;
            if(cost<lim) continue;
            if(k<=0){
             cost/=2;
             if(cost<lim) continue;
            }
            else{
                if(prev>=lim){
                 cost=prev;
                 }
                 else{
                    k--;
                    used=true;
                 }
            }
            int x= cur[1];
            int y= cur[2];
            if(d.unify(x,y)){
                curstab=min(curstab,cost);
            }
            else{
                if(used) k++;
            }
        }
        if(d.comp()==1) return curstab>=lim;
        return false;

        };
        int lo=1, hi=2e5;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;        
    }
};