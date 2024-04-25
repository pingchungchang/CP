#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 4e4+10;
const ll mod = 1e9+7;
int sq = 202;
vector<ll> all;
ll sum = 0;
ll ans[mxn*10];
ll arr[mxn],cnt[mxn];
int n,q;

struct Q{
	int l,r,id;
	Q(){}
	Q(int a,int b,int c){
		l = a,r = b,id = c;
	}
	bool operator<(Q b)const{
		return l/sq == b.l/sq?r<b.r:l/sq<b.l/sq;
		//return l/sq == b.l/sq?(l/sq&1?r>b.r:r<b.r):l/sq<b.l/sq;
	}
};
vector<Q> req;

void add(ll val){
	sum -= cnt[val]*cnt[val]*all[val];
	cnt[val]++;
	sum += cnt[val]*cnt[val]*all[val];
	return;
}
void del(ll val){
	sum -= cnt[val]*cnt[val]*all[val];
	cnt[val]--;
	sum += cnt[val]*cnt[val]*all[val];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 0;i<n;i++){
		arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
	}
	int pl = 0,pr = 0;
	cnt[arr[0]] = 1;
	sum = all[arr[0]];
	for(int i = 0;i<q;i++){
		Q tmp;
		cin>>tmp.l>>tmp.r;
		tmp.r--;
		tmp.id = i;
		req.push_back(tmp);
	}
	sort(req.begin(),req.end());
	for(auto &i:req){
		if(i.l>i.r){
			ans[i.id] = 0;
			continue;
		}
		while(pr<i.r)add(arr[++pr]);
		while(pl>i.l)add(arr[--pl]);
		while(pr>i.r)del(arr[pr--]);
		while(pl<i.l)del(arr[pl++]);
		ans[i.id] = sum%mod;
	}
	for(int i= 0;i<q;i++)cout<<ans[i]<<'\n';
	return 0;
}
