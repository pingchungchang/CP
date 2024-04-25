#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 4e18;
const ll mxn = 2e5+10;
set<pll> st;
ll pref[mxn],arr[mxn];
ll dp[mxn],pdp[mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],pref[i] = pref[i-1]+arr[i];
	st.insert(make_pair(0,0));
	for(int i = 1;i<=n;i++){
		auto it = st.lower_bound(make_pair(pref[i],inf));
		if(it != st.begin()){
			it--;
			dp[i] = it->sc+i;
		}
		pdp[i] = max(pdp[i-1],dp[i]);
		pll tmp = make_pair(pref[i],pdp[i]-i);
		it = st.insert(tmp).fs;
		while(next(it) != st.end()&&next(it)->sc<=tmp.sc){
			st.erase(next(it));
			it = st.find(tmp);
		}
	}
	cout<<pdp[n];
}
