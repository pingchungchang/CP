#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
const int mxn = 2e5+10;

multiset<int> ls,rs;
ll lsum,rsum;
int arr[mxn],brr[mxn];
int n,m;

void solve(){
	ls.clear();rs.clear();lsum = rsum = 0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=m;i++)cin>>brr[i];
	sort(arr+1,arr+n+1);
	sort(brr+1,brr+m+1);
	for(int i = 1;i<=n;i++){
		ls.insert(arr[i]);
		ls.insert(brr[i]);
		lsum += arr[i];
		lsum += brr[i];
	}
	while(ls.size()>rs.size()){
		rsum += *ls.rbegin();
		lsum -= *ls.rbegin();
		rs.insert(*ls.rbegin());
		ls.erase(ls.find(*ls.rbegin()));
	}
	ll ans = rsum - lsum;
	int pl = n,pr = m;
	for(;pl>0;pl--,pr--){
		int ta = brr[pl],tb = brr[pr];
		if(rs.find(ta) != rs.end()){
			rsum -= ta;
			rs.erase(rs.find(ta));
		}
		else{
			lsum -= ta;
			ls.erase(ls.find(ta));
		}
		rsum += tb;
		rs.insert(tb);
		while(rs.size()>ls.size()){
			ls.insert(*rs.begin());
			lsum += *rs.begin();
			rsum -= *rs.begin();
			rs.erase(rs.find(*rs.begin()));
		}
		ans = max(ans,rsum-lsum);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
