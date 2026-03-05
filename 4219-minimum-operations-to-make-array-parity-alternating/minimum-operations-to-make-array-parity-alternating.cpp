class Solution {
public:

   /*
    1  0  0  0  1  0  1
    a1 a2 a3 a4 a5 a6 a7

    There will be fixed elements only that need to change
    -> True
         
     0 0 1 1 0
     0 1 0 1 0
    minimize max(nums)- min(nums)
    let st= {i1, i2, i3} be the indices to be changed
    if maxi>0 and mini<0    still same
    if maxi<0 and mini<0 -> increase maxi
    -3 -6 = 3     -4 -6   -2 -6
    
    if maxi is fully occupied by st
    maxi--
    other wise if maxi will be retained
    still decrease


    
   */
    vector<int> makeParityAlternating(vector<int>& nums) {
        
        int n=nums.size();
        int mx= *max_element(nums.begin(),nums.end());
        int mn= *min_element(nums.begin(),nums.end());

        auto f=[&](int xs)->vector<int>{
            int start= xs;
            int cost=0;
            vector<int>v(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                int val= abs(v[i]);
                if(val%2 != xs){
                    cost++;
                    if(v[i]==mx) v[i]--;
                    else if(v[i]==mn) v[i]++;              
                }
                xs=!xs;
            }
            int diff= *max_element(v.begin(),v.end()) - *min_element(v.begin(),v.end());
            return {cost,diff};
        };

        vector<int> a1= f(0);
        vector<int> a2= f(1);
        if(a1[0]<a2[0]) return a1;
        if(a2[0]<a1[0]) return a2;
        return {a1[0],min(a1[1],a2[1])};
    }
};