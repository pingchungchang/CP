#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
int n,m;
int arr[mxn][8];
int able[1<<9];

inline pii calc(int k){
	memset(able,0,sizeof(able));
	for(int i = 1;i<=n;i++){
		int mask = 0;
		for(int j = 0;j<m;j++){
			if(arr[i][j]>=k)mask|=1<<j;
		}
		able[mask] = i;
	}
	for(int i = 0;i<(1<<m);i++){
		for(int j = 0;j<(1<<m);j++){
			if(!able[i]||!able[j])continue;
			if(__builtin_popcount(i|j) == m)return make_pair(able[i],able[j]);
		}
	}
	return make_pair(0,0);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j=0;j<m;j++)cin>>arr[i][j];
	}
	int l = 0,r = 1e9;
	while(l != r){
		int mid = (l+r+1)>>1;
		if(calc(mid).fs)l = mid;
		else r = mid-1;
	}
	pii re = calc(l);
	cout<<re.fs<<' '<<re.sc;
}
