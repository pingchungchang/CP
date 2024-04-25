#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
int arr[mxn][mxn];
int n,k;
bool sh;

void square(int sr,int sc,int er,int ec,int tar){
	assert(tar%4 == 0);
	for(int i = sr+1;i<=er&&tar;i+=2){
		for(int j = sc+1;j<=ec&&tar;j+=2){
			arr[i-1][j-1] = arr[i][j] = arr[i-1][j] = arr[i][j-1] = 1;
			tar -= 4;
		}
	}
	return;
}

void rest(int tar){
	assert(tar%4 == 0);
	for(int i = 2;i<=n;i++){
		for(int j = 2;j<=n;j++){
			if(!arr[i][j] &&!arr[i-1][j]&&!arr[i][j-1]&&!arr[i-1][j-1])
				arr[i-1][j-1] = arr[i][j] = arr[i-1][j] = arr[i][j-1] = 1,tar -= 4;
			if(!tar)return;
		}
		if(!tar)return;
	}
	return;
}

inline bool check(){
	int r = 0,c = 0;
	int cnt = 0;
	for(int i = 1;i<=n;i++)r ^= arr[i][1],c ^= arr[1][i];
	for(int i = 1;i<=n;i++)for(int j =1;j<=n;j++)cnt += arr[i][j];
	if(cnt != k)return false;
	for(int i = 1;i<=n;i++){
		int tr = 0,tc = 0;
		for(int j = 1;j<=n;j++){
			tr ^= arr[j][i];
			tc ^= arr[i][j];
		}
		if(r != tr||c != tc)return false;
	}
	return true;
}

void solve(){
	for(int i = 0;i<=n;i++)for(int j = 0;j<=n;j++)arr[i][j] = 0;
	sh = false;
	cin>>n>>k;
	if(k>n*n-k)sh ^= 1,k = n*n-k;
	if(!k){
		cout<<"Yes\n";
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)cout<<sh<<' ';cout<<'\n';
		}
		return;
	}
	if(n==2&&k==2){
		cout<<"Yes\n0 1\n1 0\n";
		return;
	}
	if(k%2 == 1||(n != 2&&k == 2)){
		cout<<"No\n";
		return;
	}
	if(k%4 == 0)square(1,1,n,n,k);
	else{
		arr[1][1] = arr[2][1] = arr[1][2] = arr[3][2] = arr[3][3] = arr[2][3] = 1;
		rest(k-6);
	}
	if(!check()){
		cout<<"No\n";
		return;
	}
	cout<<"Yes\n";
	if(sh)for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++)arr[i][j] ^= 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)cout<<arr[i][j]<<' ';cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
