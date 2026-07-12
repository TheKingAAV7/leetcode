class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st(arr.begin(),arr.end());
        map<int,int>mp;
        int pos=1;
        for(int i:st){
            mp[i]=pos++;
        }

        for(int &i:arr) i=mp[i];
        return arr;
    }
};