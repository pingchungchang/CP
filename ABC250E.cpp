#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
const int mxn = 2e5+10;
ll arr1[mxn],arr2[mxn];
ll sz1[mxn],sz2[mxn];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set<int> st;
    for(int i = 1;i<=n;i++){
        cin>>arr1[i];
        if(st.find(arr1[i]) != st.end())arr1[i] = 0;
        else st.insert(arr1[i]);
        arr1[i] = arr1[i]*(arr1[i]+(1LL<<20));
        sz1[i] = st.size();
    }
    st.clear();
    for(int i =1;i<=n;i++){
        cin>>arr2[i];
        if(st.find(arr2[i]) != st.end())arr2[i] = 0;
        else st.insert(arr2[i]);
        arr2[i] = arr2[i]*(arr2[i]+(1LL<<20));
        sz2[i] = st.size();
    }
    // for(int i = 1;i<=n;i++)cout<<arr1[i]<<' ';cout<<endl;for(int i = 1;i<=n;i++)cout<<arr2[i]<<' ';cout<<endl;return 0;
    for(int i = 1;i<=n;i++){
        arr1[i] ^= arr1[i-1];
        arr2[i] ^= arr2[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        bool flag = true;
        if(sz1[a] != sz2[b])flag = false;
        if(arr1[a] != arr2[b])flag =false;
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}