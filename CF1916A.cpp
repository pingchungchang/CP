#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,k;
	cin>>n>>k;
	int p[] = {7,17};
	vector<int> v;
	int r = 1;
	while(n--){
		int tmp;
		cin>>tmp;
		r *= tmp;
	}
	if(2023%r != 0){
		cout<<"NO\n";
		return;
	}
	cout<<"Yes\n";
	cout<<2023/r<<' ';
	k--;
	while(k--)cout<<1<<' ';
	cout<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
