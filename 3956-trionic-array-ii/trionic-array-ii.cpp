#define ll long long

class SparseTable{
    public:
    int K=25;
    vector<vector<ll>>dp;
    int n;
    SparseTable(int n,vector<ll>&arr ){
        this->n=n;
        dp.resize(n,vector<ll>(K,LLONG_MAX));

        for(int i=0;i<n;i++) dp[i][0]=arr[i];
        for(int k=1;k<K;k++){
            for(int i=0;(i+(1<<(k-1)))<n;i++){
                dp[i][k]= min(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
            }
        }
    }

    ll query(int l, int r){
        int dist=r-l+1;
        int idx=l;
        int pos=0;
        ll tans=LLONG_MAX;
        while(dist>0){
            if(dist&1){
                tans=min(tans,dp[idx][pos]);
                idx+=(1<<pos);
            }
            pos++;
            dist>>=1;
        }
        return tans;
    }
};
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<ll>endinc(n,0),stdec(n,0),stinc(n,0);
        int cnt=0;
        int prev= INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>prev){
                cnt++;
            }
            else cnt=1;
            endinc[i]=cnt;
            prev=nums[i];
        } 

        prev=INT_MAX;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<prev){
                cnt++;
            }
            else cnt=1;
            stinc[i]=cnt;
            prev=nums[i];
        }

        prev=INT_MIN;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>prev){
                cnt++;
            }
            else cnt=1;
            stdec[i]=cnt;
            prev=nums[i];
        }
        vector<ll>pref(n,0),suff(n,0);
        ll sm=0;

        for(int i=0;i<n;i++){
            sm+=nums[i];
            pref[i]=sm;
        }
        sm=0;
        for(int i=n-1;i>=0;i--){
            sm+=nums[i];
            suff[i]=sm;
        }

        SparseTable st1(n,pref),st2(n,suff);
        ll ans=LLONG_MIN;
        for(int i=1;i<n-1;i++){
            int pidx=i;
            int qidx=i+stdec[i]-1;
            int lefidx = i-endinc[i]+1;

            ll psm= pref[i];
            ll qsm= suff[qidx];
            int rigidx=qidx+stinc[qidx]-1;
            if(lefidx<pidx and pidx<qidx and qidx<rigidx){
                // --- compute min prefix before left segment (pref index = l-1) ---
                ll minip = LLONG_MAX;
                int L1 = lefidx-1;
                int R1 = pidx-2;
                if(L1 <= R1){
                    int Lq = max(0, L1);
                    int Rq = min(n-1, R1);
                    if(Lq <= Rq) minip = st1.query(Lq, Rq);
                }
                if(lefidx==0) minip = min(minip, 0ll);

                // --- compute min suffix after right segment (suff index = r+1) ---
                ll miniq = LLONG_MAX;
                int L2 = qidx+2;
                int R2 = rigidx+1;
                if(L2 <= R2){
                    int Lq2 = max(0, L2);
                    int Rq2 = min(n-1, R2);
                    if(Lq2 <= Rq2) miniq = st2.query(Lq2, Rq2);
                    // if range includes index n (i.e. r+1 == n), include suff[n] == 0
                    if(R2 >= n) miniq = min(miniq, 0ll);
                }
                if(rigidx==n-1) miniq = min(miniq, 0ll);

                ll bwsm= pref[qidx-1]-pref[pidx];
                ll lefsm= psm-minip;
                ll rigsm= qsm-miniq;

                ll totalsm= lefsm+bwsm+rigsm;
                ans=max(ans,totalsm);
            }

        }

        return ans;
    }
};
