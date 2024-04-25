#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 3e5+10;
vector<int> v[mxn];
vector<int> in[mxn];
int dsu[mxn*2],sz[mxn*2],val[mxn*2],ans[mxn];;
string s;
int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	val[a] += val[b];
	sz[a] += sz[b];
	dsu[b] = a;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	cin>>s;
	s = "#"+s;
	for(int i = 1;i<=k;i++){
		int ss;
		cin>>ss;
		while(ss--){
			int c;
			cin>>c;
			v[i].push_back(c);
			in[c].push_back(i);
		}
		val[mxn+i] = 1;
		sz[mxn+i] = sz[mxn-i] = 1;
		dsu[mxn+i] = mxn+i;
		dsu[mxn-i] = mxn-i;
	}
	sz[0] = 1;
	ans[0] = 0;
	int base = 0;
	for(int i = 1;i<=n;i++){
		if(s[i] == '1'&&in[i].size() == 1){
			ans[i] = ans[i-1];
			continue;
		}
		if(s[i] == '0'&&in[i].size() == 1){
		}
	}
}
