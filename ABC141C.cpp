#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n+1,m);
    for(int i = 0;i<k;i++){
        int a;
        cin>>a;
        v[a]++;
    }
    for(int i = 1;i<=n;i++){
        if(v[i]>k)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
