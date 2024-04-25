#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
ll n,m;
vector<ll> all;
ll rig[mxn],lef[mxn];
pll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	all.push_back(m);
	all.push_back(0);
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		all.push_back(arr[i].fs);
		all.push_back(arr[i].sc);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 0;i<n;i++){
		arr[i].fs = lower_bound(all.begin(),all.end(),arr[i].fs)-all.begin();
		arr[i].sc = lower_bound(all.begin(),all.end(),arr[i].sc)-all.begin();
		if(arr[i].fs>arr[i].sc){
			lef[arr[i].sc] ++;
			lef[arr[i].fs] --;
		}
		else{
			rig[arr[i].fs]++;
			rig[arr[i].sc]--;
		}
	}
	ll ans = 0;
	ll pl = 0,pr  =0;
	for(int i = 0;i+1<all.size();i++){
		pl += lef[i],pr += rig[i];
		ll mx = max(pl*2+1,pr*2-1);
		ans += (all[i+1]-all[i])*mx;
	}
	cout<<ans;
}
