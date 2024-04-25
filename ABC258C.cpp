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
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	s += s;
	int now = 0;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int tmp;
			cin>>tmp;
			now += tmp;
			now %= n;
		}
		else{
			int k;
			cin>>k;
			cout<<s[n+k-now-1]<<'\n';
		}
	}
	return 0;
}

