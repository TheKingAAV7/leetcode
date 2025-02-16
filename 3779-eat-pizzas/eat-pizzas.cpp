class Solution {
public:
    long long maxWeight(vector<int>& piz) {
       int n=piz.size(); 
       sort(piz.begin(),piz.end());
       int cnt=n/4;
       long long ans=0;
       int even=cnt/2;
       int odd=cnt-even;
       int pos=n-1;
       while(odd--){
        ans+=piz.back();
        piz.pop_back();
       }
       int id=piz.size()-2;
       while(even--){
        ans+=piz[id];
        id-=2;
       }
       return ans;
    }
};