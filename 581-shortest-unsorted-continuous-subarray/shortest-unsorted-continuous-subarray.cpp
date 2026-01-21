class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n= nums.size();
        int lo= 2, hi= n-1;
        int ans=n;
        

        vector<int>pref(n,0);
        vector<int>suff(n,0);

        int prev=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=prev){
                cnt++;
                prev=nums[i];
            }
            else{
                cnt=1;
                prev=nums[i];
            }
            pref[i]=cnt;
        }
        if(pref[n-1]==n) return 0;
        prev=INT_MAX;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=prev){
                cnt++;
                prev=nums[i];
            }
            else{
                cnt=1;
                prev=nums[i];
            }
            suff[i]=cnt;
        }

        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;

        auto f=[&](int mid)->bool{
            multiset<int>st;
            for(int i=0;i<mid;i++){
                st.insert(nums[i]);
            }

            if(*st.rbegin()<=nums[mid] and suff[mid]==(n-mid)){
                return true;
            }

            for(int i= mid;i<n;i++){
                int pele= nums[i-mid];
                auto it= st.find(pele);
                st.erase(it);
                st.insert(nums[i]);
                int smallest= *st.begin();
                int largest= -1e9;
                if(i!=(n-1)) 
                largest= *st.rbegin();
                if(largest== -1e9){
                   // cout<<"Mi"<<" "<<mid<<endl;
                    if(pref[i-mid]==(i-mid+1) and smallest>=nums[i-mid]) return true;
                }
                if(smallest>=nums[i-mid] and (largest!=-1e9 and largest<=nums[i+1]) ){
                    if(pref[i-mid]== (i-mid+1)  and suff[i+1]==(n-(i+1))){
                        return true;
                    }
                }
            }
            //cout<<mid<<endl;
            return false;

        };
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans= mid;
                hi= mid-1;
            }
            else lo= mid+1;
        }
        return ans;
    }
};