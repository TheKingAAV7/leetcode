class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=0;
        int ans =0;
        char prev='-';
        for(int i=0;i<word.size();i++){
            if(word[i]==prev){
                cnt++;
            }
            else{
                if(cnt==0){
                    prev=word[i];
                    cnt=1;
                    continue;
                }
                ans+=(cnt-1);

                prev=word[i];
                cnt=1;
            }
        }
        ans+=(cnt-1);
        return ans+1;
    }
};