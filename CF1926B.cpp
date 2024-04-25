#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	string arr[n];
	for(auto &i:arr)cin>>i;
	int l = n-1,r = 0,u = n-1,d = 0;
	for(int i= 0;i<n;i++){
		for(int j =0;j<n;j++){
			if(arr[i][j] == '1')l = min(l,j),r = max(r,j),u = min(u,i),d = max(d,i);
		}
	}
	int s = 0;
	for(int i = u;i<=d;i++){
		for(int j = l;j<=r;j++)s += arr[i][j]-'0';
	}
	cout<<(s == (r-l+1)*(d-u+1)?"SQUARE\n":"TRIANGLE\n");
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
