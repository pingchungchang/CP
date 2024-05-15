#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
bitset<mxn> bit[mxn];

void modify(int r,int c){
	for(int i = r;i<mxn;i+=i&-i){
		for(int j = c;j<mxn;j+=j&-j){
			bit[i][j] = bit[i][j]^1;
		}
	}
	return;
}
int getval(int r,int c){
	int re = 0;
	for(int i = r;i>0;i-= i&-i){
		for(int j = c;j>0;j-= j&-j){
			re ^= bit[i][j];
		}
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<mxn;i++){
		modify(i,i);
		cout<<getval(i,i);
	}
	return 0;
}
