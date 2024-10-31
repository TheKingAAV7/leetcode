class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    
        int a=max(rec1[0],rec1[2]);
        int b=max(rec2[0],rec2[2]);
        int c=min(rec1[0],rec1[2]);
        int d=min(rec2[0],rec2[2]);

        int e=max(rec1[1],rec1[3]);
        int f=max(rec2[1],rec2[3]);
        int g=min(rec1[1],rec1[3]);
        int h=min(rec2[1],rec2[3]);


        if(a<=d || b<=c){
            return false;
        }
        else{
            if(e<=h || f<=g ){
                return false;
            }
            else{
                return true;
            }
        }

        return false;
    }
};