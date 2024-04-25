#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	set<int> v[n];
	vector<int> all;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			v[i].insert(tmp);
			all.push_back(tmp);
		}
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	int ans = 0;
	for(auto &no:all){
		set<int> st;
		for(auto &i:v){
			if(i.find(no) == i.end()){
				for(auto &j:i)st.insert(j);
			}
		}
		ans = max(ans,(int)st.size());
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
