class Solution {
// Copied

vector<int> f(int n,vector<vector<int>>&v){
    if(n==1){
        v.push_back({1});
        return {1};
    }
    if(n==2){
    v.push_back({1});
    v.push_back({1,1});
    return {1,1};
    }
    vector<int>an(n);
    an[0]=1;
    an[n-1]=1;
    vector<int> temp = f(n - 1, v);
    for(int i=1;i<n-1;i++){
     
      an[i]=temp[i-1]+temp[i];
    }
    v.push_back(an);
    return an;






}
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==1)
        return {{1}};
        if(numRows==2)
        return {{1},{1,1}};
        else{
         
       f(numRows,ans);
        }
        return ans;
        
    }
};