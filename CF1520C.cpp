#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int arr[110][110];

void solve(){
	int n;
	cin>>n;
	if(n == 2){
		cout<<"-1\n";
		return;
	}
	int C = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			arr[i][j] = C;
			C+=2;
			if(C>n*n)C = 2;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
/*
1 3 5
7 9 2
4 6 8
1 3 5 7
9 11 13 15
2 4 6 8
10 12 14 16
*/
