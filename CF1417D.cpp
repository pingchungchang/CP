#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


void solve(){
	int n;
	cin>>n;
	int arr[n+1] = {};
	int cnt[2] = {};
	ll sum = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i],cnt[arr[i]&1]++,sum += arr[i];
	if(sum%n != 0){
		cout<<"-1\n";
		return;
	}
	vector<tuple<int,int,int>> ans;
	ll tar = sum/n;
	for(int i = 2;i<=n;i++){
		if(arr[i]%i != 0){
			ans.push_back(make_tuple(1,i,i-arr[i]%i));
			arr[i] += i-arr[i]%i;
		}
		ans.push_back(make_tuple(i,1,arr[i]/i));
		arr[1] += arr[i]/i*i;
		arr[i] -= arr[i]/i*i;
	}
	for(int i = 2;i<=n;i++){
		ans.push_back(make_tuple(1,i,tar-arr[i]));
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
