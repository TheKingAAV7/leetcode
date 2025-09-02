class Solution {
public:
    vector<int>tmp;
    vector<int>ans;
    int diff=INT_MAX;
    void f(int n, int k){
     if(k==1){
        tmp.push_back(n);
        int mx=*max_element(tmp.begin(),tmp.end());
        int mn=*min_element(tmp.begin(),tmp.end());
        int d=mx-mn;
        if(d<diff){
            ans=tmp;
            diff=d;
        }
        tmp.pop_back();
        return;
     }
     for(int i=1;i<=n;i++){
        if(n%i==0){
            tmp.push_back(i);
            f(n/i,k-1);
            tmp.pop_back();
        }
     }
    }
    vector<int> minDifference(int n, int k) {
        f(n,k);
        return ans;
        
    }
};