#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const ll inf = 1e9;
const int mxn = 1e5+10;
int n,m;
pii arr[mxn],brr[mxn];
ll dif[mxn*20];

namespace CHECK{
	ll pref[mxn*10];
	inline bool GO(ll C){
		for(int i = 1;i<mxn*10;i++){
			C += dif[i];
			pref[i] = pref[i-1]+C;
		}
		C = 0;
		for(int i = 0;i<m;i++){
			C += brr[i].fs;
			if(C>pref[brr[i].sc])return false;
		}
		return true;
	}
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	multiset<int> st;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	cin>>m;
	for(int i = 0;i<m;i++)cin>>brr[i].fs>>brr[i].sc;
	sort(arr,arr+n,[](pii a,pii b){return a.sc == b.sc?a.fs<b.fs:a.sc<b.sc;});
	sort(brr,brr+m,[](pii a,pii b){return a.sc == b.sc?a.fs<b.fs:a.sc<b.sc;});
	for(int i = 0;i<n;i++){
		auto it = st.lower_bound(arr[i].fs);
		if(it == st.begin()){
			st.insert(arr[i].sc);
		}
		else{
			it--;
			st.erase(it);
			st.insert(arr[i].sc);
		}
	}
	int l = st.size(),r = n;
	for(int i = 0;i<n;i++){
		dif[arr[i].fs]--;
		dif[arr[i].sc+1]++;
	}
	while(l != r){
		int mid = (l+r)>>1;
		if(CHECK::GO(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}
