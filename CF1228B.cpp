#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1010;
const int mod = 1e9+7;
int arr[mxn][mxn];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++)arr[i][j] = 1;
		arr[i][k] = 2;
	}
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			if(arr[j][i] == 2){
				cout<<0;
				return 0;
			}
			arr[j][i] = 2;
		}
		if(arr[k][i] == 1){
			cout<<0;
			return 0;
		}
		arr[k][i] = 2;
	}
	int ans = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == 0)ans = ans*2%mod;
		}
	}
	cout<<ans;
}
