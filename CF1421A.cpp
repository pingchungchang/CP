#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int a,b;
	cin>>a>>b;
	int ans = 0;
	for(int i = 30;i>=0;i--){
		if(((1<<i)&a) != ((1<<i)&b))ans ^= 1<<i;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
