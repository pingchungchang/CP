#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int st[mxn][20];
int arr[mxn];
int n;

inline int ask(int l,int r){
	int d = r-l+1;
	int h;
	for(int i = 0;i<20;i++)if(d&(1<<i))h = i;
	return min(st[l][h],st[r-(1<<h)+1][h]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		st[i][0] = arr[i];
	}
	for(int i = 1;i<20;i++){
		for(int j = 1;j+(1<<i)-1<=n;j++){
			st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i = 0;i<n;i++){
		int l,r;
		cin>>l>>r;
		cout<<ask(l,r)+1<<'\n';
	}
	return 0;
}
