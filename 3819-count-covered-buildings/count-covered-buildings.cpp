class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& arr) {
        int N= arr.size();
        unordered_map<int,array<int,2>>row,colo;
        int cnt=0;

        for(int i=0;i<N;i++){
            int cur_row= arr[i][0];
            int cur_col= arr[i][1];
            if(row.find(cur_row)==row.end()){
              
                row[cur_row]={cur_col,cur_col};
            }
            else{
               
                row[cur_row][0]= min(row[cur_row][0],cur_col);
                row[cur_row][1]= max(row[cur_row][1],cur_col);
              //  cout<<cur_row<<" s"<<cur_col<<endl;
            }
            if(colo.find(cur_col)==colo.end()){
                colo[cur_col]={cur_row,cur_row};
            }
            else{
                colo[cur_col][0]= min(colo[cur_col][0],cur_row);
                colo[cur_col][1]= max(colo[cur_col][1],cur_row);
            }
        }
        // for(auto it:row){
        //     cout<<it.first<<" "<<it.second[0]<<" "<<it.second[1]<<endl;
        // }
        // cout<<endl;
        // for(auto it:colo){
        //     cout<<it.first<<" "<<it.second[0]<<" "<<it.second[1]<<endl;
        // }
        for(auto it:arr){
            int ro= it[0];
            int col= it[1];
            if(row[ro][0]<col and col<row[ro][1] and colo[col][0]<ro and ro<colo[col][1]) cnt++;
        }
        return cnt;
    }
};