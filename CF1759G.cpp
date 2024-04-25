#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n/2];
    set<int> st;
    for(int i =1;i<=n;i++)st.insert(i);
    for(auto &i:arr){
        cin>>i;
        st.erase(i);
    }
    if(st.size() != n/2){
        cout<<"-1\n";
        return;
    }
    int ans[n];
    for(int i = n-1;i>=0;i-=2){
        auto it = st.lower_bound(arr[i/2]);
        if(it == st.begin()){
            cout<<"-1\n";
            return;
        }
        it--;
        ans[i] = arr[i/2];
        ans[i-1] = *it;
        st.erase(it);
    }
    for(int i = 0;i<n;i++)cout<<ans[i]<<' ';cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}