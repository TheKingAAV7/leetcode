class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        vector<int> a1(26,0),a2(26,0);
        vector<int>b1(26,0),b2(26,0);
        for(int i=0;i<n;i++){
            if(i%2==0){
             a1[s1[i]-'a']++;
             a2[s2[i]-'a']++;
            }
            else{
             b1[s1[i]-'a']++;
             b2[s2[i]-'a']++;
            }
        }
       
        return a1==a2 and b1==b2;
    }
};