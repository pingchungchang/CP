#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans = 0;
	for(int i = 0;i<=a;i++){
		if(i*2>b)break;
		int tb = b-i*2;
		int tans = i*3;
		tans += min(c/2,tb)*3;
		ans = max(ans,tans);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
