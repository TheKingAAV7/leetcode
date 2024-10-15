class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);

    int pos1=0,pos2=s.length()-1;
    int n= s.length();
    while(pos1<n and s.length() and s[pos1]=='0'){
    pos1++;
    }
    
    long long ans=0;
    while(pos2>=0 and s[pos2]=='1'){
        pos2--;
    }
    if(pos1>pos2){
        return 0;
    }
    int zero=pos2;
    for(int i=pos2;i>=pos1;i--){
       if(s[i]=='1'){
        ans+=(zero-i);
        zero--;
       }
    }

   return ans;

    }
};