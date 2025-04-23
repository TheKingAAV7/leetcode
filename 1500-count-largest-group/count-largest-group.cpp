class Solution {
public:
    int countLargestGroup(int n) {
       map<int,vector<int>>mp;
       for(int i=1;i<=n;i++){
        int sm=0;
        int num=i;
        while(num>0){
            sm+=num%10;
            num/=10;
        }
        mp[sm].push_back(num);
       } 
       vector<pair<int,vector<int>>>v(mp.begin(),mp.end());
       sort(v.begin(),v.end(),[&](pair<int,vector<int>>&a,pair<int,vector<int>>&b)->bool{
        return b.second.size()<a.second.size();
       });
       int cnt=1;
        for(int i=1;i<v.size();i++){
            cout<<v[i].second.size()<<" ";
            if(v[i].second.size()==v[i-1].second.size()) cnt++;
            else break;
        }
        return cnt;
        
    }
};