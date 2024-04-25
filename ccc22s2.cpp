#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5e5+10;
int dsu[mxn];
vector<string> all;
vector<pair<string,string>> same,dif;
vector<tuple<string,string,string>> paths;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x,y,g;
	cin>>x;
	for(int i = 0;i<x;i++){
		string a,b;
		cin>>a>>b;
		same.push_back({a,b});
		all.push_back(a);
		all.push_back(b);
	}
	cin>>y;
	for(int i = 0;i<y;i++){
		string a,b;
		cin>>a>>b;
		dif.push_back({a,b});
		all.push_back(a);
		all.push_back(b);
	}
	cin>>g;
	for(int i = 0;i<g;i++){
		string a,b,c;
		cin>>a>>b>>c;
		paths.push_back(make_tuple(a,b,c));
		all.push_back(a);
		all.push_back(b);
		all.push_back(c);
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 0;i<mxn;i++)dsu[i] = i;
	for(auto &i:paths){
		int a = lower_bound(all.begin(),all.end(),get<0>(i))-all.begin();
		int b = lower_bound(all.begin(),all.end(),get<1>(i))-all.begin();
		int c = lower_bound(all.begin(),all.end(),get<2>(i))-all.begin();
		dsu[root(a)] = root(b);
		dsu[root(c)] = root(b);
	}
	int ans = 0;
	for(auto &i:same){
		int a = lower_bound(all.begin(),all.end(),i.fs)-all.begin();
		int b = lower_bound(all.begin(),all.end(),i.sc)-all.begin();
		if(root(a) != root(b))ans++;
	}
	for(auto &i:dif){
		int a = lower_bound(all.begin(),all.end(),i.fs)-all.begin();
		int b = lower_bound(all.begin(),all.end(),i.sc)-all.begin();
		if(root(a) == root(b))ans++;
	}
	cout<<ans;
}
