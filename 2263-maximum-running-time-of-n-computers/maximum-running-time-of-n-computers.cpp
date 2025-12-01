class Solution {
public:
    long long maxRunTime(int n1, vector<int>& bat) {
        // COpied
        sort(bat.begin(),bat.end());
        long long sm = accumulate(bat.begin(),bat.end(),0ll);
        int k=0;
        int n= bat.size();
        while(bat[n-1-k]> (sm/(n1-k))){
            sm-= bat[n-1-k];
            k++;
        }
        return sm/(n1-k);
    }
};