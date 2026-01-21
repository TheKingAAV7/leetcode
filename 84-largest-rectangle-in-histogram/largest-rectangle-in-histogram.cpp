class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n= arr.size();
        stack<array<int,2>>st1,st2;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st1.empty() and arr[i]<=st1.top()[0]){
                cnt+=st1.top()[1];
                st1.pop();
            }
            ans[i]=cnt;
            st1.push({arr[i],cnt});
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st2.empty() and arr[i]<=st2.top()[0]){
                cnt+=st2.top()[1];
                st2.pop();
            }
            ans[i]+=(cnt);
            st2.push({arr[i],cnt});
        }

        // for(int i:ans) cout<<i<<" ";
        // cout<<endl;
        int fin=0;
        for(int i=0;i<n;i++){
            int count= ans[i]-1;
            fin= max(fin, count*arr[i]);
        }
        return fin;
    }
};