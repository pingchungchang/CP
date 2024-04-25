#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int sum = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		sum += k;
	}
	if(sum == n)cout<<"0\n";
	else if(sum>n)cout<<sum-n<<'\n';
	else cout<<"1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
