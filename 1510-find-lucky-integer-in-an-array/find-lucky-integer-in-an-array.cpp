class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mp;
        int cnt=-1;
        for(int i:arr){
            mp[i]++;
        }
        for(int i:arr){
            if(mp[i]==i) cnt=max(cnt,i);
        }
        return cnt;
    }
};