#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 4e5+10;
const int B = 60;
const int thres = 32;

struct mat{
	ll base[B];
	mat(){
		memset(base,0,sizeof(base));
	}
	ll* operator[](int k)const{
		return (ll*)base[k];
	}
	ll add(ll k){
		for(int i = B-1;i>=0;i--){
			if(k&(1ll<<i)){
				if(!base[i]){
					base[i] = k;
					break;
				}
				else k^= base[i];
			}
		}
		return k;
	}
	mat operator+(mat b)const{
		mat re = b;
		for(int i = 0;i<B;i++)re.add(base[i]);
		return re;
	}
};

deque<mat> pref[mxn*4],suf[mxn*4];
ll arr[mxn];
ll N,Q;

#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2

void build(int now,int l,int r){
	if(r-l+1<=thres)return;
	if(l == r){
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	if(!now)return;
	if(mid-l+1>thres)pref[now] = pref[ls];
	else{
		pref[now].push_back(mat());
		pref[now].back().base[__lg(arr[l])] = arr[l];
		for(int i = l+1;i<=mid;i++){
			pref[now].push_back(pref[now].back());
			pref[now].back().add(arr[i]);
		}
	}
	if(r-mid>thres)suf[now] = suf[rs];
	else{
		suf[now].push_back(mat());
		suf[now].back().base[__lg(arr[l])] = arr[l];
		for(int i = r-1;i>mid;i--){
			suf[now].push_front(suf[now].front());
			suf[now].front().add(arr[i]);
		}
	}
	for(int i = mid+1;i<=r;i++){
		pref[now].push_back(pref[now].back());
		pref[now].back().add(arr[i]);
	}
	for(int i = mid;i>=l;i--){
		suf[now].push_front(suf[now].front());
		suf[now].front().add(arr[i]);
	}
	return;
}

bool getval(int now,int l,int r,int s,int e,ll v){
	if(r-l+1<=thres*2){
		mat re;
		for(int i = s;i<=e;i++)re.add(arr[i]);
		return re.add(v);
	}
	if(mid>=s&&mid<e){
		auto re = suf[ls].end()[s-mid-1]+pref[rs][r-mid-1];
		return re.add(v);
	}
	if(mid>=e)return getval(ls,l,mid,s,e,v);
	else return getval(rs,mid+1,r,s,e,v);
}

#undef ls
#undef rs
#undef mid

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	build(0,1,N);
	while(Q--){
		int l,r;
		ll v;
		cin>>l>>r>>v;
		auto re = getval(0,1,N,l,r,v);
		cout<<(!re?"Yes\n":"No\n");
	}
	return 0;
}
