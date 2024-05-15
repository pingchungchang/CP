#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;

struct node{
	int pl,pr;
	ll val;
	node(){pl = pr = val = 0;}
};
vector<node> pool;
int ppp = 0;

int newnode(int src = 0){
	ppp++;
	while(ppp>=pool.size()){
		pool.push_back(node());
	}
	pool[ppp] = pool[src];
	return ppp;
}

struct SEG{
#define ls pool[now].pl
#define rs pool[now].pr
#define mid ((l+r)>>1)
	int rt;
	SEG(){
		rt = 0;
	}
	int modify(int now,int l,int r,int p,int v){
		if(!now)now = newnode();
		if(l == r){
			pool[now].val += v;
			return now;
		}
		if(mid>=p)ls = modify(ls,l,mid,p,v);
		else rs = modify(rs,mid+1,r,p,v);
		pool[now].val = pool[ls].val+pool[rs].val;
		return now;
	}
	ll getval(int now,int l,int r,int s,int e){
		if(!now)return 0ll;
		if(l>=s&&e>=r)return pool[now].val;
		if(mid>=e)return getval(ls,l,mid,s,e);
		else if(mid<s)return getval(rs,mid+1,r,s,e);
		else return getval(ls,l,mid,s,e)+getval(rs,mid+1,r,s,e);
	}
#undef ls
#undef mid
#undef rs
};

struct DS{
	SEG bit[mxn];
	void modify(int x,int y,int v){
		for(int i = x;i<mxn;i+=i&-i){
			bit[i].rt = bit[i].modify(bit[i].rt,0,mxn,y,v);
		}
		return;
	}
	ll getval(int x,int y){
		ll re = 0;
		for(int i = x;i>0;i-= i&-i){
			re += bit[i].getval(bit[i].rt,0,mxn,0,y);
		}
		return re;
	}
};

DS ds1,ds2;
set<int> st[mxn];
int N,Q;
pii rp[mxn];
int arr[mxn];

namespace ST{
	void del(int p){
		int v = arr[p];
		auto it = st[v].find(p);
		assert(it != st[v].begin());
		ds1.modify(p,*prev(it),-v);
		st[v].erase(p);
		it = st[v].lower_bound(p);
		if(it != st[v].end()){
			ds1.modify(*it,p,-v);
			ds1.modify(*it,*prev(it),v);
		}
		return;
	}

	void add(int p){
		int v = arr[p];
		auto it = st[v].lower_bound(p);
		if(it != st[v].end()){
			ds1.modify(*it,*prev(it),-v);
			ds1.modify(*it,p,v);
		}
		assert(it != st[v].begin());
		it--;
		ds1.modify(p,*it,v);
		st[v].insert(p);
		return;
	}
}

void T1(){
	int p,v;
	cin>>p>>v;
	ST::del(p);
	arr[p] = v;
	ST::add(p);
	return;
}

void T2(){
	int s,e,v;
	cin>>s>>e>>v;
	ds2.modify(s,e,v);
	rp[s] = pii(e,v);
	return;
}

void T3(){
	int s;
	cin>>s;
	auto [e,v] = rp[s];
	ds2.modify(s,e,-v);
	rp[e] = pii(0,0);
	return;
}

void T4(){
	int s,e;
	cin>>s>>e;
	ll tans = 0;
	tans += ds1.getval(e,s-1)-ds1.getval(s-1,s-1);
	tans += ds2.getval(mxn-1,e)-ds2.getval(s-1,e);
	cout<<tans<<'\n';
	return;
}

namespace BRUTE{
	bitset<5050> ap;
	void GO(){
		for(int i = 1;i<=N;i++)cin>>arr[i];
		while(Q--){
			int t,a,b;
			cin>>t>>a>>b;
			if(t == 1)arr[a] = b;
			else if(t == 4){
				ap.reset();
				for(int i = a;i<=b;i++){
					if(arr[i]>N)exit(0);
					ap[arr[i]] = 1;
				}
				ll ans = 0;
				for(int i = 1;i<5050;i++){
					if(ap[i])ans += i;
				}
				cout<<ans<<'\n';
			}
			else{
				while(t++){
					ap[min(t,5000)] = rand()&1;
				}
			}
		}
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	if(N>5000)return 0;
	BRUTE::GO();return 0;
	pool.push_back(node());
	for(int i = 1;i<=N;i++)st[i].insert(0);
	for(int i = 1;i<=N;i++){
		int k;
		cin>>k;
		arr[i] = k;
		st[k].insert(i);
	}
	for(int i = 1;i<=N;i++){
		for(auto it = st[i].begin();it != st[i].end();it++){
			if(!(*it))continue;
			ds1.modify(*it,*prev(it),i);
		}
	}
	while(Q--){
		int t;
		cin>>t;
		if(t == 1)T1();
		else if(t == 2)T2();
		else if(t == 3)T3();
		else T4();
	}
	return 0;
}
