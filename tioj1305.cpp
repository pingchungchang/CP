#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define uint long long
#define ll long long
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ordered_set st;
    string s;
    ll n;
    while(cin>>s){
        if(s == "exit")return 0;
        cin>>n;
        if(s[0] == 'i')st.insert(n);
        else if(s[0] == 'a'){
            if(n>st.size()||n<1)cout<<"error\n";
            else cout<<*st.find_by_order(n-1)<<'\n';
        }
        else if(s[0] = 'r'){
            if(st.find(n) != st.end())st.erase(n);
        }
        else assert(false);
    }
    return 0;
}