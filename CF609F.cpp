#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second

bool flag;

struct node{
	ll lp,rp,id;
	ll src;
	node(){}
	node(ll lll,ll rrr,ll ii,ll ss){
		id = ii;
		lp = lll,rp = rrr;
		src = ss;
	}
	inline const bool operator<(const node& b)const{
		if (flag) return src < b.src;
		else return lp<b.lp;
	}
};

const int mxn = 2e5+10;
ll cnt[mxn],len[mxn];
multiset<pll> mos;
set<node> frog;

void addfrog(node now){
	flag = true;
	auto it = frog.lower_bound(now);
	if(it != frog.begin()){
		it--;
		if(it->rp>=now.rp){
			return;
		}
		now.lp = max(now.lp,it->rp+1);
		flag = true;
		it++;
		assert(it == frog.lower_bound(now));
		it = frog.lower_bound(now);
	}
	auto rit = it;
	while(rit != frog.end()&&rit->rp<=now.rp)rit++;
	flag = false;
	frog.erase(it,rit);
	if(rit != frog.end()){
		auto val = *rit;
		frog.erase(rit);
		val.lp = max(now.rp+1,val.lp);
		frog.insert(val);
	}
	frog.insert(now);
}
void addmos(pll now){
	mos.insert(now);
	flag = false;
	auto eat = frog.end();
	while((eat = frog.upper_bound(node(now.fs,now.sc,0,now.fs))) != frog.begin()){
		eat--;
		if(eat->rp >= now.fs){
			len[eat->id] += now.sc;
			cnt[eat->id]++;
			mos.erase(mos.find(now));
			addfrog(node(eat->lp,eat->rp+now.sc,eat->id,eat->src));
			if(mos.lower_bound(now) == mos.end())break;
			now = *mos.lower_bound(now);
		}
		else break;
	}
	return;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	pll arr[n],brr[m];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	for(auto &i:brr)cin>>i.fs>>i.sc;
	for(int i = 0;i<n;i++){
		addfrog(node(arr[i].fs,arr[i].fs+arr[i].sc,i,arr[i].fs));
	}
	//for(auto &i:frog)cout<<i.lp<<','<<i.rp<<','<<i.src<<','<<i.id<<' ';cout<<endl;
	for(int i = 0;i<m;i++){
		addmos(brr[i]);
		//for(auto &i:frog)cout<<i.lp<<','<<i.rp<<','<<i.src<<','<<i.id<<' ';cout<<endl;
	}
	for(int i = 0;i<n;i++){
		cout<<cnt[i]<<' '<<len[i]+arr[i].sc<<'\n';
	}
	return 0;
}
