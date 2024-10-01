class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int>mp;
        for(int i=0;i<arr.size();i++){
            arr[i]=(arr[i]%k + k)%k;
            mp[arr[i]]++;
        }
        
        for(auto it: mp){
            if(it.first==0){
                if(it.second%2==0) continue;
                else return false;
            }
            if(mp.find(k-it.first)!=mp.end()){
                if(mp[k-it.first]!=it.second) return false;
            }
            else return false;
        }
        return true;
    }
};