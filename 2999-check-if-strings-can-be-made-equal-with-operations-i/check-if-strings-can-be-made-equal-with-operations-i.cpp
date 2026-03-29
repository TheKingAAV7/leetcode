class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        string a= string()+s1[0]+s1[2];
        string b= string()+s2[0]+s2[2];
        string a1= string()+s1[1]+s1[3];
        string b1= string()+s2[1]+s2[3];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(a1.begin(),a1.end());
        sort(b1.begin(),b1.end());
        return a1==b1 and a==b;
        
    }
};