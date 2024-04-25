#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
#define pll pair<ll,ll>
#define fs first
#define sc second
#define int ll
#define ll long long

int bit1[mxn],bit2[mxn];
pll v[mxn];
int n,q;

inline void modify(int bit[],int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
inline int getval(int bit[],int p){
	int re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	int C = 0;
	int pt = 1;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		v[i].fs = C+1;
		v[i].sc = C+k;
		C += k;
		modify(bit2,i,v[i].sc-v[i].fs+1);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int tar;
			cin>>tar;
			int l = 1,r = n;
			while(l != r){
				int mid = (l+r)>>1;
				if(getval(bit2,mid)<tar)l = mid+1;
				else r = mid;
			}
			tar--;
			tar -= getval(bit2,l-1);
			int sh = getval(bit1,v[l].sc-v[l].fs+1);
			sh %= (v[l].sc-v[l].fs+1);
			tar -= sh;
			if(tar<0)tar += v[l].sc-v[l].fs+1;
			cout<<v[l].fs+tar<<'\n';
		}
		else{
			int k;
			cin>>k;
			int sum = 0;
			while(k--){
				sum += v[pt].sc-v[pt].fs+1;
				modify(bit2,pt,-((int)v[pt].sc-v[pt].fs+1));
				pt++;
			}
			if(sum<mxn)modify(bit1,sum,sum);
		}
	}
}
