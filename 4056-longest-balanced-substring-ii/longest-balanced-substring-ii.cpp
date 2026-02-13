class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
       for(char c='a';c<='c';c++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==c) cnt++;
            else cnt=0;
            ans=max(ans,cnt);
        }
       }

       // two variables appear the same  ab, ac, bc
       // whenever we get third variable not concerned, clear the map
       for(char c1='a';c1<='c';c1++){
        for(char c2=c1+1;c2<='c';c2++){
            map<int,int>mp;
            mp[0]=-1;
            int diff=0;
            for(int i=0;i<n;i++){
                if(s[i]==c1){
                    diff++;
                } 
                else if(s[i]==c2){
                    diff--;
                }
                else{
                    mp.clear();
                    mp[0]=i; // i-1 or i+1 maybe
                    diff=0;
                }
                if(s[i]==c1 || s[i]==c2){
                    if(mp.find(diff)!=mp.end()) ans=max(ans,i-mp[diff]);
                    else mp[diff]=i;
                }
            }
        }
       }

       /*

        pref[i]['a']-pref[j]['a']==pref[i]['b']

        p(i,a)-p(j,a) == p(i,b) - p(j,b) == p(i,c) - p(j,c)

        p(i,a)-p(i,b)== p(j,a)-p(j,b) and 
        p(i,b)-p(i,c)== p(j,b) - p(j,c)


       */

       map<pair<int,int>,int>mp;
       mp[{0,0}]=-1;
       int pa,pb,pc;
       pa=pb=pc=0;
       for(int i=0;i<n;i++){
        if(s[i]=='a') pa++;
        else if(s[i]=='b') pb++;
        else pc++;

        int d1= pa-pb;
        int d2= pb-pc;
        if(mp.find({d1,d2})!=mp.end()){
            ans=max(ans,i-mp[{d1,d2}]);
        }
        else mp[{d1,d2}]=i;
       }

       return ans;


    }
};