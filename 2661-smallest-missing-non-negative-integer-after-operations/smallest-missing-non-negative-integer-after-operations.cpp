class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int &i:nums){
            if(i<0){
                i=abs(i);
                mp[(k-(i%k))%k]++;
            }
            else{
                mp[i%k]++;
            }
        } 
        int cur=0;
        while(true){
            int reqmod=cur%k;
            if(mp.find(reqmod)!=mp.end()){
                mp[reqmod]--;
                if(mp[reqmod]==0) mp.erase(reqmod);
                cur++;
            }
            else return cur;
        }
        return -1;
    }
};