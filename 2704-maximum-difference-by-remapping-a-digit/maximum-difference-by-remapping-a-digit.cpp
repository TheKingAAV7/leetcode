class Solution {
public:
    int minMaxDifference(int num) {
        string tmp=to_string(num);
        int n=tmp.length();
        int pos=0;
        while(pos<n and tmp[pos]=='9') pos++;
        if(pos==n){
            return num;
        }
        string maxi=tmp;
        string mini=tmp;
        for(int i=0;i<n;i++){
            if(maxi[i]==tmp[pos]) maxi[i]='9';
            if(mini[i]==tmp[0]) mini[i]='0';
        }
        int mx=stoi(maxi);
        int mn=stoi(mini);
        return mx-mn;

    }
};