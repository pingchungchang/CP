#include <bits/stdc++.h>
using namespace std;

int n;
void solve(){
    int total = 0;
    set<int> st;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        total += k;
        st.insert(k);
    }
    total -= *st.begin()+*st.rbegin();
    cout<<fixed<<setprecision(2)<<total/(long double)(n-2)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n)solve();
}