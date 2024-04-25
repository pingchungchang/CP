#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
int dp1[mxn],dp2[mxn],arr[mxn],lp[mxn];
vector<int> st;
int N;
const int mod = 998244353;

inline int mad(int a,int b){
	 a += b;
	 return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}

void solve(){
	st.clear();
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	st.push_back(0);
	for(int i = 1;i<=N;i++){
		while(arr[st.back()]>=arr[i])st.pop_back();
		lp[i] = st.back();
		st.push_back(i);
	}
	for(int i = 1;i<=N;i++){
		dp1[i] = dp1[i-1];
		dp1[i] = mad(dp1[i],mub(dp1[i],dp1[lp[i]]));
		if(!lp[i])dp1[i] = mad(dp1[i],1);
		dp1[i] = mad(dp1[i],dp2[lp[i]]);
		dp2[i] = mad(dp2[lp[i]],mub(dp1[i],dp1[i-1]));
	}
	//for(int i = 1;i<=N;i++)cout<<lp[i]<<' ';cout<<'\n';
	//for(int i = 1;i<=N;i++)cout<<mub(dp1[i],dp1[i-1])<<' ';cout<<'\n';
	int ans = 0;
	int mn = 1e9+10;
	for(int i = N;i>=1;i--){
		mn = min(mn,arr[i]);
		if(mn == arr[i]){
			ans = mad(ans,mub(dp1[i],dp1[i-1]));
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
