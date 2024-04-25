#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2020;
string arr[mxn];

int row[mxn],col[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll ans= 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(arr[i][j] == 'o'){
				row[i]++,col[j]++;
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++){
			if(arr[i][j] == 'x')continue;
			ans += 1ll*(row[i]-1)*(col[j]-1);
		}
	}
	cout<<ans;
}
