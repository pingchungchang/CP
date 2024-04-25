#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    n = s.size();
    vector<pair<char,int>> v;
    for(auto i:s){
        if(v.empty()||v.back().fs != i){
            v.push_back(make_pair(i,1));
        }
        else v.back().sc++;
    }
    multiset<int> st;
    for(int i = 1;i<v.size()-1;i++){
        if(v[i].fs == 'R'&&v[i].sc == 1&&v[i-1].fs == 'A'&&v[i+1].fs == 'C'){
            st.insert(min(v[i+1].sc,v[i-1].sc));
        }
    }
    //for(auto i:st)cout<<i<<' ';cout<<endl;
    int t = 0;
    while(!st.empty()){
        t++;
        int now;
        if(t%2 == 1){
            now = *st.rbegin();
            st.erase(st.find(now));
            now--;
            if(now>0)st.insert(now);
        }
        else{
            now = *st.begin();
            st.erase(st.find(now));
        }
        //for(auto i:st)cout<<i<<' ';cout<<endl;
    }
    cout<<t;
}
