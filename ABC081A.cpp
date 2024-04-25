#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
#define pii pair<int,int>
#define pll pair<ll,ll>
int main(){
    string s;
    cin>>s;
    int ans =0;
    for(auto &i:s)ans += i-'0';
    cout<<ans;
}