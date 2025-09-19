class Spreadsheet {
public:
    vector<vector<int>>v;
    int f1(string &s){
        int i=0;
        int row=0;
        int col=s[i]-'A';
        i++;
        while(i<s.size()){
            row=row*10+(s[i]-'0');
            i++;
        }
        return v[row-1][col];
    }
    int f2(string &s){
        int i=0;
        int num=0;
        while(i<s.size()){
            num=num*10+(s[i]-'0');
            i++;
        }
        return num;
    }
    
   
    Spreadsheet(int rows) {
        v.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        char a=cell[0];
        int i=1;
        int num=0;
        while(i<cell.size()){
            num=num*10+(cell[i]-'0');
            i++;
        }
        int col=a-65;
        v[num-1][col]=value;
    }
    
    void resetCell(string cell) {
           char a=cell[0];
        int i=1;
        int num=0;
        while(i<cell.size()){
            num=num*10+(cell[i]-'0');
            i++;
        }
        int col=a-65;
        v[num-1][col]=0;
    }
    
    int getValue(string form) {
       string a="",b="";
       int n=form.length();
       bool f=false;
       for(int i=0;i<n;i++){
        if(form[i]=='+'){
            f=true;
            continue;
        }

        if(!f){
             if(form[i]!='=') a.push_back(form[i]);
            
        }
        else {
            b.push_back(form[i]);
           
        }
       }
       int a1=0,b1=0;
      // cout<<a<<" "<<b<<endl;
       if(a[0]>='0' and a[0]<='9') a1=f2(a);
       else a1=f1(a);

       if(b[0]>='0' and b[0]<='9') b1=f2(b);
       else b1=f1(b);
       
       return a1+b1;
       
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */