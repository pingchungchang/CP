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

string conv(int k,int bits){
	string re;
	for(int i = 0;i<bits;i++){
		if(k&1)re += '1';
		else re += '0';
		k>>=1;
	}
	reverse(_all(re));
	return re;
}
int decode(string s){
	int re= 0;
	for(int i = 0;i<s.size();i++){
		re<<=1;
		if(s[i] == '1')re ^=1;
	}
	return re;
}
void dfs(int now,int par,vector<vector<int>>&tree,vector<int>& pars){
	pars[now] = par;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now,tree,pars);
	}
	return;
}
string send(int n,vector<pii> edges){
	string re = conv(n,17);
	vector<int> pars(n);
	int b = 0;
	int kk = n;
	vector<vector<int>> tree(n);
	while(kk){
		b++;
		kk>>=1;
	}
	for(auto &i:edges){
		tree[i.fs].push_back(i.sc);
		tree[i.sc].push_back(i.fs);
	}
	dfs(0,0,tree,pars);
	for(int i = 1;i<n;i++){
		re += conv(pars[i],b);
	}
	return re;
}
vector<pii> recv(string code){
	int n = decode(code.substr(0,17));
	vector<pii> ans;
	int b = 0;
	while(n){
		b++;
		n>>=1;
	}
	int cnt = 1;
	for(int i = 17;i<code.size();i+= b){
		int p = decode(code.substr(i,b));
		ans.push_back({p,cnt});
		cnt++;
	}
	return ans;
}
//int main(){
//	int n;
//	cin>>n;
//	vector<pii> v(n-1);
//	for(auto &i:v){
//		cin>>i.fs>>i.sc;
//	}
//	string tmp = send(n,v);
//	auto re = recv(tmp);
//	for(auto &i:re)cout<<i.fs<<' '<<i.sc<<',';
//}

