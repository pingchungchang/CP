#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	pll coupons[m];
	for(auto &i:coupons)cin>>i.fs;
	for(auto &i:coupons)cin>>i.sc;
	sort(arr,arr+n);
	sort(coupons,coupons+m);
	int p = n-1;
	ll ans = 0;
	for(auto &i:arr)ans += i;
	for(int i = m-1;i>=0;i--){
		while(p>=0&&arr[p]>=coupons[i].fs){
			pq.push(0LL);
			p--;
		}
		if(!pq.empty()&&pq.top()<coupons[i].sc){
			ans += pq.top();
			pq.pop();
			ans -= coupons[i].sc;
			pq.push(coupons[i].sc);
		}
	}
	cout<<ans;
}
