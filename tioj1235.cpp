#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string arr[9];
string now[9];
bool flag = false;
string all = "ROYGBIPLW";

void solve(int r,int c){
	//cout<<r<<' '<<c<<":"<<endl;
	//for(auto &i:now)cout<<i<<endl;
	if(r == 9){
		for(int i = 0;i<9;i++){
			for(int j = 0;j<9;j++){
				if(arr[i][j] == '*')cout<<now[i][j];
			}
			cout<<'\n';
		}
		exit(0);
	}
	if(now[r][c] != '*'){
		if(c == 8)solve(r+1,0);
		else solve(r,c+1);
	}
	else{
		int used = 0;
		for(int i = 0;i<9;i++){
			if(now[r][i] != '*')used |= 1<<(now[r][i]-'A');
			if(now[i][c] != '*')used |= 1<<(now[i][c]-'A');
		}
		int sr = r/3*3,sc = c/3*3;
		for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)if(now[sr+i][sc+j] != '*')used|=1<<(now[sr+i][sc+j]-'A');
		for(auto &i:all){
			//cout<<r<<' '<<c<<":"<<i<<endl;
			if(used&(1<<(i-'A')))continue;
			now[r][c] = i;
			if(c == 8)solve(r+1,0);
			else solve(r,c+1);
		}
		now[r][c] = '*';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:arr){
		cin>>i;
	}
	for(int i = 0;i<9;i++)now[i] = arr[i];
	solve(0,0);
	assert(false);
}
