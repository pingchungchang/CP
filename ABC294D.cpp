#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set<int> st;
    int p = 1;
    int n,q;
    cin>>n>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            st.insert(p);
            p++;
        }
        else if(t == 2){
            int k;
            cin>>k;
            st.erase(k);
        }
        else{
            cout<<*st.begin()<<'\n';
        }
    }
    return 0;
}