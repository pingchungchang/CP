#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    multiset<ll> st;
    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1){
            ll x;
            cin>>x;
            st.insert(x);
        }
        else if(t == 2){
            ll x,c;
            cin>>x>>c;
            while(c>0&&st.find(x) != st.end()){
                st.erase(st.find(x));
                c--;
            }
        }
        else{
            cout<<*st.rbegin()-*st.begin()<<'\n';
        }
    }
}
