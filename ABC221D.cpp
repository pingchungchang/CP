#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int ans[n+1] = {0};
    pair<int,int> line[n];
    map<int,int> converter;
    for(int i =0;i<n;i++){
        int s,e,b;
        cin>>s>>b;
        e = s+b;
        if(converter.count(s) == 0)converter[s] =0;
        if(converter.count(e) == 0)converter[e] = 0;
        converter[s]++;
        converter[e]--;
    }
    int nowvalue =0;
    auto now = converter.begin();
    for(auto it = converter.begin();it != converter.end();it++){
        ans[nowvalue] += (it->first-now->first);
        now = it;
        nowvalue += it->second;
    }
    for(int i =1;i<=n;i++)cout<<ans[i]<<' ';
}
