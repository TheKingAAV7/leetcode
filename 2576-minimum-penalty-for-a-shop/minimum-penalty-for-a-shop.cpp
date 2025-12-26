class Solution {
public:
    int bestClosingTime(string customers) {
        // lef= N , rig=Y
        int sz= customers.size();
        int n,y;
        n=y=0;
        for(int i=0;i<sz;i++){
            if(customers[i]=='N') n++;
            else y++;
        }
        int curpenalty=0;
        int idx=0;
        int curN, curY;
        curN=curY=0;
        int minpenalty= INT_MAX;

      
        for(int i=0;i<sz;i++){
            int rigy= y-curY;
            int lefn= curN;
            curpenalty= rigy+lefn;
            //cout<<i<<" "<<curpenalty<<endl;
            if(curpenalty<minpenalty){
                minpenalty=curpenalty;
                idx=i;
            }
            if(customers[i]=='Y') curY++;
            else curN++;
        }
        if(n<minpenalty){
            idx=sz;
        }

        return idx;

    }
};