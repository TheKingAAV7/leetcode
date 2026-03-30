class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        string a1,a2;
        string b1,b2;
        for(int i=0;i<n;i++){
            if(i%2==0){
             a1.push_back(s1[i]);
             a2.push_back(s2[i]);
            }
            else{
             b1.push_back(s1[i]);
             b2.push_back(s2[i]);
            }
        }
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        sort(b1.begin(),b1.end());
        sort(b2.begin(),b2.end());
        return a1==a2 and b1==b2;
    }
};