class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
       int n= arr.size();
       vector<int>pref(n),suff(n);
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
        mini= min(mini,arr[i]);
        pref[i]= mini;
       }
       int maxi= INT_MIN;
       for(int i=n-1;i>=0;i--){
        maxi=max(maxi,arr[i]);
        suff[i]=maxi;
       }
       for(int i=1;i<n-1;i++){
        if(pref[i-1]<arr[i] and arr[i]<suff[i+1]) return true;
       }
       return false;
    }
};