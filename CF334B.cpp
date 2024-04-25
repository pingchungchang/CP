#include <bits/stdc++.h>
using namespace std;

int main(){
    set<pair<int,int>> st;
    set<int>xs;
    set<int>ys;
    vector<pair<int,int>> v(8);
    for(int i = 0;i<8;i++){
        cin>>v[i].first>>v[i].second;
        st.insert(v[i]);
        xs.insert(v[i].first);
        ys.insert(v[i].second);
    }
    vector<int> x;
    vector<int> y;
    for(auto i:xs)x.push_back(i);
    for(auto i:ys)y.push_back(i);
    if(x.size() !=3||y.size() != 3){
        cout<<"ugly";
    }
    else{
        for(int i = 0;i<x.size();i++){
            for(int j = 0;j<y.size();j++){
                if(i == 1&&j == 1)continue;
                if(st.find(make_pair(x[i],y[j])) == st.end()){
                    cout<<"ugly";
                    return 0;
                }
            }
        }
        cout<<"respectable";
    }
}
