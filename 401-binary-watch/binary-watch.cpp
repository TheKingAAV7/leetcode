class Solution {
public:
    vector<string> readBinaryWatch(int k) {
        vector<int>v={8,4,2,1,32,16,8,4,2,1};
        vector<string>ans;
        for(int i=0;i<(1<<10);i++){
            if(__builtin_popcount(i)==k){
                int hrs=0, mins=0;
                for(int j=0;j<4;j++){
                 if((i>>j)&(1))
                 hrs+=v[j];
                }
                for(int j=4;j<10;j++){
                    if((i>>j)&1){
                        mins+=v[j];
                    }
                }
                if(hrs<12 and mins<60){
                string hours=to_string(hrs);
                string minutes;
                if(mins<10) minutes="0" + to_string(mins); 
                else
                 minutes= to_string(mins);
                string cur= hours+":"+minutes;
                ans.push_back(cur);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};