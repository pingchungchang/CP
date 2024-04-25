#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
ll bit1[mxn],bit2[mxn];
int arr[mxn];

void modify(ll bit[],int p,ll v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
ll getval(ll bit[],int p){
	ll re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

void solve(){
	int n;
	memset(bit1,0,sizeof(bit1));
	memset(bit2,0,sizeof(bit2));
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans += getval(bit2,arr[i]);
		modify(bit2,arr[i],getval(bit1,arr[i]));
		modify(bit1,arr[i],1);
	}
	memset(bit1,0,sizeof(bit1));
	memset(bit2,0,sizeof(bit2));
	for(int i = n;i>=1;i--){
		ans += getval(bit2,arr[i]);
		modify(bit2,arr[i],getval(bit1,arr[i]));
		modify(bit1,arr[i],1);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
