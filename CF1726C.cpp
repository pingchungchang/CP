#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	s = "("+s+")";
	vector<int> st;
	for(int i = 0;i<=n*2;i++)dsu[i] = i,sz[i] = 1;
	vector<pii> tmp[n*2+2];
	for(int i = 0;i<s.size();i++){
		if(s[i] == '('){
			st.push_back(i);
			tmp[st.size()].push_back({i,-1});
		}
		else{
			tmp[st.size()].back().sc = i;
			if(!tmp[st.size()+1].empty()){
				for(auto &j:tmp[st.size()+1]){
					onion(j.fs,j.sc);
					onion(tmp[st.size()+1][0].fs,j.fs);
				}
			}
			tmp[st.size()+1].clear();
			st.pop_back();
		}
	}
	int ans = 0;
	for(int i = 1;i<=n*2;i++)if(dsu[i] ==i)ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
