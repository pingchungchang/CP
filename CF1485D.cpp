#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(auto &i:arr)for(auto &j:i)cin>>j;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			arr[i][j] = pow(arr[i][j],4);
			if((i+j)&1)arr[i][j] = 720720;
			else arr[i][j] += 720720;
		}
	}
	for(auto &i:arr){for(auto &j:i)cout<<j<<' ';cout<<'\n';}
}
