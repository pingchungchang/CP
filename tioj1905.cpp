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
#define int ll
const ll inf = 2LL*INT_MAX;
const ll mxn = 1e5+10;
ll arr[mxn];
ll bit[mxn];
ll segtree[mxn*4];
void modify(ll p,ll v){
	p++;
	for(;p<mxn;p += p&-p)bit[p] = min(bit[p],v);
	return;
}
ll getval(int p){
	p++;
	ll re = inf;
	for(;p>0;p -= p&-p)re = min(re,bit[p]);
	return re;
}

void changeval(int now,int l,int r,ll p,ll v){
	if(l == r){
		segtree[now] = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)changeval(now*2+1,l,mid,p,v);
	else changeval(now*2+2,mid+1,r,p,v);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
}
ll getsmall(int now,int l,int r,int s,int e){
	if(s<=l&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getsmall(now*2+1,l,mid,s,e);
	else if(mid<s)return getsmall(now*2+2,mid+1,r,s,e);
	else return min(getsmall(now*2+1,l,mid,s,e),getsmall(now*2+2,mid+1,r,s,e));
}
main(){
	io
	ll n,q;
	cin>>n;
	vector<ll> all;
	for(auto &i:bit)i = inf;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		all.push_back(arr[i]);
	}
	for(auto &i:segtree) i = inf;
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	cin>>q;
	ll ans[q];
	for(auto &i:ans)i = inf;
	pair<pll,int> req[q];
	for(int i = 0;i<q;i++){
		cin>>req[i].fs.fs>>req[i].fs.sc;
		req[i].sc = i;
		req[i].fs.fs--,req[i].fs.sc--;
	}
	
//	cout<<endl<<endl;
	
	sort(req,req+q);
	int p = q-1;
	for(int i = n-1;i>=0;i--){
		int j = getsmall(0,0,n-1,lower_bound(_all(all),arr[i])-all.begin(),n-1);
		int pj = -1;
//		cout<<i<<' '<<j<<endl; 
		while(pj!=j&&j<n){
			pj = j;
			modify(j,arr[j]-arr[i]);
//			cout<<i<<' '<<j<<' '<<(arr[i]+arr[j])/2<<endl;
			j = getsmall(0,0,n-1,lower_bound(_all(all),arr[i])-all.begin(),--upper_bound(_all(all),(arr[i]+arr[j])/2)-all.begin());
		}
		if(i != n&&arr[i]<=arr[i+1]){
			modify(i+1,arr[i+1]-arr[i]);
		}
//		if(i == 0){
//			for(int kk = 0;kk<n;kk++)cout<<getval(kk)<<' ';cout<<endl;
//		}
		while(p>=0&&req[p].fs.fs == i){
			ans[req[p].sc] = min(ans[req[p].sc],getval(req[p].fs.sc));
			p--;
		}
		changeval(0,0,n-1,lower_bound(_all(all),arr[i])-all.begin(),i);
	}
//	for(int i = 0;i<q;i++)cout<<ans[i]<<' ';
//	return 0;
	for(auto &i:req){
		i.fs.fs = n-1-i.fs.fs;
		i.fs.sc = n-1-i.fs.sc;
		swap(i.fs.fs,i.fs.sc);
	}
	reverse(arr,arr+n);
	for(auto &i:bit)i = inf;
	p = q-1;
	for(auto &i:segtree)i = inf;
	sort(req,req+q);
	
//	cout<<endl;

	for(int i = n-1;i>=0;i--){
		int j = getsmall(0,0,n-1,lower_bound(_all(all),arr[i])-all.begin(),n-1);
		int pj = -1;
//		cout<<i<<' '<<j<<endl; 
		while(pj != j&&j < n){
			pj = j;
			modify(j,arr[j]-arr[i]);
			j = getsmall(0,0,n-1,lower_bound(_all(all),arr[i])-all.begin(),--upper_bound(_all(all),(arr[i]+arr[j])/2)-all.begin());
//			cout<<i<<' '<<j<<endl;
		}
		if(i != n&&arr[i]<=arr[i+1]){
			modify(i+1,arr[i+1]-arr[i]);
		}
		while(p>=0&&req[p].fs.fs == i){
//			cout<<req[p].fs.fs<<' '<<req[p].fs.sc<<' '<<req[p].sc<<endl;
			ans[req[p].sc] = min(ans[req[p].sc],getval(req[p].fs.sc));
			p--;
		}
		changeval(0,0,n-1,lower_bound(_all(all),arr[i])-all.begin(),i);
	}	for(int i= 0;i<q;i++){
		cout<<ans[i]<<"\n";
	}	
	return 0;
}
/*
10
10449 19727 11400 26418 13028 2026 7922 7231 3868 8296 
10
6 10
5 8
2 4
3 4
1 4
5 6
9 10
1 5
2 5
2 9
*/
