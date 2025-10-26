
#define ll long long
class Solution {
public:
    long long countStableSubarrays(vector<int>& arr) {
        /*

        9 3 3 3 9
        (9,9) (12,3) (15,3) (18,3) (27,9) 
        conditions:
        1) len>=3
        2) arr[l]==arr[r] and arr[l+1].. arr[r-1]

        prefix and pos works..
        ok, we have to consider all the remaining positions for each element..
        9 xxx 9 xxxxx 9      (4)  (10)  (3x) (8x+9)


        let's consider between sum -> not possible..
         ok, so, our logic seems correct
                    

        */
        int n=arr.size();
        map<pair<ll,int>,int>mp;
        // sm,int
        ll ans=0;
        ll sm=0;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            ll req= sm-(2*arr[i]);
            pair<ll,int>tmp=make_pair(req,arr[i]);
            
            if(mp.find(tmp)!=mp.end()){
                
             ans+=mp[tmp];
            }
            mp[{sm,arr[i]}]++;
            
        }

        ll cnt=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]==0 and arr[i+1]==0) cnt++;
        }
         
        return ans-cnt;
        
    }
};