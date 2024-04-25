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
	vector<int> pars(n+1,0);
	for(int i= 1;i<=n;i++){
		cin>>pars[i];
	}
	int mx = 0;
	vector<int> tags(n+1,0);
	vector<int> v(n+1);
	vector<int> ans(n+1,0);
	vector<int> total(n+1,0);
	for(int i = 1;i<=n;i++)cin>>v[i];
	for(int i = 1;i<=n;i++){
		int now = v[i];
		tags[now] = 1;
		if(tags[pars[now]] == 0){
			cout<<-1<<'\n';
			return;
		}
		if(i != 1){
			mx++;
			ans[now] = mx-total[pars[now]];
			total[now] = mx;
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

