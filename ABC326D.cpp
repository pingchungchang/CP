#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>


struct node{
	int pos[3];
	string s;
	node(){}
};
const int mxn = 6;
string now[mxn];
int n;
string R,C;

inline bool check(){

	for(int i = 0;i<n;i++){
		int c = 0;
		for(int j = 0;j<n;j++){
			if(now[i][j] == '.')continue;
			if(!c&&now[i][j] != R[i])return false;
			if(c&(1<<(now[i][j]-'A')))return false;
			c|=1<<(now[i][j]-'A');
		}
		if(__builtin_popcount(c) != 3)return false;
	}
	for(int i = 0;i<n;i++){
		int c =0;
		for(int j = 0;j<n;j++){
			if(now[j][i] == '.')continue;
			if(!c&&now[j][i] != C[i])return false;
			if(c&(1<<(now[j][i]-'A')))return false;
			c|=1<<(now[j][i]-'A');
		}
		if(__builtin_popcount(c) != 3)return false;
	}

	return true;
}

void dfs(int row){
	if(row == n){
		if(check()){
			cout<<"Yes\n";
			for(int i = 0;i<n;i++)cout<<now[i]<<'\n';
			exit(0);
		}
		return;
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			for(int k = j+1;k<n;k++){
				now[row][i] = R[row];
				char r1 = 'A',r2 = 'B';
				if(R[row] == 'A')r1 = 'C';
				else if(R[row] == 'B')r2 = 'C';
				now[row][j] = r1;
				now[row][k] = r2;
				dfs(row+1);
				swap(now[row][j],now[row][k]);
				dfs(row+1);
				now[row][i] = now[row][j] = now[row][k] = '.';
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>R>>C;
	for(auto &i:now)i = string(n,'.');
	dfs(0);
	cout<<"No";
}
