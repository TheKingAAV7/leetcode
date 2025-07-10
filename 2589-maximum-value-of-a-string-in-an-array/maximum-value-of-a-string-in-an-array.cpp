class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=-1;
        for(auto it:strs){
            bool anms=true;
            int num=0;
            for(auto c:it){
                if(c>='a' and c<='z') {
                     anms=false;
                    break;
                }
                else num=num*10+(c-'0');
            }

            int val=(anms)?num:it.length();
            
            ans=max(ans,val);
        }
        return ans;
    }
};