class Solution {
public:
    int maximumGroups(vector<int>& grades) {
       // sum[i]<sum[i+1]
       // no[i]<no[i+1]    
       int ans=1;
       sort(grades.begin(),grades.end());
       int n=grades.size();

        int prev=grades[0];
        int cnt=1;
        int gps=1; // 3 5 6 7 10 12
        int sm=0;
        int cur_cnt=0;
        for(int i=1;i<n;i++){
            sm+=grades[i];
            cur_cnt++;
            if(sm>prev and cur_cnt>cnt){
              //  cout<<i<<endl;
                gps++;
                cnt=cur_cnt;
                prev=sm;
                cur_cnt=0;
                sm=0;
            }
        }
       // if(sm>prev and cur_cnt>cnt) gps++;
       
       return gps;
    }
};