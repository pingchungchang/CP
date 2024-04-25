#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	deque<ll> v;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		v.push_back(k);
	}
	for(int i = 0;i<=n;i++){
		if(v.front() == 1)break;
		v.push_back(v.front());
		v.pop_front();
		if(i == n){
			cout<<"NO\n";
			return;
		}
	}
	v.pop_front();
	int pre = 1;
	for(int i = 2;i<=n;i++){
		if(v.front()>i||v.front() == 1||v.front()-pre>1){
			cout<<"NO\n";
			return;
		}
		pre = v.front();
		v.pop_front();
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

