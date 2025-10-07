class Solution {
public:
    vector<int> avoidFlood(vector<int>& arr) {
        int n=arr.size();
        set<int>st;
        map<int,int>mp;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                st.insert(i);
            }
            else{
                if(mp.find(arr[i])==mp.end()){
                    mp[arr[i]]=i;
                }
                else{
                    auto it=st.lower_bound(mp[arr[i]]);
                    if(it==st.end()) return {};
                    ans[*it]=arr[i];
                    st.erase(it);
                    mp[arr[i]]=i;
                }
            }
        }
        for(int i:st) ans[i]=1;
        return ans;
    }
};