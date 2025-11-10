class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*

        3 1 2 1
        3 1 2 1 2 2 2 2 1
        0 1 2 3 4 5 6
        2 2 3 4 5 4 2 
        4 5 3 2 1
        (0-7) 

        WE WILL ALWAYS HAVE TO CHOOSE SUBARRAY SUCH THAT IT CONTAINS ALL THE SMALLEST ELEMENTS

        JUST COUNT HOW MANY DISTINCT RANGES ARE THERE FOR EACH ELEMENT..
    
        THE ANSWER WILL BE ATLEAST NO. OF UNIQU ELEMENTS..

        */

        int n = nums.size();
        vector<array<int,2>>st1,st2;
        vector<int>pref(n,0),suff(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st1.empty() and nums[i]<=st1.back()[0]){
                cnt+=st1.back()[1];
                st1.pop_back();
            }
            pref[i]=cnt;
            st1.push_back({nums[i],cnt});  
        }

        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st2.empty() and nums[i]<=st2.back()[0]){
                cnt+=st2.back()[1];
                st2.pop_back();
            }
            suff[i]=cnt;
            st2.push_back({nums[i],cnt});  
        }

        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;
        // for(int i:suff) cout<<i<<" ";
        // cout<<endl;

        unordered_map<int,set<pair<int,int>>>mp;

        for(int i=0;i<n;i++){
            int lef= i-pref[i] +1;
            int rig= i+suff[i] -1;
           // cout<<lef<<" "<<rig<<endl;
            mp[nums[i]].insert({lef,rig});
        }
        for(auto &it:mp){
            if(it.first==0) continue;
            ans+=it.second.size();
        }
        return ans;

        

        
        
    }
};