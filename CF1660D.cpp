#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	for(int i = 0;i<n;i++)cin>>arr[i];
	arr[n] = 0;
	pair<int,pii> ans = make_pair(0,make_pair(0,0));
	vector<pii> seg;
	int p1 = 0;
	for(int i = 0;i<=n;i++){
		if(arr[i] == 0){
			seg.push_back(make_pair(p1,i));
			p1 = i+1;
		}
	}
	int pref[n+1] = {};
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		if(abs(arr[i-1]) == 2)pref[i]++;
	}
	for(auto now:seg){
		if(now.fs == now.sc)continue;
		int s = now.sc,b = now.fs;
		int cnt =0;
		for(int i = now.fs;i<now.sc;i++){
			if(arr[i]<0){
				cnt++;
				s = min(s,i);
				b = max(b,i);
			}
		}
		if(cnt %2 == 0&&ans.fs<pref[now.sc]-pref[now.fs]){
			ans = make_pair(pref[now.sc]-pref[now.fs],make_pair(now.fs,now.sc));
		}
		else if(cnt%2 != 0){
			if(ans.fs<pref[b]-pref[now.fs]){
				ans = make_pair(pref[b]-pref[now.fs],make_pair(now.fs,b));
			}
			if(ans.fs<pref[now.sc]-pref[s+1]){
				ans = make_pair(pref[now.sc]-pref[s+1],make_pair(s+1,now.sc));
			}
		}
//		cout<<ans.sc.fs<<' '<<ans.sc.sc<<'.';
//		cout<<s<<b<<'.';
	}
	cout<<ans.sc.fs<<' '<<n-ans.sc.sc<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

