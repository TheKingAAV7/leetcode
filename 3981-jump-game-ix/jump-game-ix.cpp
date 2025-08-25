class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<array<int,2>>v;
        int x;
        map<int,int>mp;
        vector<int>suff(n,-1);
        mp[nums.back()]=n-1;
        suff[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            x=nums[i];
            auto it=mp.lower_bound(x);
            if(it==mp.begin()){
                mp[x]=max(mp[x],i);
                suff[i]=i;
            }
            else{
                it--;
                suff[i]=it->second;
                mp[x]=max({mp[x],it->second,i});
            }
        }

        for(int i=0;i<n;i++){
            v.push_back({i,suff[i]});
        }
        sort(v.begin(),v.end());
        vector<array<int,2>>nv;
        int mini=v[0][0];
        int maxi=v[0][1];
        for(int i=1;i<n;i++){
            int l=v[i][0];
            int r=v[i][1];
            if(l>maxi){
                nv.push_back({mini,maxi});
                mini=l;
                maxi=r;
            }
            else{
                maxi=max(maxi,r);
            }
        }
        nv.push_back({mini,maxi});
        vector<int>ans;
        for(auto it:nv){
            int l=it[0];
            int r=it[1];
            int maxi=-1;
            for(int i=l;i<=r;i++){
                maxi=max(maxi,nums[i]);
            }
            ans.push_back(maxi);
        }
        vector<int>res;
        for(int i=0;i<nv.size();i++){
             int l=nv[i][0];
            int r=nv[i][1];
            int cnt=r-l+1;
            for(int j=0;j<cnt;j++){
                res.push_back(ans[i]);
            }
        }
        return res;
    }
};