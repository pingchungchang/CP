#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string arr[10];
inline bool check(){
	for(int i = 0;i<10;i++){
		for(int j = 0;j<10;j++){
			if(arr[i][j] != 'X')continue;
			if(i+5<=10){
				int C = 0;
				for(int k = 0;k<5;k++)if(arr[i+k][j] == 'X')C++;
				if(C == 5)return true;
			}
			if(j+5<=10){
				int C = 0;
				for(int k = 0;k<5;k++)if(arr[i][j+k] == 'X')C++;
				if(C == 5)return true;
			}
			if(i+5<=10&&j+5<=10){
				int C = 0;
				for(int k = 0;k<5;k++)if(arr[i+k][j+k] == 'X')C++;
				if(C == 5)return true;
			}
			if(i+5<=10&&j-4>=0){
				int C = 0;
				for(int k = 0;k<5;k++)if(arr[i+k][j-k] == 'X')C++;
				if(C == 5)return true;
			}
		}
	}
	return false;
}

void solve(){
	int n = 10;
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++){
		if(arr[i][j] == '.')arr[i][j] = 'X';
		else continue;
		if(check()){
			cout<<"YES\n";
			return;
		}
		arr[i][j] = '.';
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
