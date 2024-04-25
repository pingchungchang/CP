#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
ll n,m;
ll arr[mxn];
deque<ll> dq;
vector<ll> ans;

void solve(){
	cin>>n>>m;
	ans.clear();
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		dq.push_back(k);
	}
	sort(dq.rbegin(),dq.rend());
	for(int i = 0;i<n;i++){
		while(!dq.empty()&&dq.front()>=arr[i]){
			ans.push_back(dq.front());
			dq.pop_front();
		}
		ans.push_back(arr[i]);
	}
	while(!dq.empty()){
		ans.push_back(dq.front());
		dq.pop_front();
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
