#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 1e5+10;
const int sq = sqrt(mxn);
const ll inf = 1e18;
int n,q,d;
ll ans[mxn];
ll arr[mxn];
vector<ll> all;
int tar[mxn];
int itar[mxn];
int cnt[mxn];
ll sum;

struct Q{
	int l,r,id;
	Q(){}
	bool operator<(Q &b)const{
		return l/sq == b.l/sq?l/sq&1?r>b.r:r<b.r:l<b.l;
	}
};

vector<Q> req;
void addR(int val){
	val = arr[val];
	sum += cnt[tar[val]];
	cnt[val]++;
	return;
}
void addL(int val){
	val = arr[val];
	sum += cnt[itar[val]];
	cnt[val]++;
}
void delL(int val){
	val = arr[val];
	assert(val);
	cnt[val]--;
	sum -= cnt[itar[val]];
	return;
}
void delR(int val){
	val = arr[val];
	cnt[val]--;
	sum -= cnt[tar[val]];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>d;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		int tmp;
		cin>>tmp;
		if(arr[i]==1)arr[i] = arr[i-1]+tmp;
		else arr[i] = arr[i-1]-tmp;
	}
	for(int i = 0;i<=n;i++)all.push_back(arr[i]);
	all.push_back(-inf);
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 0;i<all.size();i++){
		auto it = lower_bound(all.begin(),all.end(),all[i]-d);
		if(it != all.end()&&*it == all[i]-d)tar[i] = it-all.begin();
		else tar[i] = 0;
		it = lower_bound(all.begin(),all.end(),all[i]+d);
		if(it != all.end()&&*it == all[i]+d)itar[i] = it-all.begin();
		else itar[i] = 0;
	}
	for(int i = 0;i<=n;i++){
		arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
	}
	cin>>q;
	for(int i = 0;i<q;i++){
		Q tmp;
		cin>>tmp.l>>tmp.r;
		tmp.id = i;
		tmp.l--;
		req.push_back(tmp);
	}

	/*
	for(auto &i:all)cout<<i<<',';cout<<endl;
	for(int i = 0;i<=n;i++)cout<<all[arr[i]]<<' ';cout<<endl;
   */
	int pl = 0,pr = 0;
	sort(req.begin(),req.end());
	addL(0);
	for(auto &i:req){
		while(pr<i.r)addR(++pr);
		while(pl>i.l)addL(--pl);
		while(pr>i.r)delR(pr--);
		while(pl<i.l)delL(pl++);
		//cout<<i.l<<' '<<i.r<<":"<<sum<<endl;
		ans[i.id] = sum;
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
	return 0;
}
