class Solution {
public:
    int totalWaviness(int num1, int num2) {
        string s1= to_string(num1);
        int ans=0;
        for(int i=num1;i<=num2;i++){
                string s= to_string(i);
            int m=s.length();
            for(int j=1;j<m-1;j++){
                    if(s[j]>s[j-1] and s[j]>s[j+1]){
                        ans++;
                    }
                    if(s[j]<s[j-1] and s[j]<s[j+1]) ans++;
            }

        }
        return ans;
    }
};