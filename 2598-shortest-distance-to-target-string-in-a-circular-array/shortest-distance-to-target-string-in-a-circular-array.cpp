class Solution {
public:
    int closestTarget(vector<string>& words, string target, int sI) {
        int n=words.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int a1= abs(sI-i);
                int a2= n-a1;
                ans= min({ans, a1, a2});
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};