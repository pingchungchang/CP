#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	int n,p;
	cin>>n>>p;
	p--;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	deque<pll> dq;
	pll right = {0,0};
	ll now = 0;
	bool flag = true;
	bool ans = false;
	dq.push_back({INT_MAX,0});
	for(int i = p+1;i<n;i++){
		dq.push_back({min(arr[i],dq.back().fs),arr[i]});
	}
	for(int i = p;i>=0;i--){
		while(!dq.empty()&&now+right.fs+dq.front().sc>=0){
			right.fs +=dq.front().sc;
			right.sc = max(right.fs,right.sc);
			dq.pop_front();
		}
		if(now+right.sc+arr[i]<0){
			flag = false;
			break;
		}
		now += arr[i];
	}
	ans |= flag;
	
	reverse(arr,arr+n);
	dq.clear();
	p = n-1-p;
	right = {0,0};
	now = 0;
	flag = true;
	dq.push_back({INT_MAX,0});
	for(int i = p+1;i<n;i++){
		dq.push_back({min(arr[i],dq.back().fs),arr[i]});
	}
	for(int i = p;i>=0;i--){
		while(!dq.empty()&&now+right.fs+dq.front().sc>=0){
			right.fs +=dq.front().sc;
			right.sc = max(right.fs,right.sc);
			dq.pop_front();
		}
		if(now+right.sc+arr[i]<0){
			flag = false;
			break;
		}
		now += arr[i];
	}
	ans |= flag;
	if(ans)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

