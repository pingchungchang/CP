#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
set<int> st;
ll arr[mxn],brr[mxn];
vector<int> op[mxn];
int n,m;

void solve(){
	st.clear();
	for(int i = 0;i<=n;i++){
		arr[i] = brr[i] = 0;
		op[i].clear();
	}
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i],arr[i] += arr[i-1];
	for(int i = 1;i<=n;i++)cin>>brr[i],brr[i] += brr[i-1];
	for(int i = 0;i<=n;i++)st.insert(i);
	queue<pii> q;
	for(int i = 0;i<m;i++){
		int l,r;
		cin>>l>>r;
		l--;
		if(arr[l] == brr[l]&&arr[r] == brr[r])q.push(make_pair(l,r));
		else{
			op[l].push_back(r);
			op[r].push_back(l);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		auto lit = st.lower_bound(now.fs);
		auto rit = st.upper_bound(now.sc);
		for(auto it = lit;it != rit;it++){
			arr[*it] = brr[*it];
		}
		for(auto it = lit;it != rit;it++){
			for(auto &j:op[*it]){
				if(arr[j] == brr[j]){
					q.push(make_pair(min(j,*it),max(j,*it)));
				}
			}
		}
		st.erase(lit,rit);
	}
	bool flag = true;
	for(int i = 0;i<=n;i++){
		if(arr[i] != brr[i])flag = false;
	}
	cout<<(flag?"YES\n":"NO\n");
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
