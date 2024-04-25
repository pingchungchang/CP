#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define mid (((ll)l+r)>>1)
const int mxn = 2e5+10;

struct node{
	int pl,pr;
	ll val;
};
int ppp = 0;
node segtree[mxn*30];
int roots[mxn];

int newnode(int ref){
	ppp++;
	assert(ppp<mxn*30);
	segtree[ppp].pl = segtree[ref].pl;
	segtree[ppp].pr = segtree[ref].pr;
	segtree[ppp].val = segtree[ref].val;
	return ppp;
}

void modify(int now,int l,int r,int p,ll v){
	if(l == r){
		segtree[now].val = v;
		return;
	}
	if(mid>=p){
		segtree[now].pl = newnode(segtree[now].pl);
		modify(segtree[now].pl,l,mid,p,v);
	}
	else{
		segtree[now].pr = newnode(segtree[now].pr);
		modify(segtree[now].pr,mid+1,r,p,v);
	}
	segtree[now].val = segtree[segtree[now].pl].val^segtree[segtree[now].pr].val;
	return;
}

ll getval(int now,int l,int r,int s,int e){
	if(!now)return 0;
	if(l>=s&&e>=r){
		return segtree[now].val;
	}
	ll re = 0;
	if(mid>=s){
		auto tmp = getval(segtree[now].pl,l,mid,s,e);
		re ^= tmp;
	}
	if(mid<e){
		auto tmp = getval(segtree[now].pr,mid+1,r,s,e);
		re ^= tmp;
	}
	return re;
}

void pv(int now,int l,int r){
	if(!now)return;
	cout<<l<<','<<r<<":"<<segtree[now].val<<endl;
	pv(segtree[now].pl,l,mid);
	pv(segtree[now].pr,mid+1,r);
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	srand(time(NULL));
	cin>>n;
	vector<int> all;
	int arr[n+1] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i],all.push_back(arr[i]);
	all.push_back(-1);
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	vector<int> vals[n+1];
	for(int i = 1;i<=n;i++){
		arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
		vals[arr[i]].push_back(i);
	}
	ll hval[n+1];
	for(int i = 1;i<=n;i++){
		int r1 = rand(),r2 = rand(),r3 = rand();
		hval[i] = (r1<<8)|(r2<<16)|(r3);
	}
	roots[0] = 0;
	for(int i = 1;i<=n;i++){
		roots[i] = newnode(roots[i-1]);
		for(auto &j:vals[i])modify(roots[i],1,n,j,hval[i]);
		/*
		cout<<i<<":";
		for(auto &j:vals[i])cout<<j<<' ';cout<<endl;
	    */
	}
	//for(int i = 1;i<=n;i++)cout<<hval[i].fs<<','<<hval[i].sc<<endl;
	//pv(roots[n],1,n);
	ll ans = 0;
	int q;cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l ^= ans;
		r ^= ans;
		//cout<<l<<','<<r<<'\n';
		ll re = getval(roots[n],1,n,l,r);
		if(re == 0){
			cout<<(ans = 0)<<'\n';
			continue;
		}
		int s = 1,e = n;
		while(s != e){
			int mm = (s+e)>>1;
			auto re = getval(roots[mm],1,n,l,r);
			if(re == 0)s = mm+1;
			else e = mm;
		}
		cout<<(ans = all[e])<<'\n';
	}
	return 0;
}
