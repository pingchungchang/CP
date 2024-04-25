#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int arr[mxn],brr[mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	bool done[n+1] = {};
	set<pll> st;
	for(int i = 1;i<=n;i++){
		st.insert(make_pair(arr[i]+brr[i],i));
	}
	pll sum = {0ll,0ll};
	for(int i = 1;i<=n;i++)sum.fs += arr[i],sum.sc += brr[i];
	for(int i = 1;i<=n;i++){
		if(i&1){
			sum.fs--;
			auto it = st.rbegin();
			sum.sc -= brr[it->sc];
			st.erase(st.find(*it));
		}
		else{
			sum.sc--;
			auto it = st.rbegin();
			sum.fs -= arr[it->sc];
			st.erase(st.find(*it));
		}
	}
	cout<<sum.fs-sum.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
