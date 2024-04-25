#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> arr[n];
	for(auto &i:arr)i = vector<int>(m,0);
	for(int i = 0;i<m;i++){
		int now = (i+1)%m;
		for(int j = 0;j<n;j++){
			arr[j][i] = now;
			now = (now+1)%m;
			if(now==i)now = (now+1)%m;
		}
	}
	set<int> st;
	for(int i = 0;i<m;i++){
		set<int> ss;
		for(int j = 0;j<n;j++){
			ss.insert(arr[j][i]);
		}
		for(int j = 0;j<=m;j++){
			if(ss.find(j) == ss.end()){
				st.insert(j);
				break;
			}
		}
	}
	int ans;
	for(ans = 0;ans<=m;ans++){
		if(st.find(ans) == st.end())break;
	}
	cout<<ans<<'\n';
	for(auto &i:arr){
		for(auto &j:i)cout<<j<<' ';cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
