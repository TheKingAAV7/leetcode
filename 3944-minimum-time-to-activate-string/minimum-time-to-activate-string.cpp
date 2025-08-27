class Solution {
public:
    int minTime(string s, vector<int>& od, int k) {
        int n=od.size();
        int m=s.length();
        set<int>st;
        long long cnt=0;
        st.insert(od[0]);
        long long lefti=(od[0]+1);
         long long righti=(m-od[0]);
        cnt+=(lefti*righti);
        if(cnt>=k) return 0;
        
        for(int i=1;i<n;i++){
            // left and right closest
            auto it=st.lower_bound(od[i]);
            if(it==st.end()){
                it--;
                int leftidx=(*it);
                int lefcnt=od[i]-leftidx;
                int rigcnt=m-od[i];
                cnt+=(lefcnt*rigcnt);
                if(cnt>=k) return i;
            }
            else if(it==st.begin()){
                
                int rigidx=(*it);
                int rigcnt=rigidx-od[i];
                int lefcnt=od[i]+1;
                cnt+=(lefcnt*rigcnt);
                if(i==2){
                    cout<<lefcnt<<" "<<rigcnt<<endl;
                }
                if(cnt>=k) return i;
            }
            else{
               int rigidx=(*it);
               it--;
               int lefidx=(*it); 
               int lefcnt=od[i]-lefidx;
               int rigcnt=rigidx-od[i];
               cnt+=(lefcnt*rigcnt);
                if(cnt>=k) return i;
            }
            st.insert(od[i]);
          //  cout<<cnt<<endl;

        }
        return -1;
    }
};