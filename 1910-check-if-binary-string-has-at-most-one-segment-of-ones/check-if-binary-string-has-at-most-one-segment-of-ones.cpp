class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0;
        int cur=0;
        char prev='1';
        for(char &c: s){
            if(c=='1'){
            if(prev=='1'){
                cur++;
            }
            else{
             cnt++;
             cur=0;
            }
            }
            else{
                if(prev=='1') cnt++;
                cur=0;
            }
            prev=c;
        }
        cout<<cnt<<endl;
        if(cur>0) cnt++;

        return cnt<=1;
    }
};