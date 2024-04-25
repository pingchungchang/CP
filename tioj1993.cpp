#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 1e5+10;
bitset<mxn> bs;
void solve(){
	int n,h;
	cin>>n>>h;
	bs.reset();
	bs[0] = true;
	for(int i = 0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		bs = (bs<<x)|(bs<<y)|(bs<<z);
	}
	for(int i = h;i>=0;i--){
		if(bs[i]){
			cout<<i<<'\n';
			return;
		}
	}
	cout<<"no solution\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

