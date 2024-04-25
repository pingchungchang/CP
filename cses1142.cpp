#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n;
int arr[mxn];
int len[mxn];
deque<int> dq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	dq.push_back(0);
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&arr[dq.back()]>=arr[i])dq.pop_back();
		len[i] = i-dq.back();
		dq.push_back(i);
	}
	dq = {n+1};
	for(int i = n;i>=1;i--){
		while(!dq.empty()&&arr[dq.back()]>=arr[i])dq.pop_back();
		len[i] += dq.back()-i-1;
		dq.push_back(i);
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans = max(ans,1ll*len[i]*arr[i]);
	}
	cout<<ans;
}
