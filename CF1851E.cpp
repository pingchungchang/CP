#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll


void solve(){
	int n,k;
	cin>>n>>k;
	set<int> st;
	int cost[n+1];
	for(int i = 1;i<=n;i++)cin>>cost[i];
	for(int i = 0;i<k;i++){
		int c;
		cin>>c;
		st.insert(c);
	}
	int ans[n+1];
	queue<int> q;
	int sum[n+1];
	memset(sum,0,sizeof(sum));
	vector<int> v[n+1];
	int miss[n+1];
	memset(miss,0,sizeof(miss));
	for(int i = 1;i<=n;i++){
		ans[i] = cost[i];
		int e;
		cin>>e;
		for(int j = 0;j<e;j++){
			int tmp;
			cin>>tmp;
			if(st.find(i) != st.end())continue;
			if(st.find(tmp) != st.end())continue;
			v[tmp].push_back(i);
			miss[i]++;
		}
		if(!miss[i]){
			if(e == 0&&st.find(i) == st.end())sum[i] = ans[i];
			else sum[i] = 0;
			q.push(i);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		ans[now] = min(ans[now],sum[now]);
		for(auto &i:v[now]){
			miss[i]--;
			sum[i]+=ans[now];
			if(!miss[i])q.push(i);
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
