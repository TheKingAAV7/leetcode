class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans(arr.begin(),arr.end());
        
        sort(begin(ans),end(ans));
        unordered_map<int,int>mp;
        int cnt=1;
        for(int i=0;i<ans.size();i++){
            if(mp.find(ans[i])==mp.end()){
            mp[ans[i]]=cnt;
            cnt++;
            }
        }
        for(int &i:arr){
            i=mp[i];
        }
        return arr;
        
    }
};