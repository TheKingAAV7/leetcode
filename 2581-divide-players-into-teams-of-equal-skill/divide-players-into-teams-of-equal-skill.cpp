class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=1;
        sort(begin(skill),end(skill));
        int i=0,j=skill.size()-1;
        ans=skill[i]*skill[j];
        long long sm=skill[i++] + skill[j--];

        while(i<j){
            if(skill[i]+skill[j]!=sm) return -1;
            ans+=(skill[i]*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};