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
int main(){
	io
	int n,m;
	cin>>n>>m;
	vector<pll> a,b;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(a.empty()||a.back().fs != k)a.push_back({k,1});
		else a.back().sc++;
	}
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		if(b.empty()||b.back().fs != k)b.push_back({k,1});
		else b.back().sc++;
	}
	ll ans = 0;
	int p = 0;
	for(int i = 0;i<a.size();i++){
		while(p != b.size()&&b[p].fs<a[i].fs)p++;
		if(p != b.size()&&b[p].fs == a[i].fs)ans += b[p].sc*a[i].sc;
	}
	cout<<ans;
}

