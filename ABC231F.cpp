#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define _all(T) T.begin(),T.end()
const ll mxn = 2e5+10;
ll bit[mxn];
void modify(ll p,ll v){
	for(;p<mxn;p += p&-p)bit[p] += v;
	return;
}
ll getval(ll s,ll e){
	ll re = 0;
	for(;e>0;e -= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}
bool cmp(pll a,pll b){
	if(a.fs != b.fs)return a.fs<b.fs;
	else return a.sc>b.sc;
}
int main(){
	int n;
	cin>>n;
	pll arr[n];
	vector<ll> alla,allb;
	for(auto &i:arr){
		cin>>i.fs;
		alla.push_back(i.fs);
	}
	for(auto &i:arr){
		cin>>i.sc;
		allb.push_back(i.sc);
	}
	sort(_all(alla));
	alla.erase(unique(_all(alla)),alla.end());
	sort(_all(allb));
	allb.erase(unique(_all(allb)),allb.end());
	for(auto &i:arr){
		i.fs = lower_bound(_all(alla),i.fs)-alla.begin()+1;
		i.sc = lower_bound(_all(allb),i.sc)-allb.begin()+1;
	}
	sort(arr,arr+n,cmp);
	for(auto &i:arr)cout<<i.fs<<' '<<i.sc<<',';
	vector<vector<int>> v;
	for(auto &i:arr){
		if(v.empty()||v.back()[0] != i.fs||v.back()[1] != i.sc)v.push_back({i.fs,i.sc,1});
		else v.back()[2]++;
	}
	cout<<endl;
	for(auto &i:v)cout<<i[0]<<" "<<i[1]<<' '<<i[2]<<',';
//	return 0;
	ll ans = 0;
	for(auto &i:v){
		ans += getval(i[1],mxn-1);
		ans += i[2]*i[2];
		modify(i[1],i[2]);
	}
	cout<<ans;
	
}
