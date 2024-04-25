#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    multiset<int> st;
    int t;
    while(cin>>t){
        if(t == -1){
            if(st.empty())continue;
            else{
                cout<<*st.begin()<<' ';
                st.erase(st.find(*st.begin()));
            }
        }
        else if(t == -2){
            if(st.empty())continue;
            else{
                cout<<*st.rbegin()<<' ';
                st.erase(st.find(*st.rbegin()));
            }
        }
        else st.insert(t);
    }
}