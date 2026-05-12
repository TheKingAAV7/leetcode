#define ll long long
class Solution {
public:
    int minimumEffort(vector<vector<int>>& arr) {
        /*


        which one to pick first?

        if there's no minimum,
        always in the decreasing order

        i.e for same minimum
        do it in decreasing order

        for different one?

        decreasing order of difference?
        

        5 10   6 11

        5     16  11+

        1 5   2 5  3 5  4 5 

        6 10    2 2


        12+2+

        */

        int n= arr.size();

        sort(arr.begin(),arr.end(),[&](vector<int>&a,vector<int>&b)->bool{
            ll d1= a[1]-a[0];
            ll d2= b[1]-b[0];
            return d1>d2;
        });
        ll ans= arr[0][1];
        ll cur= arr[0][1]-arr[0][0];

        // for(auto it:arr) cout<<it[0]<<" "<<it[1]<<endl;
        for(int i=1;i<n;i++){
            ll mini= arr[i][1];
            ll amt= arr[i][0];
            if(cur>=mini){
                cur-=amt;
            }
            else{
                ans+=(mini-cur);
                cur= mini-amt;
            }
        }
        return (int)ans;

        

        
    }
};