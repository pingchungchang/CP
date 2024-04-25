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
void solve(){
	int n;
	cin>>n;
	ll total = 0;
	vector<int> ev,odd;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		total += k;
		if(k&1)odd.push_back(i+1);
		else ev.push_back(i+1);
	}
	bool flag = false;
	for(ll i = 2;i*i<=total;i++){
		if(total%i == 0){
			flag = true;
			break;
		}
	}
	if(!flag)cout<<ev.size()+odd.size()-1<<'\n';
	else cout<<ev.size()+odd.size()<<'\n';
	for(auto i:ev)cout<<i<<' ';for(int i = 0;i<(int)odd.size()-1;i++)cout<<odd[i]<<' ';
	if(flag&&!odd.empty())cout<<odd.back()<<'\n';
	else cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

