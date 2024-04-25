#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 5e6+10;
pll pre[mxn];
int arr[mxn/10];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			ll t = arr[i]+arr[j];
			if(pre[t].fs == 0){
				pre[t] = {i,j};
				continue;
			}
			if(pre[t].fs != i&&pre[t].sc != i&&pre[t].fs != j&&pre[t].sc != j){
				cout<<"YES\n"<<pre[t].fs<<' '<<pre[t].sc<<' '<<i<<' '<<j;
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}
