class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
      map<int,int>mp;
      int n=cards.size();
      int ans=n+1;
      int l=0;
      for(int i=0;i<n;i++){
        mp[cards[i]]++;
        while(mp[cards[i]]>1){
           // cout<<i<<endl;
            ans=min(ans,i-l+1);
            mp[cards[l]]--;
            if(mp[cards[l]]==0) mp.erase(cards[l]);
            l++;
        }
      }
      return ans==(n+1)?-1:ans;
    }
};