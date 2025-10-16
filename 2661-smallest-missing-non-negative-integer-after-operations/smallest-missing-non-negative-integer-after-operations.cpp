class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int k) {
        //  1 6 7 8 10

        int n=nums.size();
        map<int,multiset<int>>mp;
        map<int,int>pres;
        // for(int &i:nums) i=abs(i);
        for(int i:nums){
            if(i<0){
              int ss=abs(i);

              mp[(k-(ss%k))%k].insert(i);
            }
            else{
            mp[i%k].insert(i);
            }
            pres[i]++;
        }
        int cur=0;
        while(true){
           //cout<<cur<<endl;
            if(mp.find((cur%k))!=mp.end() ){
                int lst=*mp[cur%k].rbegin();
                pres[lst]--;
                if(pres[lst]==0) pres.erase(lst);
                mp[cur%k].erase(prev(mp[cur%k].end()));
                if(mp[cur%k].size()==0) mp.erase(cur%k);
                cur++;
            }
            else if(pres.find(cur)!=pres.end() ){
                pres[cur]--;
                if(pres[cur]==0) pres.erase(cur);
                auto it=mp[cur%k].find(cur);
                mp[cur%k].erase(it);
                if(mp[cur%k].size()==0) {
                mp.erase(cur%k);
                }
                cur++;
            }
            else{
                return cur;
            }
        }
        return n;

    }     
      /*

      
    keeping track of modulo?



    */
};