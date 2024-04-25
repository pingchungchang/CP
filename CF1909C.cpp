#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	pii arr[n*2];
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs;
		arr[i].sc = 1;
	}
	for(int i = 0;i<n;i++)cin>>arr[i+n].fs,arr[i+n].sc = -1;
	int brr[n];
	for(auto &i:brr)cin>>i;
	sort(brr,brr+n);
	vector<int> st,v;
	sort(arr,arr+n*2);
	for(auto &i:arr){
		if(i.sc>0)st.push_back(i.fs);
		else{
			v.push_back(i.fs-st.back());
			st.pop_back();
		}
	}
	sort(v.rbegin(),v.rend());
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ans += 1ll*v[i]*brr[i];
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
