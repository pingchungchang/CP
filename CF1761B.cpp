#include <bits/stdc++.h>
using namespace std;

void solve(){
    list<int> lst;
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    bool flag = true;
    set<int> st;
    for(int i = 0;i<n;i++){
        st.insert(arr[i]);
    }
    if(st.size() <= 2){
        cout<<n/2+1<<'\n';
    }
    else cout<<n<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}