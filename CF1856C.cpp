#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn  =1010;
const ll inf = 1e9;
ll sbit[mxn],cbit[mxn];
void modify(ll bit[],int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
ll getval(ll bit[],int s,int e){
	ll re = 0;
	for(;e>0;e-= e&-e)re +=bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll ans = *max_element(arr,arr+n);
	for(int i = 1;i<n;i++){
		ans = max(ans,min(arr[i-1]+k,arr[i]+1));
	}
	reverse(arr,arr+n);
	for(int i = 0;i<n;i++)arr[i] -= i;
	vector<ll> all;
	all.push_back(-inf);
	all.push_back(inf+1);
	for(auto &i:arr)all.push_back(i);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 1;i<n;i++){
		memset(cbit,0,sizeof(cbit));
		memset(sbit,0,sizeof(sbit));
		ll big = max(arr[i],arr[i-1]);
		ll small = arr[i];
		ll total = 0;
		for(int j = i;j<n;j++){
			total += max(0LL,arr[i]-arr[j]);
			auto tmp = lower_bound(all.begin(),all.end(),max(arr[i],arr[j]))-all.begin();
			modify(cbit,tmp,1);modify(sbit,tmp,all[tmp]);
			if(total>k)break;
			ll l = small,r = big;
			ll rest = k-total;
			while(l != r){
				ll mid = l+(r-l+1)/2;
				auto pos = lower_bound(all.begin(),all.end(),mid)-all.begin();
				if(getval(cbit,1,pos)*mid-getval(sbit,1,pos)>rest)r = mid-1;
				else l = mid;
			}
			auto pos = lower_bound(all.begin(),all.end(),l)-all.begin();
			//cout<<i<<' '<<j<<' '<<small<<' '<<total<<' '<<rest<<' '<<getval(cbit,1,pos)*l-getval(sbit,1,pos)<<endl;
			ans = max(ans,l+j);
		}
	}
	cout<<ans<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
