#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

void solve(){
    vector<pii> v;
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int a[n] = {},b[n] = {};
    set<int> st;
    for(int i = 0;i<n;i++){
        if(st.find(arr[i]) == st.end())a[i] = arr[i];
        else b[i] = arr[i];
        st.insert(arr[i]);
    }
    set<int> sa,sb;
    for(int i = 1;i<=n;i++){
        sa.insert(i);sb.insert(i);
    }
    for(int i = 0;i<n;i++){
        if(a[i])sa.erase(a[i]);
        if(b[i])sb.erase(b[i]);
    }
    for(int i = 0;i<n;i++){
        if(!a[i]){
            auto it = sa.upper_bound(arr[i]);
            if(it == sa.begin()){
                cout<<"No\n";
                return;
            }
            it--;
            a[i] = *it;
            sa.erase(it);
        }
        else if(!b[i]){
            auto it = sb.upper_bound(arr[i]);
            if(it == sb.begin()){
                cout<<"No\n";
                return;
            }
            it--;
            b[i] = *it;
            sb.erase(it);
        }
    }
    sa.clear();sb.clear();
    for(auto &i:a)sa.insert(i);
    for(auto &i:b)sb.insert(i);
    if(sa.size() != n||sb.size() != n){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(auto &i:a)cout<<i<<' ';cout<<'\n';
    for(auto &i:b)cout<<i<<' ';cout<<'\n';
    return;
    // for(int i = 1;i<=n;i++)st.insert(i);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}