#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
set<pii> st;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    pii now = {0,0};
    st.insert(now);
    for(auto &i:s){
        if(i == 'L')now.fs++;
        else if(i == 'R')now.fs--;
        else if(i == 'U')now.sc++;
        else now.sc--;
        if(st.find(now) != st.end()){
            cout<<"Yes";
            return 0;
        }
        st.insert(now);
    }
    cout<<"No";
    return 0;
}