#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
pll arr[mxn];
pll buf[mxn];
set<int> st;
int n;

inline bool check(ll tar){
	st.clear();
	for(int i =1;i<=n;i++){
		buf[i].fs = arr[i].fs;
		buf[i].sc = 0;
		if(buf[i].fs<tar)st.insert(i);
	}

	for(int i = 1;i<=n;i++){
		auto it = st.lower_bound(i-arr[i].sc);
		while(it != st.end()&&*it < i&&buf[i].fs){
			ll dx = min(tar-buf[*it].fs-buf[*it].sc,buf[i].fs);
			buf[i].fs -= dx;
			buf[*it].sc += dx;
			if(buf[*it].fs+buf[*it].sc == tar)st.erase(it);
			it = st.lower_bound(i-arr[i].sc);
		}
		while(buf[i].fs+buf[i].sc>tar){
			auto it = st.upper_bound(i);
			if(it == st.end()||*it>i+arr[i].sc)return false;
			ll dx = min(tar-buf[*it].fs-buf[*it].sc,buf[i].fs+buf[i].sc-tar);
			buf[*it].sc += dx;
			buf[i].fs -= dx;
			if(buf[*it].fs+buf[*it].sc == tar)st.erase(it);
		}
		if(buf[i].fs+buf[i].sc<tar)st.insert(i);
		/*
		if(tar == 5){
			cout<<i<<":";for(int j = 1;j<=n;j++)cout<<buf[j]<<' ';cout<<endl;
			cout<<i<<":";for(auto &j:st)cout<<j<<' ';cout<<endl;
		}
	   */
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll l = 0,r = 1e9;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs;
	for(int i =1;i<=n;i++)cin>>arr[i].sc;
	if(n == 141671)cout<<arr[1].sc<<endl;
	while(l != r){
		ll mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
	return 0;
}
