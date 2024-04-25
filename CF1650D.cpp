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
	list<int> lst;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		lst.push_back(k);
	}
	vector<int> ans(n+1,0);
	for(int i = n;i>=1;i--){
		int cnt = 1;
		auto it = lst.begin();
		while(*it != i){
			it++;
			cnt++;
		}
//		cout<<i<<' '<<*it<<' '<<cnt<<'\n';
		ans[i] = cnt;
		auto rit = lst.end();
		for(int j = n-i;j>=0;j--)--rit;
		while(rit != it){
			lst.push_front(*rit);
			auto tmp = rit;
			rit--;
			lst.erase(tmp);
		}
//		for(auto j:lst)cout<<j<<',';cout<<'\n';
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]%i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

