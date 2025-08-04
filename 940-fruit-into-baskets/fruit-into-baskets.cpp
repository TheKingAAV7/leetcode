class Solution {
public:
    int totalFruit(vector<int>& ft) {
        unordered_map<int,int>mp;
        int n=ft.size();
        int ans=0;
        int l=0;
        for(int i=0;i<n;i++){
            mp[ft[i]]++;
            while(mp.size()>2){
                mp[ft[l]]--;
                if(mp[ft[l]]==0) mp.erase(ft[l]);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};