class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int es) {
        double ans=0;
        double n= classes.size();
        priority_queue<tuple<double,double, double>>pq;
        for(int i=0;i<n;i++){
            double tmp=(double(classes[i][0])+1)/(double(classes[i][1])+1);
            double prev=(double(classes[i][0]))/(double(classes[i][1]));
            pq.push(make_tuple((tmp-prev),double(classes[i][0])+1,double(classes[i][1])+1));
        }
        // while(!pq.empty()){
        //     auto [x,y,z]=pq.top();
        //     cout<<x<<" "<<y<<" "<<z<<endl;
        //     pq.pop();
        // }
        while(es--){
         auto [x,y,z]= pq.top();
         pq.pop();
         double tmp=(double(y)+1)/(double(z)+1);
            double prev=(double(y))/(double(z));
            pq.push(make_tuple((tmp-prev),double(y)+1,double(z)+1));
        }  
        while(!pq.empty()){
            auto [x,y,z]=pq.top();
             double prev=(double(y)-1)/(double(z)-1);
            pq.pop();
            ans+=prev;
        }
        return ans/double(n);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();