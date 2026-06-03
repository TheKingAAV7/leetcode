class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int n=lst.size();
        int m=wst.size();
        vector<array<int,3>>v1(n),v2(m);
        vector<int>suffw(m,-1),suffl(n,-1),prefw(m,-1),prefl(n,-1);
        for(int i=0;i<n;i++){
            v1[i]={lst[i],lst[i]+ld[i],ld[i]};
        }
        for(int i=0;i<m;i++) v2[i]={wst[i],wst[i]+wd[i],wd[i]};

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        int mini=INT_MAX;
        
        for(int i=n-1;i>=0;i--){
            mini=min(mini,v1[i][1]);
            suffl[i]=mini;
        }
        mini=INT_MAX;
        for(int i=m-1;i>=0;i--){
            mini=min(mini,v2[i][1]);
            suffw[i]=mini;
        }
        mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,v1[i][2]);
            prefl[i]=mini;
        }
        mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,v2[i][2]);
            prefw[i]=mini;
        }
        // llmini=INT_MAX;
        int ans=INT_MAX;
        // choose best for land rides
        for(int i=0;i<n;i++){
            int x=v1[i][1];
            auto it = lower_bound(v2.begin(), v2.end(), array<int,3>{x, 0, 0},
    [](const array<int,3>& a, const array<int,3>& b) {
        return a[0] < b[0];
    });
            if(it!=v2.end()){
                int idx=it-v2.begin();
                ans=min(ans,suffw[idx]);
            }
            // choose left;
            auto it1 = upper_bound(v2.begin(), v2.end(), array<int,3>{x, 0, 0},
    [](const array<int,3>& a, const array<int,3>& b) {
        return a[0] < b[0]; 
    });
            if(it1!=v2.begin()){
            it1--;
            int idx2=it1-v2.begin();
            ans=min(ans,x+prefw[idx2]);
            }
        }

        /////////////////////////////////



         for(int i=0;i<m;i++){
            int x=v2[i][1];
            auto it = lower_bound(v1.begin(), v1.end(), array<int,3>{x, 0, 0},
    [](const array<int,3>& a, const array<int,3>& b) {
        return a[0] < b[0];
    });
            if(it!=v1.end()){
                int idx=it-v1.begin();
                ans=min(ans,suffl[idx]);
            }
            // choose left;
            auto it1 = upper_bound(v1.begin(), v1.end(), array<int,3>{x, 0, 0},
    [](const array<int,3>& a, const array<int,3>& b) {
        return a[0] < b[0]; 
    });
            if(it1!=v1.begin()){
            it1--;
            int idx2=it1-v1.begin();
            ans=min(ans,x+prefl[idx2]);
            }
        }
        
        // (2,6) (8,9)       (2,4) (3,6) (6,9,3)  
        return ans;
    }
};