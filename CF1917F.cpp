#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
bitset<mxn*2> dp[mxn*2];//dp[i] = dp[i]|dp[i-l]|(dp[i-l]<<l)
int N,D;
int arr[mxn*2];

void solve(){
	for(int i = 0;i<=D;i++)dp[i].reset();
	cin>>N>>D;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	sort(arr+1,arr+N+1);
	//for(int i = 1;i<=N;i++)cout<<arr[i]<<',';cout<<endl;
	int cnt = 0;
	for(int i = 1;i<=N;i++){
		cnt += (D/2+1<=arr[i]);
	}
	if(cnt>=2||arr[N]>D){
		cout<<"NO\n";
		return;
	}
	if(arr[N-1]+arr[N]>D){
		cout<<"NO\n";
		return;
	}
	dp[1][0] = 1;
	for(int i = 1;i<N;i++)dp[1] = dp[1]|(dp[1]<<arr[i]);
	if(dp[1][D-arr[N]]){
		cout<<"YES\n";
		return;
	}
	dp[1].reset();
	dp[0][0] = 1;
	for(int i = 1;i<N;i++){
		for(int j = D;j>=arr[i];j--){
			dp[j] = dp[j]|(dp[j-arr[i]])|(dp[j-arr[i]]<<arr[i]);
		}
	}
	for(int i = 0;i<=D;i++){
		if((arr[N]+i)*2<=D&&dp[D-arr[N]][i]){
			cout<<"YES\n";
			return;
		}
		else if(i*2<=D&&dp[D][i]&&i+arr[N]<=D&&D-i+arr[N]<=D){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
