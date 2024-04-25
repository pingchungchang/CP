#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
set<ll> st;
int n,Q;
ll arr[mxn],pref[mxn];
queue<pii> q;

void solve(){
	st.clear();
	cin>>n>>Q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	q.push(make_pair(1,n));
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		st.insert({pref[now.sc]-pref[now.fs-1]});
		if(arr[now.fs] == arr[now.sc])continue;
		ll mid = (arr[now.fs]+arr[now.sc])>>1;
		auto pos = upper_bound(arr+now.fs,arr+now.sc+1,mid)-arr;
		q.push(make_pair(now.fs,pos-1));
		q.push(make_pair(pos,now.sc));
	}
	while(Q--){
		int k;
		cin>>k;
		if(st.find(k) != st.end())cout<<"Yes\n";
		else cout<<"No\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
