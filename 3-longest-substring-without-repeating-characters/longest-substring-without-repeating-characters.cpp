class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int lo=1,hi=n;
        auto f=[&](int k)->bool{
            map<char,int>mp;
            for(int i=0;i<k;i++) mp[s[i]]++;
            if(mp.size()==k) return true;
            for(int i=k;i<n;i++){
                mp[s[i-k]]--;
                if(mp[s[i-k]]==0) mp.erase(s[i-k]);
                mp[s[i]]++;
                if(mp.size()==k) return true;
            }
            return false;
        };
        int ans=1;
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