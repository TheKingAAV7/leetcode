class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        int cnt=0;
        int cntr=0;
        if(boxes[0]=='1') cnt++;
        if(boxes[n-1]=='1') cntr++;
        vector<int>pref(n,0),suff(n,0);

        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+cnt;
            suff[n-i-1]=suff[n-i]+cntr;
            if(boxes[n-i-1]=='1') cntr++;
            if(boxes[i]=='1') cnt++;   
        }
       
        
        // for(int i=n-2;i>=0;i--){
        //     suff[i]=suff[i+1]+cnt;
        //     if(boxes[i]=='1') cnt++;
        // }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(pref[i]+suff[i]);
        }
        return ans;
    }
};