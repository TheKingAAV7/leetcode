class Solution {
public:
    int minNumberOperations(vector<int>& arr) {
/*
    Basically, WE will find ranges for all the elements

    there can be multiple ranges for each element
     e.g 4-> (0,2) (4,5)
     map<int,vector<array<int,2>>>mp;
     now for each element in map sorted, just use sweepline, to determine, what's the 
     effective value of current element

*/
    int ans=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++){
        ans+=max(0,arr[i]-arr[i-1]);
    }
    return ans;
    }
};