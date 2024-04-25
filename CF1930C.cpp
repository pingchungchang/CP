#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
int arr[mxn],n;

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],arr[i]+=i;
	sort(arr+1,arr+n+1);
	int pt = 2e9;
	vector<int> ans;
	for(int i = n;i>=1;i--){
		ans.push_back(min(arr[i],pt-1));
		pt = ans.back();
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
