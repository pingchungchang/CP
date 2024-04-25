#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,m,k;
int arr[55][55] = {};
int ans = INT_MAX;
int servers[55];
void solve(){
	for(int i =0;i<n;i++){
		cin>>servers[i];
	}
	int v[55][55] = {};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int from = servers[i];
			int to = j;
			v[from][to] += arr[i][j];
		}
	}
	int tmp = 0;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<m;j++){
			if(i == j){
				tmp += v[i][j];
			}
			else{
				if(v[i][j]>1000){
					tmp += (v[i][j]-1000)*2;
					v[i][j] = 1000;
				}
				tmp += 3*v[i][j];
			}
		}
	}
	ans = min(tmp,ans);
}
int main(){
	cin>>n>>m>>k;
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++)cin>>arr[i][j];
	}
	for(int i = 0;i<k;i++)solve();
	cout<<ans;
}

