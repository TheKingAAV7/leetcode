class Solution {  //  (0 2) (2 4)  (4 6)
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>ver,hor;
        
        for(auto it:rectangles){
            int y1=it[1];
            int y2=it[3];
            ver.push_back({y1,y2});
        }
        for(auto it:rectangles){
            hor.push_back({it[0],it[2]});
        }
        auto f=[&](vector<pair<int,int>>&inter)->int{
            
            int m=inter.size();
            vector<pair<int,int>>tmp;
            tmp.push_back(inter[0]);
            for(int i=1;i<m;i++){
                if(inter[i].first<tmp.back().second){
                    tmp.back().second=max(tmp.back().second,inter[i].second);
                }
                else{
                    tmp.push_back(inter[i]);
                }
            }
           
            return tmp.size();
           
         

        };
        sort(ver.begin(),ver.end());
        sort(hor.begin(),hor.end());
        
        if(f(ver)>=3 || f(hor)>=3)
        return true;
        return false;
    }
};