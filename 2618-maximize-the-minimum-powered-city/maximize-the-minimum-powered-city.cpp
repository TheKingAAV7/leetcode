
#define ll long long
class Solution {
public:
/*

        1 2 4 5 0
        0 1 2 3 4 
        1 1
        2 2 2
          4 4 4
            5 5 5


        3 7 11 9 5  
         4 4 4 4
         

        do binary search and check for each r+1 window, 

        what if we require (3, 5) (2) over here.
        ok, seems good..  
            
        13,12,8,14,7  R=2

        0 1 2 3 4 5
        13 13 13
        12 12 12 12
        8  8  8  8  8
           14 14 14 14
              7  7  7
        


        Doubts:
        1) SHould i always insert all the powerstations at a particular position?
        Let's check if we can we make all >= x


        */
    long long maxPower(vector<int>& arr, int r, int k) {
        
        int n=arr.size();
        

        vector<long long>mp(n+1,0);
        for(int i=0;i<n;i++){
            int lef= max(0,i-r);
            int rig= min(n,i+r+1);
            mp[lef]+=arr[i];
            //cout<<rig+1<<endl;
            mp[rig]-=arr[i];

           
        }
        
        ll sm=0;
        for(int i=0;i<n;i++){
            sm+=mp[i];
            mp[i]=sm;
        }
        for(int i=0;i<n;i++){ 
        cout<<mp[i]<<" ";
        //mp[i]+=arr[i];
        }
        cout<<endl;

       auto f=[&](ll mid)->bool{
            ll needTotal=0;
            int len = 2*r + 1;
            vector<ll> added(n,0);   
            ll windowAdded = 0;      

            for(int i=0;i<n;i++){
                if(i - len >= 0) windowAdded -= added[i - len];
                ll currPower = mp[i] + windowAdded;
                if(currPower < mid){
                    ll need = mid - currPower;
                    added[i] = need;
                    windowAdded += need;
                    needTotal += need;
                    if(needTotal > k) return false;
                }
            }
            return needTotal <= k;
        };
        
        ll lo=0,hi=1e15;
        ll ans=lo;

        while(lo<=hi){
            ll mid= lo + (hi-lo)/2;
            if(f(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;

        }

        return ans;

    }
};