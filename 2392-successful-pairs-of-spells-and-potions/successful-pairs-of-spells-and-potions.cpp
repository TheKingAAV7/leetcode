class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //int ans=0;
        int n=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i:spells){
            long long x=ceil((success*1.0)/(i*1.0));
            auto it=lower_bound(potions.begin(),potions.end(),x);
            int pos=(it-potions.begin());
            if(it!=potions.end()){
                ans.push_back((n-pos));
            }
            else ans.push_back(0);
        }
        return ans;
    }
};