#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const ll mod = 998244353;
const int mxn = 1+(1<<7);
pii trie[mxn];
int fail[mxn];
vector<string> v;
bitset<mxn> no;
int arr[mxn];

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

vector<vector<ll>> mul(vector<vector<ll>> a,vector<vector<ll>> b){
	vector<vector<ll>> re(mxn,vector<ll>(mxn,0));
	for(int i = 0;i<mxn;i++){
		for(int j = 0;j<mxn;j++){
			for(int k = 0;k<mxn;k++){
				re[i][j] = mad(re[i][j],a[i][k]*b[k][j]%mod);
			}
		}
	}
	return re;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i = 1;i<=6;i++){
		for(int j = 0;j<(1<<i);j++){
			v.push_back("");
			for(int k = 0;k<i;k++){
				if(j&(1<<k))v.back() += 'b';
				else v.back() += 'a';
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<m;i++){
		string s;
		cin>>s;
		for(int j = 0;j<v.size();j++){
			int aa = v[j].size(),bb = s.size();
			for(int k = 0;k<aa-bb+1;k++){
				if(v[j].substr(k,s.size()) == s)no[j] = true;
			}
		}
	}
	//cout<<v.size()<<' '<<mxn<<endl;
	vector<vector<ll>> paths(mxn,vector<ll>(mxn,0));
	auto now = paths;
	for(int i = 0;i<now.size();i++)now[i][i] = 1;
	for(int i = 0;i<v.size();i++){
		if(no[i])continue;
		string tmp = v[i];
		if(tmp.size()<=5){
			tmp = tmp+'a';
			auto id = lower_bound(v.begin(),v.end(),tmp)-v.begin();
			if(!no[id])paths[i][id] = 1;
			tmp.pop_back();
			tmp+='b';
			id = lower_bound(v.begin(),v.end(),tmp)-v.begin();
			if(!no[id])paths[i][id] = 1;
			tmp.pop_back();
		}
		if(tmp.size() == 6){
			tmp = tmp.substr(1,5)+'a';
			auto id = lower_bound(v.begin(),v.end(),tmp)-v.begin();
			if(!no[id]&&v[id] == tmp)paths[i][id] = 1;
			tmp = tmp.substr(0,5)+'b';
			id = lower_bound(v.begin(),v.end(),tmp)-v.begin();
			if(!no[id]&&v[id] == tmp)paths[i][id] = 1;
			tmp.pop_back();
		}
	}
	/*
	for(int i= 0;i<mxn;i++){
		for(int j = 0;j<mxn;j++){
			if(paths[i][j]){
				cout<<v[i]<<' '<<v[j]<<endl;
			}
		}
	}

   */
	n--;
	while(n){
		if(n&1)now = mul(now,paths);
		paths = mul(paths,paths);
		n>>=1;
	}
	auto a = lower_bound(v.begin(),v.end(),"a")-v.begin();
	auto b= lower_bound(v.begin(),v.end(),"b")-v.begin();
	ll ans = 0;
	for(int i = 0;i<mxn;i++){
		ans = mad(ans,mad(now[a][i],now[b][i]));
	}
	cout<<ans;
}
