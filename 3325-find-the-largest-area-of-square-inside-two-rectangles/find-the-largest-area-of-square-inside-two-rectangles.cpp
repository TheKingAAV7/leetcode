#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

/*
For each pair of rectangles, find the common area and then find the maximum square that can fit into it..
which will be min(l,r)^2

*/
    long long largestSquareArea(vector<vector<int>>& bLeft, vector<vector<int>>& tRight) {
        int n=bLeft.size();

        long long ans=0;


        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // these two rectangles will overlap if and only if bottom left of the right one is inside the left one
                // Or the bottom right corner of the right one is  inside left rectangle..

                int rec1blx= bLeft[i][0];
                int rec1bly= bLeft[i][1];
                int rec1tlx= tRight[i][0];
                int rec1tly= tRight[i][1];
                int rec1brx= tRight[i][0];
                int rec1bry= rec1bly;
                int rec1trx= tRight[i][0];
                int rec1try= tRight[i][1];


                int rec2blx= bLeft[j][0];
                int rec2bly= bLeft[j][1];
                int rec2tlx= tRight[j][0];
                int rec2tly= tRight[j][1];
                int rec2brx= tRight[j][0];
                int rec2bry= rec2bly;
                int rec2trx= tRight[j][0];
                int rec2try= tRight[j][1];

                int ix1 = max(rec1blx, rec2blx);   // left
                int iy1 = max(rec1bly, rec2bly);   // bottom
                int ix2 = min(rec1brx, rec2brx);   // right
                int iy2 = min(rec1try, rec2try);   // top

                if (ix1 < ix2 && iy1 < iy2) {
                    long long side = 1LL * min(ix2 - ix1, iy2 - iy1);
                    ans = max(ans, side * side);
                }

            }
            
        }
        return ans;
    }
};
