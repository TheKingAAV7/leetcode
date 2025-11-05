#define ll long long
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        /*

        1) Count frequency of all elements of  k length subarrays -> map

        2) Keep only top x most frequent elements bigger one first..  -> map<freq,vector<ele>> (maybe)
        3) Sum  - pending

        Observations:
           while shifting the window, what will happen?

           1) New element can be added
           2) no. of unique decreases, stays the same.

           the problem is SUM

           1) we are removing an element
            so, first check, if this element was part of topx
            i) if not, ignore..
            ii) if yes -> only one occurence will be decreased.. 

          2) Adding at last
             i) increases freq
             ii) check if this can become part of topx


             1 1 2 2 3 4 2    (2,3)  (1,4) (1,3) (1,1)
                              (2,3)       -> 6- 2 + 2
                    

        */

        int n=nums.size();

        map<int,int>mp;
        set<array<int,2>,greater<array<int,2>>>topx;
        set<array<int,2>,greater<array<int,2>>>tobe;
        vector<ll>ans;

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            tobe.insert({it.second,it.first});
        }

        
        // insert topx
        long long sm=0;
        int tmpx=x;
       // for(auto it:tobe) cout<<it[0]<<" "<<it[1]<<endl;
        while(!tobe.empty() and ((int)topx.size())< x){
            auto cur= *tobe.begin();
            topx.insert(cur);
            sm+= (1ll* cur[0]*cur[1]);
            tobe.erase(tobe.begin());
        }
        ans.push_back(sm);

        for(int i=k;i<n;i++){
            int rmele= nums[i-k];
            int freqrm= mp[nums[i-k]];

            mp[rmele]--;
            if(mp[rmele]==0) mp.erase(rmele);
            // check if it's in topx 
            array<int,2> tof= {freqrm,rmele};
            auto it= topx.find(tof);
            if(it!=topx.end()){
                //delete this
                sm-=(1ll*rmele*freqrm);
                topx.erase(it);

                // decrease freq and insert in tobe
                freqrm--;
                if(freqrm>0) tobe.insert({freqrm,rmele});

                int newele= nums[i];
                int newfreq= mp[nums[i]];
                mp[nums[i]]++;

                array<int,2> nele={newfreq,newele};
                auto it1= topx.find(nele);
                if(it1!=topx.end()){
                    topx.erase(it1);
                    sm+= newele;
                    topx.insert({newfreq+1,newele});
                }
                else{
                    auto it2= tobe.find(nele);
                    if(it2!=tobe.end()) tobe.erase(it2);
                    tobe.insert({newfreq+1,newele});

                }

                while(!tobe.empty() and ((int)topx.size())< x){
                        auto cur= *tobe.begin();
                        topx.insert(cur);
                        sm+= (1ll* cur[0]*cur[1]);
                        tobe.erase(tobe.begin());
                }

                while(!tobe.empty() and !topx.empty() and (( (*tobe.begin())[0]> ( (*topx.rbegin())[0])) || ( (*tobe.begin())[0])==( (*topx.rbegin())[0]) and (( (*tobe.begin())[1]> ( (*topx.rbegin())[1])))  )){
                   auto ls= *(prev(topx.end()));
                    sm-= (1ll* ls[0]*ls[1]);
                    topx.erase(prev(topx.end()));
                    topx.insert({ (*tobe.begin())[0],(*tobe.begin())[1]});

                    sm+=(1ll *(*tobe.begin())[0]*(*tobe.begin())[1]);
                    tobe.erase(tobe.begin());
                    tobe.insert({ls[0],ls[1]});
                }

            }
            else{

                // mp[rmele]--;
                // if(mp[rmele]==0) mp.erase(rmele);
                auto it1= tobe.find(tof);
              //  cout<<tof[0]<<" "<<tof[1]<<endl;
                if(it1!=tobe.end()) 
                tobe.erase(it1);

                // decrease freq and insert in tobe
                freqrm--;
                if(freqrm>0) tobe.insert({freqrm,rmele});

                int newele= nums[i];
                int newfreq= mp[nums[i]];
                mp[nums[i]]++;

                array<int,2> nele={newfreq,newele};
                auto it2= topx.find(nele);

                if(it2!=topx.end()){
                    topx.erase(it2);
                    sm+= newele;
                    topx.insert({newfreq+1,newele});
                }
                else{
                    auto it3= tobe.find(nele);
                    if(it3!=tobe.end()) tobe.erase(it3);
                    
                    tobe.insert({newfreq+1,newele});

                }

                 while(!tobe.empty() and ((int)topx.size())< x){
                        auto cur= *tobe.begin();
                        topx.insert(cur);
                        sm+= (1ll*cur[0]*cur[1]);
                        tobe.erase(tobe.begin());
                }

               while(!tobe.empty() and  !topx.empty() and (( (*tobe.begin())[0]> ( (*topx.rbegin())[0])) || ( (*tobe.begin())[0])==( (*topx.rbegin())[0]) and (( (*tobe.begin())[1]> ( (*topx.rbegin())[1])))  )){

                   auto ls= *(prev(topx.end()));
                    sm-= (1ll*ls[0]*ls[1]);
                    topx.erase(prev(topx.end()));
                    topx.insert({ (*tobe.begin())[0],(*tobe.begin())[1]});

                    sm+=(1ll * ( *tobe.begin())[0]*(*tobe.begin())[1]);
                    tobe.erase(tobe.begin());
                    tobe.insert({ls[0],ls[1]});

                }


            }

            ans.push_back(sm);

            // for(auto it:topx) cout<<"( "<<it[0]<<" "<<it[1]<<" ) ";
            // cout<<endl;
            // for(auto it:tobe) cout<<"( "<<it[0]<<" "<<it[1]<<" ) ";
            // cout<<endl;

           // cout<<endl;
            

        }
        return ans;


    }
};