class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        vector<int>pos;
        string cp=s;
        string str="AEIOUaeiou";
        for(int i=0;i<n;i++){
            if(str.find(s[i])!=string::npos) pos.push_back(i);
        }
        vector<int>tmp(pos.begin(),pos.end());
        int cnt=0;
        sort(pos.begin(),pos.end(),[&](int a, int b)->bool{
            cnt++;
            return s[a]<s[b];
        });
        for(int i:pos) cout<<i<<" ";
        cout<<endl;
        cout<<cnt<<endl;
        for(int i=0;i<tmp.size();i++){
            s[tmp[i]]=cp[pos[i]];
        }
        return s;


        


    }
};