#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const ll mxn = 2e5+10;

multiset<ll> pool,act;
pll arr[mxn];
ll n,k,total;

void add(){
	act.insert(*pool.rbegin());
	total += *pool.rbegin();
	pool.erase(pool.find(*pool.rbegin()));
	return;
}

void solve(){
	pool.clear(),act.clear();
	cin>>n>>k;
	total = 0;
	for(int i = 0;i<n;i++)cin>>arr[i].fs;
	for(int i = 0;i<n;i++)cin>>arr[i].sc,total += arr[i].sc-arr[i].fs+1;
	if(total<k){
		cout<<"-1\n";
		return;
	}
	total = 0;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		if(arr[i].fs != arr[i].sc)pool.insert(arr[i].sc-arr[i].fs+1);
		sum += arr[i].sc-arr[i].fs+1;
	}
	ll ans = 1e18;
	ll m = k;
	for(int i = n-1;i>=0;i--){
		if(sum<k)break;
		ll len = arr[i].sc-arr[i].fs+1;
		if(pool.find(len)!=pool.end()){
			pool.erase(pool.find(len));
		}
		else if(act.find(len)!=act.end()){
			total -= len;
			act.erase(act.find(len));
		}
		while(!pool.empty()&&total<m){
			add();
		}
		ll r = arr[i].fs+max(0LL,m-total-1);
		//cout<<i<<":"<<ans<<','<<r<<','<<total<<'\n';
		if(total+len>=m)ans = min(ans,r+2LL*(ll)(act.size()+1));
		else ans = min(ans,arr[i].sc+2LL*(ll)(act.size()+1+m-total-len));
		sum -= len;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
