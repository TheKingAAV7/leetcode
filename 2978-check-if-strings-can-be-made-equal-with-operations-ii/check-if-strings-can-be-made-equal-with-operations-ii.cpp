class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        array<int,26> a1={0};
        array<int,26>a2={0};
        array<int,26>b1={0};
        array<int,26>b2={0};
        // vector<int>b1(26,0),b2(26,0);
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
        
        for(int i:b1) cout<<i<<" ";
        cout<<endl;
        for(int i:b2) cout<<i<<" ";
        cout<<endl;
        return a1==a2 and b1==b2;
    }
};