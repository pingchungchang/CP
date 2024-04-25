#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
map<int,int> mp;
pii big = {0,0};

int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int a;
    while(cin>>a){
        if(!a)break;
        mp[a]++;
        big = max(big,{mp[a],-a});
        cout<<big.fs<<' '<<-big.sc<<'\n';
    }
    return 0;
}