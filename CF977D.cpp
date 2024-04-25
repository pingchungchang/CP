#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bool cmp(ll a,ll b){
	ll ca = 0,cb = 0;
	while(a%3 == 0)ca++,a/=3;
	while(b%3 == 0)cb++,b/=3;
	ll ta = 0,tb = 0;
	while(!((1LL<<ta)&a))ta++;
	while(!((1LL<<tb)&b))tb++;
	if(ca == cb)return ta<tb;
	else return ca>cb;
}

void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n,cmp);
	for(auto &i:arr)cout<<i<<' ';return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
