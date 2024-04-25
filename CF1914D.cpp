#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
pii arr[mxn],brr[mxn],crr[mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].fs,arr[i].sc = i;
	for(int i = 0;i<n;i++)cin>>brr[i].fs,brr[i].sc = i;
	for(int i = 0;i<n;i++)cin>>crr[i].fs,crr[i].sc = i;
	sort(arr,arr+n,greater<pii>());
	sort(brr,brr+n,greater<pii>());
	sort(crr,crr+n,greater<pii>());
	int ans = 0;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			for(int k = 0;k<3;k++){
				int tmp[] = {arr[i].sc,brr[j].sc,crr[k].sc};
				sort(tmp,tmp+3);
				if(tmp[0] == tmp[1]||tmp[1] == tmp[2])continue;
				ans = max(ans,arr[i].fs+brr[j].fs+crr[k].fs);
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
