class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxi=0;
        double lo=INT_MAX;;
        for(auto &it:squares){
             maxi= max(maxi,(double)(it[1] + it[2]));
             lo= min(lo,(double)(it[1]));
        }
        double aux=1e-5;
        double hi= maxi;
        double ans=-1;
        auto f=[&](double mid)->bool{
         
            double areaup=0;
            double areadown= 0;
            for(auto &it:squares){
                double x= it[0];
                double y= it[1];
                double len= it[2];
                if(y>=mid){
                    areaup+=(len*len);
                }
                else if(mid>=(y+len)){
                    areadown+=(len*len);
                }
                else{
                    double dlen= (mid-y);
                    double total= len*len;
                    double darea= dlen*len;
                    double uarea= total-darea;
                    areaup+=uarea;
                    areadown+= darea;
                }
            }
            
           // cout<<mid<<" "<<areaup<<" "<<areadown<<endl;
            return areaup<=areadown;
            
        };
        while(hi-lo>aux){
            double mid=(lo+hi)/2.0;

            if(f(mid)){
                ans= mid;
                hi= mid;
            }   
            else lo= mid;
        }
        return ans;
    }
};