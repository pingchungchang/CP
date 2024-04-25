#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int shift = n/3;
	n = n%3;
	if(n == 1)cout<<shift+1<<' '<<shift<<'\n';
	else if(n == 2)cout<<shift<<' '<<shift+1<<'\n';
	else cout<<shift<<' '<<shift<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
