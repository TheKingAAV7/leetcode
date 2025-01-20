class Solution {
private:
int f(int k,vector<vector<int>>mat,vector<int>&arr,int n,int m, int sz){
    unordered_map<int,int>mp;
    for(int i=0;i<k;i++){
        mp[arr[i]]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp.find(mat[i][j])!=mp.end()){
                mat[i][j]=0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bool allZeros = true;
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) return true;
    }

  
    for (int j = 0; j < m; j++) {
        bool allZeros = true;
        for (int i = 0; i < n; i++) {
            if (mat[i][j] != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) return true;
    }

    return false;

}
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
       int sz=arr.size();
       int n=mat.size();
       int m=mat[0].size();
       int l=min(n,m),h=sz;
       int ans=sz;
       while(l<=h){
        int mid=(l+h)>>1;
        if(f(mid,mat,arr,n,m,sz)){
            ans=mid-1;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
       }
       return ans;

    }
};