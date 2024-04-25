#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,q;
	cin>>n>>q;
	int pre = 2;
	for(int i = 2;i<=n;i++)cout<<i-1<<' '<<i<<'\n';
	while(q--){
		int r;
		cin>>r;
		if(n-pre+1 == r)cout<<"-1 -1 -1\n";//n-p+1 = r->p = n-r+1
		else cout<<1<<' '<<pre<<' '<<(pre = n-r+1)<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
