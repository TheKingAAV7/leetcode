class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // 5 3 3 33 3 3 3 3 3 3 3 33 3 3 3 3 3 3 3 3..

        /*

           [x-limit ,x+limit]
         
         (3,1) (3,2)... (5,0)

         [3, 3, 3]


         (1,0) (5,1) (3,2) (9,3)  (8,4)

         (1,0) (3,2) (5,1) (8,4) (9,3)

         [1, 3, 5]
         [8, 9]
       
        */
        int n= nums.size();

        vector<pair<int,int>> v(n);
        for(int i=0;i<n;++i){
            v[i] = {nums[i],i};
        }
        sort(v.begin(),v.end());

        vector<int>result(n);
        // vector<vector<int>>groups;

        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n and (v[j].first - v[j-1].first <= limit)) {
                j++;
            }   

            vector<int>index;
            for(int x=i;x<j;++x){
                index.push_back(v[x].second);     
            }
            sort(index.begin(),index.end());

            // {v1,i1} {v2,i2} {v3,i3} {v4,i4} ... 
            for(int x=i; x<j; ++x){
                result[index[x-i]] = v[x].first;
            }

            i=j;
        }
        
        return result;
    }
};