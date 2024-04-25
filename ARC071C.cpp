#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    int n = a.size(),m = b.size();
    vector<int> p1(n+1,0);
    vector<int> p2(n+1,0);
    for(int i = 0;i<n;i++){
        p1[i+1] = p1[i]+ a[i]-'a';
    }
    for(int i = 0;i<m;i++){
        p2[i+1] = p2[i]+b[i]-'a';
    }
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        int s1,e1,s2,e2;
        cin>>s1>>e1>>s2>>e2;
        if((p1[e1]-p1[s1-1])%3 == (p2[e2]-p2[s2-1])%3)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
