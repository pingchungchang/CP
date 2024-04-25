#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i =1;i<=n;i++){
        int a;
        cin>>a;
        v[i-1].first = a;
        v[i-1].second = i;
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<n/2;i++){
        cout<<v[i].second<<' '<<v[n-1-i].second;
        if(i != n/2-1)cout<<'\n';
    }
}
