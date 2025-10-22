class Solution {
public:
    int longestBalanced(string s) {
        
        /*
        Cases:
        1) all a's b's c's
        2) (a,b) (bc) (a,c) if we get a third vairable clear the map..
        3) (a,b,c) {
            a[i]-a[j]==b[i]-b[j] and a[i]-a[j]== c[i]-c[j]
            a[i]-b[i]=a[j]-b[j]  and a[i]-c[i]=a[j]-c[j]
            {(a[j]-b[j],a[j]-c[j])}= i;
        }

        */
        int n=s.length();
        int ans=0;
        for(char c='a';c<='c';c++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(s[i]==c) cnt++;
                else {
                ans=max(ans,cnt);
                cnt=0;
                }
            }
            ans=max(ans,cnt);
        }
            // 1 2 1
        function<int(char , char )>f1=[&](char a, char b)->int{
            int diff=0;
            map<int,int>mp;
            mp[0]=-1;

            // aabcacc  -1
            // 1
            int tans=0;
            for(int i=0;i<n;i++){
                if(s[i]==a) diff++;
                else if(s[i]==b) diff--;
                else{
                map<int,int>tmp;
                 mp.swap(tmp);

                }


                if(mp.find(diff)!=mp.end()){
                    
                    tans=max(tans,i-mp[diff]);
                }
                if(mp.find(diff)==mp.end()) mp[diff]=i;
            }
            return tans;
        };

        function<int()>f=[&](){
            map<pair<int,int>,int>mp;
            mp[{0,0}]=-1;
            int cnta=0;
            int cntb=0;
            int cntc=0;
            int tans=0;
            for(int i=0;i<n;i++){
                if(s[i]=='a') cnta++;
                else if(s[i]=='b') cntb++;
                else cntc++;
                int diff1=(cnta-cntb);
                int diff2=(cnta-cntc);
                if(mp.find({diff1,diff2})!=mp.end()){
                    tans=max(tans,(i-mp[{diff1,diff2}]));
                }
                if(mp.find({diff1,diff2})==mp.end())
                mp[{diff1,diff2}]=i;
            }
            return tans;
        };

        //cout<<f1('a','b')<<" "<<f1('a','c')<<" "<<f1('b','c')<<" "<<f()<<endl;
        ans=max({ans,f1('a','b'),f1('a','c'),f1('b','c'),f()});
        return ans;
    }
};