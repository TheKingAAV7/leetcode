class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        hFences.push_back(m);
        reverse(hFences.begin(),hFences.end());
        hFences.push_back(1);
        reverse(hFences.begin(),hFences.end());
        
        vFences.push_back(n);
        reverse(vFences.begin(),vFences.end());
        vFences.push_back(1);
        reverse(vFences.begin(),vFences.end());

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        int SizeH= hFences.size();
        int SizeV= vFences.size();


        // find the maximum difference between two elements, which is common in both..
        map<int,int>HDiff,VDiff;
        for(int i=0;i<SizeH;i++){
            for(int j=i+1;j<SizeH;j++){
                int diff= hFences[j]-hFences[i];
                HDiff[diff]=1;
            }
        }

        
         long long ans=-1;
         int MOD=1e9+7;
        for(int i=0;i<SizeV;i++){
            for(int j=i+1;j<SizeV;j++){
                int diff= vFences[j]-vFences[i];
                if(HDiff.find(diff)!=HDiff.end()){
                     long long Cur = 1ll * diff * diff;
                      if(Cur>ans) ans=Cur;
                }
            }
        }
        
        //
        // int MaxDiff= min(m-1,n-1);
        // for(int d=1;d<=MaxDiff;d++){
        //     if(HDiff.find(d)!=HDiff.end() and VDiff.find(d)!=VDiff.end()){
               
        //     }
        // }
        if(ans==-1) return -1;
        return (int)(ans%MOD);

    }
};