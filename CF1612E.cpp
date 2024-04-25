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

ll fac = 1;
struct node{
	vector<ll> nums;
	ll id;
	
};
bool cmp(const node &a,const node &b){
	ll ca = 0,cb = 0;
	for(auto &i:a.nums)ca += (i>fac?fac:i);
	for(auto &i:b.nums)cb += (i>fac?fac:i);
	return ca>cb;
}
int main(){
	io
	ll n;
	cin>>n;
	vector<pll> v(n);
	pll ans =make_pair(0,0);
	vector<ll> all;
	for(int i = 0;i<n;i++){
		cin>>v[i].fs>>v[i].sc;
		all.push_back(v[i].fs);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(auto &i:v){
		i.fs = lower_bound(_all(all),i.fs)-all.begin();
	}
	vector<node> cnt(all.size());
	for(int i = 0;i<all.size();i++)cnt[i].id = i;
	for(auto &i:v){
		cnt[i.fs].nums.push_back(i.sc);
	}
	for(ll i = 1;i<=40;i++){
		if(i>all.size())break;
		sort(_all(cnt),cmp);
		ll tmp = 0;
		for(ll j = 0;j<i;j++){
			for(auto k:cnt[j].nums){
				tmp += (k>fac?fac:k);
			}
		}
//		cout<<tmp<<endl;
		if(tmp*ans.sc>=ans.fs*i)ans = make_pair(tmp,i);
		fac++;
	}
	fac = ans.sc;
	sort(_all(cnt),cmp);
	vector<ll> re;
	for(int i = 0;i<ans.sc;i++)re.push_back(all[cnt[i].id]);
	cout<<re.size()<<'\n';
	for(auto i:re)cout<<i<<' ';
	return 0;
}

