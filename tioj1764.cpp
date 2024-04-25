#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 1e18;
const int mxn = 3e5+10;
vector<ll> all;
pll bit1[mxn],bit2[mxn];
ll arr[mxn];
ll N,M;
pll dp[mxn];

void modify(pll bit[],int p,pll v){
	for(;p<mxn;p+=p&-p){
		bit[p] = min(bit[p],v);
	}
	return;
}
pll getval(pll bit[],int p){
	pll re = pll(inf,inf);
	for(;p>0;p-= p&-p)re = min(re,bit[p]);
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	all = {-inf,0ll};
	for(int i = 1;i<=N;i++)cin>>arr[i],all.push_back(arr[i]+i);
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	for(auto &i:bit1)i = {inf,inf};
	for(auto &i:bit2)i = {inf,inf};
	int tmp = lower_bound(all.begin(),all.end(),arr[1]+1)-all.begin();
	modify(bit1,tmp,pll(-arr[1]-1,0));
	modify(bit2,mxn-1-tmp,pll(0,0));
	for(int i = 2;i<=N;i++){
		dp[i] = {inf,inf};
		int pos = lower_bound(all.begin(),all.end(),arr[i]+i)-all.begin();
		pll ta = getval(bit1,pos);
		ta.fs += arr[i]+i;
		ta.sc--;
		pll tb = getval(bit2,mxn-1-pos);
		tb.sc--;
		dp[i] = min(ta,tb);
		modify(bit2,mxn-1-pos,dp[i]);
		modify(bit1,pos,pll(dp[i].fs-i-arr[i],dp[i].sc));
	}
	cout<<min(M,-dp[N].sc);
}
