/*
Problem: We want to make the strings sorted with the operation given..
i.e Choose the minimum indices to delete
Observations:
1) For a column if everything is a(i) < a(i+1) we, stop..
2) Now, some indices will follow above condition some maynot 
i.e a(i)==a(i+1) or a(i)>a(i+1)
for the second case, we have no option , need to consider this index to answer


abc
bcd
bca
cxx
cyy

Shall we maintain a list of failing rows indices and then delete them gradually 
first index will never be a concern..
[1,2,3,4] -> [2,4]

*/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        set<int>rows;
        for(int i=1;i<n;i++) rows.insert(i);
        // for(int i:rows) cout<<i<<" ";
        // cout<<endl;

        int cnt=0;
        for(int j=0;j<m;j++){
            // check if all concerned indices are violating a[i-1]>a[i]
            bool violate=false;
            // cout<<j<<endl;
            // for(int i:rows) cout<<i<<" ";
            // cout<<endl;
            for(int idx:rows){
                if(strs[idx-1][j] > strs[idx][j]){
                    violate=true;
                    break;
                }
            }
            if(violate) {
                
                cnt++;
                continue;
            }
            //cout<<j<<endl;

            vector<int>toerase;
            for(int idx:rows){
                if(strs[idx-1][j]<strs[idx][j]){
                    toerase.push_back(idx);
                }
            }
            for(int ids:toerase) rows.erase(ids);

        }

        return cnt;

    }
};