class Solution {
public:
    bool checkInclusion(string t, string s) {
        unordered_map<char, int>mp,mp1;
        for(char c: t ) mp[c]++;
        int k =t.length();
        int n=s.length();
        if(k>n) return false;
        for(int i=0;i<k;i++){
            mp1[s[i]]++;
        }
        int i=0;
        if(mp==mp1) return true;

        for(int j=k;j<n;j++){
            mp1[s[i]]--;
            if(mp1[s[i]]==0) mp1.erase(s[i]);
            mp1[s[j]]++;
            if(mp1==mp) return true;
            i++;   
        }

        return false;
        


    }
};