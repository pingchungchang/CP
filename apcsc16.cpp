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

const int mxn = 1e5+10;
int bit[mxn];
bitset<mxn> used;
void modify(int p,int v){
	for(;p<mxn;p += p&-p)bit[p] += v;
}
int getval(int p){
	int re = 0;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
int main(){
	io
	int n;
	cin>>n;
	ll ans = 0;
	n *= 2;
	while(n--){
		int k;
		cin>>k;
		ans += getval(mxn-1)-getval(k);
		if(used[k])used[k] = false;
		else used[k] = true;
		if(!used[k])modify(k,-1);
		else modify(k,1);
	}
	cout<<ans;
}

