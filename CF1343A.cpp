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
	int sum = 1;
	for(int i = 1;i<30;i++){
		sum += (1<<i);
		if(n%sum == 0){
			cout<<n/sum<<'\n';
			return;
		}
	}
	assert(false);
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
