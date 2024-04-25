#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll n,m;
const int mxn = 1e5+10;
ll arr[mxn];
pll ans1,ans2;

void modify(pll &now,ll val){
	if(!now.sc)now.fs += m;
	else if(val*now.sc>=now.fs)now.fs += m;
	now.sc++;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	srand(time(NULL));
	for(int i = 0;i<n;i++)cin>>arr[i];
	ans1 = {mxn*n,n};
	ans2 = {0ll,n};
	sort(arr,arr+n);
	int st = clock();
	ll mc = 0;
	for(int i = 0;i<n;i++)if(arr[i] == m)mc++;
	ans2.fs = m*min(n,mc+1);
	while(clock()-st<0.9*CLOCKS_PER_SEC){
		pll now = {0ll,0ll};
		for(int i = 0;i<n;i++){
			modify(now,arr[i]);
		}
		ans1.fs = min(ans1.fs,now.fs);
		ans2.fs = max(ans2.fs,now.fs);
		now = {0ll,0ll};
		for(int i = n-1;i>=0;i--){
			modify(now,arr[i]);
		}
		//cout<<now.fs<<' '<<now.sc<<endl;
		ans1.fs = min(ans1.fs,now.fs);
		ans2.fs = max(ans2.fs,now.fs);
		//if(ans1.fs*ans2.sc>ans1.sc*ans2.fs)swap(ans1,ans2);
		random_shuffle(arr,arr+n);
		break;
	}
	cout<<fixed<<setprecision(2)<<ans2.fs/(double)ans2.sc<<' '<<ans1.fs/(double)ans1.sc;
}
