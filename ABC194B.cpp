#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i].first>>b[i].first;
        a[i].second = i;
        b[i].second = i;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a[0].second != b[0].second)cout<<max(a[0].first,b[0].first);
    else cout<<min(b[0].first+a[0].first,min(max(a[0].first,b[1].first),max(a[1].first,b[0].first)));
}
