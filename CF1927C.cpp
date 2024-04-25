#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 4e5+10;
int cnt[mxn];
int n,m,k;

void solve(){
	for(int i = 0;i<=k;i++)cnt[i] = 0;
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		if(tmp>k)continue;
		cnt[tmp]|=1;
	}
	for(int i = 0;i<m;i++){
		int tmp;
		cin>>tmp;
		if(tmp>k)continue;
		cnt[tmp]|=2;
	}
	int o = 0,e = 0;
	for(int i = 1;i<=k;i++){
		if(cnt[i] == 1)o++;
		else if(cnt[i] == 2)e++;
		else if(!cnt[i]){
			cout<<"NO\n";
			return;
		}
	}
	if(o<=k/2&&e<=k/2)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
