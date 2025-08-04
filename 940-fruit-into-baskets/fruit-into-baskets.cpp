class Solution {
public:
    int totalFruit(vector<int>& ft) {
        unordered_map<int,int>mp;
        int n=ft.size();
        int ans=0;
        int lo=1,hi=n;
        auto f=[&](int m)->bool{
            unordered_map<int,int>mp;
            for(int i=0;i<m;i++){
                mp[ft[i]]++;
            }
            if(mp.size()<=2) return true;
            for(int i=m;i<n;i++){
                mp[ft[i-m]]--;
                if(mp[ft[i-m]]==0) mp.erase(ft[i-m]);
                mp[ft[i]]++;
                if(mp.size()<=2) return true;
            }
            return false;
        };
        while(lo<=hi){
            int m=(lo+hi)>>1;
            if(f(m)){
                ans=m;
                lo=m+1;
            }
            else hi=m-1;
        }
        return ans;
    }
};