class Solution {
public:
    vector<vector<int>>ans;
    void f(int i, int n, vector<int>&arr, int &target, int sm,vector<int>&tmp){
        
        if(sm==target){
            ans.push_back(tmp);
            return;
        }
        if(i==n) return;
        if(sm>target) return ;
        int ans=0;
        // take current
        if((sm+arr[i])<=target){
        tmp.push_back(arr[i]);
        f(i,n,arr,target,sm+arr[i],tmp);
        tmp.pop_back();
        }
        // take next
        f(i+1,n,arr,target,sm,tmp);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>tmp;
        f(0,n,arr,target,0,tmp);
        
        return ans;
    }
};