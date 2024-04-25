#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



const int mxn = 55;
int n,m;
string arr[mxn];
pii x,y;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	x = {n,0},y = {m,0};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == '*')x.fs = min(x.fs,i),x.sc = max(x.sc,i),y.fs = min(y.fs,j),y.sc = max(y.sc,j);
		}
	}
	for(int i = x.fs;i<=x.sc;i++){
		for(int j = y.fs;j<=y.sc;j++)cout<<arr[i][j];
		cout<<'\n';
	}
}
