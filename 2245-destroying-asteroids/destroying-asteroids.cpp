class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        int n=arr.size();
        long long cur=mass;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(cur<arr[i]) return false;
            cur+=arr[i];
        }
        return true;
    }
};