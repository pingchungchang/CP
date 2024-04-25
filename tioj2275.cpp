#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e6+10;
const ll inf = 1e9+10;
pll arr[mxn];
string s;
deque<int> dq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	cin>>s;
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].sc;
		arr[i].sc += arr[i-1].sc;
		arr[i].fs += arr[i-1].fs+(s[i] == '1');
	}
	ll ans = 0;
	dq.push_back(0);
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&arr[i].fs-arr[dq.front()].fs>k)dq.pop_front();
		while(!dq.empty()&&arr[dq.back()].sc>=arr[i].sc)dq.pop_back();
		dq.push_back(i);
		ans = max(ans,arr[i].sc-arr[dq.front()].sc);
	}
	cout<<ans;
}
