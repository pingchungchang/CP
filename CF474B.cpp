#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int n;
	cin>>n;
	vector<int> v(n+1,1);
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		v[i] += v[i-1];
	}
	int q;
	cin>>q;
//	for(auto i:v)cout<<i<<' ';cout<<'\n';
	while(q--){
		int k;
		cin>>k;
		int pos = --upper_bound(v.begin(),v.end(),k)-v.begin();
		cout<<pos+1<<'\n';
	}
	return 0;
}

