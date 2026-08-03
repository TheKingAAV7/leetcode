class Solution {
public:
    int maximumWidth(vector<int>& arr) {
        int n= arr.size();
        map<int,int>cnt,res;
        for(int i=0;i<n;i++){
            cnt[arr[i]]++;
            res[arr[i]]++;
        }

        for(auto it1:cnt){
            for(auto it2:cnt){
                int a= it1.first;
                int b= it2.first;
                if(a < b){
                    res[a+b]+= min(cnt[a],cnt[b]);
                }
                if(a==b) res[a+b]+= cnt[a]/2;
            }
        }
        int ans=0;
        for(auto it:res) ans=max(ans,it.second);
        return ans;
    }
};