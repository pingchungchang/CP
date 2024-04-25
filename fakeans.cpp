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

bool cmp(pll a,pll b){
	if(a.fs*b.sc == a.sc*b.fs)return a.fs<b.fs;
	else return a.fs*b.sc<b.fs*a.sc;
}
void solve(int id){
	string in = "ojdl7164_testcases/"+to_string(id)+".in";
	ifstream fin(in);
	ll n,k;
	fin>>n>>k;
	pll v[n];
	for(int i = 0;i<n;i++)fin>>v[i].sc;
	for(int i = 0;i<n;i++)fin>>v[i].fs;
	sort(v,v+n,cmp);
	pll ans = {0,0};
	for(int i = n-1;i>=n-k;i--){
		ans.fs += v[i].fs;
		ans.sc += v[i].sc;
	}
	cout<<fixed<<setprecision(8)<<(ld)ans.fs/ans.sc<<'\n';
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i<)
}

