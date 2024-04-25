#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int arr[9][9] = {};
bool flag = false;

void dfs(int r,int c){
	cout<<r<<' '<<c;
	if(r == 9){
		flag = true;
		return;
	}
	if(arr[r][c] != 0){
		c++;
		r += c/9;
		c %= 9;
		dfs(r,c);
		return;
	}
	int cnt[10] = {};
	for(int i = 0;i<9;i++){
		cnt[arr[i][c]]++;
		cnt[arr[r][i]]++;
	}
	for(int i = r/3*3;i<r/3*3+3;i++){
		for(int j = c/3*3;j<c/3*3+3;j++){
			cnt[arr[i][j]]++;
		}
	}
	for(int i = 1;i<=9;i++){
		if(cnt[i] == 0){
			arr[r][c] = i;
			int c1 = c+1;
			int r1 =r+ c1/9;
			c1 %= 9;
			dfs(r1,c1);
			if(flag)return;
			arr[r][c] = 0;
		}
	}
	return;
}
int main(){
	string s;
	cin>>s;
	for(int i = 0;i<9;i++){
		for(int j = 0;j<9;j++){
			if(s[i*9+j] == '.')arr[i][j] = 0;
			else arr[i][j] = s[i*9+j]-'0';
		}
	}
	dfs(0,0);
	if(flag){
		for(int i = 0;i<9;i++)for(int j = 0;j<9;j++)cout<<arr[i][j];
	}
	else cout<<"No solution.\n";
}

//11................................................................................
