#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3030;
int arr[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int h,w;
	cin>>h>>w;
	for(int i = 1;i<=h;i++)for(int j= 1;j<=w;j++)arr[i][j] = 1;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		pii tmp;
		cin>>tmp.fs>>tmp.sc;
		arr[tmp.fs][tmp.sc] = 0;
	}
	for(int i = 1;i<=h;i++){
		for(int j =1;j<=w;j++)arr[i][j] = arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
	}
	ll ans = 0;
	for(int i = 1;i<=h;i++){
		for(int j = 1;j<=w;j++){
			int l = 0,r = min(i,j);
			while(l != r){
				int mid = (l+r+1)>>1;
				int sum = arr[i][j]-arr[i-mid][j]-arr[i][j-mid]+arr[i-mid][j-mid];
				if(sum == mid*mid)l = mid;
				else r = mid-1;
			}
			ans += l;
		}
	}
	cout<<ans;
}
