class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n= nums.size();
        int ans=INT_MIN;
        if(n==1) return 0;

        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                v.push_back(nums[j]);
            }
            // for(int j:v) cout<<j<<" ";
            // cout<<endl; 
            int m= v.size();
            vector<int>pref(m),suff(m);
            pref[0]=v[0];
            for(int j=1;j<m;j++) pref[j]=gcd(pref[j-1],v[j]);
            suff[m-1]=v.back();
            for(int j=m-2;j>=0;j--) suff[j]= gcd(suff[j+1],v[j]);
            int cnt=0;
            for(int j=0;j<m-1;j++){
                if(pref[j]==suff[j+1]) cnt++;
            }

            // for(int j:pref) cout<<j<<" ";
            // cout<<endl; 
            // for(int j:suff) cout<<j<<" ";
            // cout<<endl; 
            ans=max(ans,cnt);
        }

        vector<int>pref(n),suff(n);
            pref[0]=nums[0];
            for(int j=1;j<n;j++) pref[j]=gcd(pref[j-1],nums[j]);
            suff[n-1]=nums.back();
            for(int j=n-2;j>=0;j--) suff[j]= gcd(suff[j+1],nums[j]);
            int cnt=0;
            for(int j=0;j<n-1;j++){
                if(pref[j]==suff[j+1]) cnt++;
            }
        return max(cnt,ans);
    }
};