#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int arr[10][10] = {};
	for(int i = 1;i<=8;i++){
		for(int j = 1;j<=8;j++){
			char c;
			cin>>c;
			if(c == '#')arr[i][j] = 1;
		}
	}
	for(int i = 1;i<=8;i++){
		for(int j = 1;j<=8;j++){
			int sum = 0;
			for(int dx = -1;dx<=1;dx++){
				for(int dy = -1;dy<=1;dy++)sum += arr[i+dx][j+dy];
			}
			if(sum>=5){
				cout<<i<<' '<<j<<'\n';
				return;
			}
		}
	}
	cout<<"ERROR\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

