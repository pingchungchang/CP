#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


bitset<1010> locked;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int arr[n+1] = {};
	for(int i = 1;i<=k;i++){
		char c;
		int tmp;
		cin>>c>>tmp;
		locked[tmp] = true;
		if(c == 'L'){
			for(int i = tmp;i<=n;i++)arr[i]++;
		}
		else{
			for(int i = 1;i<=tmp;i++)arr[i]++;
		}
	}
	ll ans = 1;
	for(int i = 1;i<=n;i++){
		if(locked[i])continue;
		ans = ans*arr[i]%998244353;
	}
	cout<<ans;
}
