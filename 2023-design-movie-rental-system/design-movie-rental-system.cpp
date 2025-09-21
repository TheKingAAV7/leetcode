class MovieRentingSystem {
public:
// movie-> (prices,shops)
// shops->(movies,prices)
// set -> (prices,movies,shops)
// dropped->(shops,movies,prices);
    unordered_map<int,set<array<int,2>>> mov, shop;
    set<array<int,3>> st, dropped;
    set<array<int,3>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& arr) {
        for(auto it:arr){
            int sh=it[0];
            int m=it[1];
            int p=it[2];
            //if(m==1) cout<<p<<"s "<<sh<<endl;
            mov[m].insert({p,sh});
            shop[sh].insert({m,p});
            st.insert({p,m,sh});
        }
    }

    vector<int> search(int movie) {
           auto it_map = mov.find(movie);
    vector<int> ans;
    if (it_map == mov.end() || it_map->second.empty()) return ans;

    auto &s = it_map->second; 
    int cnt = 0;
    for (auto &it : s) {
        ans.push_back(it[1]); 
        if (++cnt == 5) break;
    }
    return ans;
}
    void rent(int sho, int movie) {
        // remove movie from the shop
       // for(auto it:st) cout<<it[0]<<" pr"<<it[1]<<" pr"<<it[2]<<endl;
       // cout<<endl;
        array<int,2> x={movie,-1};
        auto it=shop[sho].lower_bound(x);

        if(it!=shop[sho].end()){
            int pr= (*it)[1];
          //  cout<<movie<<" "<<sho<<"ff "<<pr<<endl;
            shop[sho].erase(it);
            array<int,2> x1={pr,sho};
            auto it1=mov[movie].find(x1);
            if(it1!=mov[movie].end()){
              // cout<<(*it1)[0]<<" "<<(*it1)[1]<<endl;
                mov[movie].erase(it1);

            }
            array<int,3> x2={pr,movie,sho};
           // cout<<pr<<" "<<movie<<" "<<sho<<endl;
            auto itl=st.find(x2);
            if(itl!=st.end()){

             st.erase(itl);
            dropped.insert({sho,movie,pr});
            rented.insert({pr, sho, movie});
            }
        }
        // for(auto it:st) cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        // cout<<endl;
        return;
    }

    void drop(int sho, int movie) {
        array<int,3>x={sho,movie,-1};
        auto it=dropped.lower_bound(x);
        if(it!=dropped.end()){
            auto tmp= *it;
            dropped.erase(it);
            int pr= tmp[2];
            auto rit = rented.find({pr, sho, movie});
            if (rit != rented.end()) rented.erase(rit);
            mov[movie].insert({pr,sho});
            shop[sho].insert({movie,pr});
            st.insert({pr,movie,sho});
        }
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (auto &it : rented) { // it == {price, shop, movie}
            ans.push_back({ it[1], it[2] });
            if (++cnt == 5) break;
        }
        return ans;
    }
};
