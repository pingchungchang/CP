#include <bits/stdc++.h>
using namespace std;

void solve(){
    int w,d,h,a,b,f,g;
    cin>>w>>d>>h>>a>>b>>f>>g;
    int len1 = h+min({a+f+abs(b-g),w-a+w-f+abs(b-g),b+g+abs(f-a),d-b+d-g+abs(f-a)});
    cout<<len1<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie();cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}