#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int z = 0;
    int o = 0;
    for(auto &i:arr){
        cin>>i;
        if(!i)z++;
        else if(i == 1)o++;
    }
    // for(auto &i:arr)cout<<i<<' ';cout<<endl;
    if(z>(n-z)+1){
        if(o+z != n||o == 0)cout<<1<<'\n';
        else cout<<"2\n";
        return;
    }
    cout<<0<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}