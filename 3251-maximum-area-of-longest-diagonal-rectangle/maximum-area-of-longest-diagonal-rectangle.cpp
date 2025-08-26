class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int n=dim.size();
        double max_dig=-1,area=-1;
        int ans=-1;
        int l,w;
        double d, a;
        for(int i=0;i<n;i++){
            l=dim[i][0];
            w=dim[i][1];
            d=(sqrt(1.0*pow(l,2)+1.0*pow(w,2)));
           // cout<<max_dig<<endl;
            if(d>1.0*max_dig){
                max_dig=d;
                area=l*w;
                ans=i;
            }
            else if(d==1.0*max_dig ){
                if(l*w>area){
                    area=l*w;
                }
            }
            
        }
        return (int)area;
    }
};