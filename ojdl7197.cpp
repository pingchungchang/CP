#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int n,m;
int arr[mxn],brr[mxn];
bitset<mxn> done;

void solve(){
	cin>>n>>m;
	done.reset();
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=m;i++)cin>>brr[i];
	int pt = 0;
	for(int i = 1;i<=m;i++){
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
