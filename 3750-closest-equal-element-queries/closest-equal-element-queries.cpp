class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        /*

        0 2  4  7 9 11
        size should be at least 4
        */
        map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            // mp[nums[i]].push_back(i+n);
        }
        vector<int>ans;
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
            // cout<<it.first<<" -> ";
            // for(auto i:it.second) cout<<i<<" ";
            // cout<<endl;
        }
        for(int x:queries){
            int val= nums[x];
            if(mp[val].size()<=1) ans.push_back(-1);
            else{
                auto &v= mp[val];
                auto it1= upper_bound(v.begin(),v.end(),x);
                int a1,a2,a3,a4,b1,b2,b3,b4;
                a1=a2=a3=a4=b1=b2=b3=b4=INT_MAX;
                if(it1!=v.end()){
                 a1= *it1-x;
                 b1= n-a1;
                }
                if(x!=v.back()){
                a3= v.back()-x;
                b3= n-a3;
                }
                if(x!=v[0]){
                a4= x-v[0];
                b4= n-a4;
                }
                
                b2=INT_MAX;
                a2= INT_MAX;
                auto it2= lower_bound(v.begin(),v.end(),x);
                if(it2!=v.begin()){
                    it2--;
                    a2= x- (*it2);
                    b2= n-a2;
                }
                // cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<endl;
                // cout<<x<<" "<<min({a1,a2,b1,b2,a3,b3,a4,b4})<<endl;
                ans.push_back(min({a1,a2,b1,b2,a3,b3,a4,b4}));
            }
        }
        return ans;
    }
};