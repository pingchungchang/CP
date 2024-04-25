#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	int arr[n][n] = {};
	for(int i = 0;i<n;i++){
		int l = 1,r = n;
		for(int j = 0;j<n;j++){
			if(j%2 == 0){
				arr[i][j] = i*n+l;
				l++;
			}
			else {
				arr[i][j] = i*n+r;
				r--;
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)cout<<arr[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}

