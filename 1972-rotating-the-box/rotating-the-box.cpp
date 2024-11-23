class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
       int m=box[0].size(),n=box.size();
       for(int i=0;i<n;i++){
        
        for(int j=m-1;j>=0;j--){
          int b=j+1;
          int idx=-1;
          if(box[i][j]=='#'){
            while(b<m and box[i][b]=='.'){
                idx=b;
                b++;
            }
            if(idx!=-1){
                cout<<idx<<endl;
                box[i][idx]='#';
                box[i][j]='.';
            }
          }  
        }
       }
    int rows = box.size();
    int cols = box[0].size();

    vector<vector<char>> rotated(cols, vector<char>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotated[j][rows - 1 - i] = box[i][j];
        }
    }

    return rotated;
      
    }
};