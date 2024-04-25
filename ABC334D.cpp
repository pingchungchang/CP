#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 2e5+10;

int n,q;
vector<pll> v;
ll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	v.push_back(make_pair(0,0));
	ll sum = 0;
	for(int i = 1;i<=n;i++){
		sum += arr[i];
		v.push_back(make_pair(sum,i));
	}
	while(q--){
		ll k;
		cin>>k;
		cout<<lower_bound(v.begin(),v.end(),make_pair(k+1,-1ll))-v.begin()-1<<'\n';
	}
}
