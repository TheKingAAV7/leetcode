class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        vector<int>ans(n,1);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[ratings[i]].push_back(i);
        }
        int maxi=*max_element(ratings.begin(),ratings.end());
        for(int i=1;i<=maxi;i++){
            if(mp.find(i)!=mp.end()){
            for(int pos:mp[i]){
                int maxi=0;
                if(pos-1 >=0 and ratings[pos]> ratings[pos-1]){
                    maxi=max(maxi,ans[pos-1]);
                }
                if(pos+1 <n and ratings[pos]>ratings[pos+1]) {
                      maxi=max(maxi,ans[pos+1]);
                }
                ans[pos]=maxi+1;
              }
            }
            
        }
        int cnt=accumulate(ans.begin(),ans.end(),0);
        return cnt;
    }
};