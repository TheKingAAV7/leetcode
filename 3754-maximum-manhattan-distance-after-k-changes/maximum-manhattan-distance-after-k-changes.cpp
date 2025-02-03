class Solution {
public:
    int maxDistance(string s, int k) {

        vector<pair<char,char>>v={{'N','E'},{'N','W'},{'S','E'},{'S','W'}};
        int ans=0;
        int n=s.length();
        for(auto it:v){
            string tmp=s;
            int pos=0;
            int tk=k;
            while(pos<n and tk>0){
                if(tmp[pos]==it.first){
                    if(it.first=='N') tmp[pos]='S';
                    else tmp[pos]='N';
                    tk--;
                }
                if(tmp[pos]==it.second){
                    if(it.second=='E') tmp[pos]='W';
                    else tmp[pos]='E';
                    tk--;
                }
                pos++;
            }
            int x=0,y=0;
            for(auto c:tmp){
                if(c=='N') y++;
                else if(c=='E') x++;
                else if(c=='W')x--;
                else y--;
                ans=max(ans,abs(x)+abs(y));
            }
        }
        return ans;
    }
};