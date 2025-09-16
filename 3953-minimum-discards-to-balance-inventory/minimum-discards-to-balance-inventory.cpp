class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        int n=arr.size();
        map<int,int>mp;
        vector<int>vis(n,0);
        int ans=0;
        int l=0;
        for(int i=0;i<n;i++){

            if((i-l+1)>w){
                //cout<<i<<endl;
               if(vis[l]==0){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
               }
               l++;
            }

            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=1;
                //cout<<i<<endl;
            }
            else{
                if(mp[arr[i]]+1 > m){
                    //cout<<i<<endl;
                    vis[i]=1;
                    ans++;
                }
                else{
                    mp[arr[i]]++;
                }
            }

            
        }
        return ans;
        
    }
};