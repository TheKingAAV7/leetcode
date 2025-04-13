class Solution {
public:
     int longestSubstring(string s, int k) {
     int i=0;
     int j = 0;
    int n = s.length();
    unordered_map<char,int> m;
    int count =0;
    int d = 0;
    while(i<n && j<n){
        m[s[j]]++;
        if(m[s[j]]==k){
            count++;
        }
        if(count == m.size()){
            d = max(d,j-i+1);
            // cout<<d<<" ";
        }
        
        j++;
        if(j==n){
            m.clear();
            i++;
            j=i;
            count=0;
        }
        
    }
    return d;
}
};