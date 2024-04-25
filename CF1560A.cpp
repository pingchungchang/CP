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
vector<ll> v;
void solve(){
	int n;
	cin>>n;
	cout<<v[n-1]<<'\n';
	return;
}
int main(){
	io
	for(int i = 1;i<(ll)10000;i++){
		if(i%3 != 0&&i %10 != 3)v.push_back(i);
	}
//	cout<<v.size()<<endl;return 0;
	int t;
	cin>>t;
	while(t--)solve();
}

