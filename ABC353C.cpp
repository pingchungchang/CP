#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 1e8;
const int mxn = 3e5+10;
int N;
ll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0;i<N;i++)cin>>arr[i];
	sort(arr,arr+N);
	ll cnt = 0,sum = 0;
	int pt = 0;
	for(int i = N-1;i>=0;i--){
		while(pt<N&&arr[i]+arr[pt]<mod)pt++;
		cnt += N-(pt>i?pt:pt+1);
		sum += arr[i];
	}
	assert(cnt%2 == 0);
	cnt>>=1;
	ll ans = sum*(N-1)-mod*cnt;
	cout<<ans<<'\n';
	return 0;
}
