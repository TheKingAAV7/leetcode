class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        vector<int>pos;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(auto it:v){
         
            pos.push_back(it.second);
        }
      
        auto beg=0;
        
        int prev= v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].first-prev>limit){
               // cout<<i<<endl;
                auto end= min((int)pos.size(), i);
              
                sort(pos.begin()+beg,pos.begin()+end);
                
                prev=v[i].first;
                beg=i;
           
     
            }
            else{
                prev=v[i].first;
            }
            
        }
       
        sort(pos.begin()+beg,pos.end());
        vector<int>ans;

        // for(auto it:v){
        //     cout<<"("<<it.first<<" "<<it.second<<") ";
        // }
        // cout<<endl;
        // for(auto it:pos){
        //     cout<<it<<"      ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            nums[pos[i]]=v[i].first;
        }

        
        return nums;

    }
};