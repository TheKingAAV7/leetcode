class unif{
public:
vector<int>parent;
vector<int>rank;
int sz;

unif(int n){
    parent.resize(n);
    iota(parent.begin(),parent.end(),0);
    rank.resize(n,0);
    sz=n;
}

int findpar(int x){
    if(parent[x]==x) return x;
    return parent[x]=findpar(parent[x]);
}

void unify(int x, int y){
    int xpar=findpar(x);
    int ypar=findpar(y);
    if(xpar==ypar) return;
    if(rank[xpar]>rank[ypar]){
        parent[ypar]=xpar;
    }
    else if(rank[xpar]<rank[ypar]){
        parent[xpar]=ypar;
    }
    else{
        parent[ypar]=xpar;
        rank[xpar]++;
    }
    return;
}
int cntpar(){
    int cnt=0;
    for(int i=0;i<sz;i++){
        if(parent[i]==i) cnt++;
    }
    return cnt;
}



};


class Solution {
private:

public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int maxi=0;
        for(auto it:edges) maxi=max(maxi,it[2]);
        int lo=0,hi=maxi;
        int ans=maxi;
        auto f=[&](int mid)->bool{
            unif a=unif(n);
            for(auto it:edges){
                if(it[2]<=mid){
                    a.unify(it[0],it[1]);
                }   
            }
            return a.cntpar()<=k;
        };
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};