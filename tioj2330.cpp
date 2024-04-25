#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
int n,m;
tlll arr[mxn];
pii metro[1010];
pii house[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		get<2>(arr[i]) = i;
	}
	for(int i = 1;i<=n;i++){
		cin>>house[i].fs>>house[i].sc>>get<1>(arr[i]);
		get<0>(arr[i]) = 9e18;
	}
	for(int i = 1;i<=m;i++)cin>>metro[i].fs>>metro[i].sc;
	for(int j = 1;j<=n;j++){
		for(int i = 1;i<=m;i++){
			get<0>(arr[j]) = min(1ll*(house[j].fs-metro[i].fs)*(house[j].fs-metro[i].fs)+
				1ll*(house[j].sc-metro[i].sc)*(house[j].sc-metro[i].sc),get<0>(arr[j]));
		}
	}
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++)cout<<get<2>(arr[i])<<'\n';
	return 0;
}
