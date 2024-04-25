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
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<int> ans(n);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		string s;
		cin>>s;
		int now = v[i];
		for(auto j:s){
			if(j == 'D')now++;
			else now--;
		}
		now += 100;
		now %= 10;
		ans[i] = now;
	}
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

