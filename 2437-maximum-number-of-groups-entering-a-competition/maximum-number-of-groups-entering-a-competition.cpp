class Solution {
public:
    int maximumGroups(vector<int>& grades) {
       // sum[i]<sum[i+1]
       // no[i]<no[i+1]    
       int ans=1;
       int n=grades.size();
       auto f=[&](int k)->bool{
        int prev=grades[0];
        int cnt=1;
        int gps=1;
        int sm=0;
        int cur_cnt=0;
        for(int i=1;i<n;i++){
            sm+=grades[i];
            cur_cnt++;
            if(sm>prev and cur_cnt>cnt){
                gps++;
                cnt=cur_cnt;
                prev=sm;
                cur_cnt=0;
                sm=0;
            }
        }
        return gps>=k;

       };
       
       sort(grades.begin(),grades.end());
       int lo=1,hi=n;
       while(lo<=hi){
        int mid=(lo+hi)>>1;
        if(f(mid)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
       }
       
       return ans;
       
    }
};