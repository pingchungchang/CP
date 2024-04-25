#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int mxn = 61;
ll B = 59;
ll tar;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>tar;
	if(tar<=19){
		mxn = 5;
		B = 3;
	}
	string arr[mxn];
	for(int i = 0;i<mxn;i++){
		arr[i] = string(mxn,'d');
	}
	for(int i = 0;i<B;i++){
		arr[i+1][i] = 'X';
	}
	for(int i = 0;i<B;i++){
		arr[i][i] = 'd';
		arr[i+2][i] = 'r';
	}
	for(int i = 0;i<mxn;i++){
		arr[0][i] = arr[mxn-1][i] = 'r';
	}
	for(int i = 0;i<mxn;i++)arr[i][mxn-1] = 'd';
	arr[mxn-1][mxn-1] = '.';
	int c = 0;
	tar--;
	for(int i = mxn-2;i>=0;i--){
		if((1ll<<c)&tar)arr[0][i] = 'X';
		c++;
	}
	cout<<mxn<<' '<<mxn<<'\n';
	if(tar == 16){
		for(int i = 0;i+1<mxn;i++)arr[0][i] = 'X';
		arr[1][mxn-2] = 'X';
	}
	if(tar == 17){
		for(int i = 0;i+1<mxn;i++)arr[0][i] = 'X';
		arr[1][mxn-2] = 'X';
		arr[2][mxn-2] = 'X';
	}
	if(tar == 18){
		for(int i = 0;i+1<mxn;i++)arr[0][i] = 'X';
		arr[1][mxn-2] = arr[1][mxn-3] = 'X';
	}
	for(int i = 0;i<mxn;i++){
		cout<<arr[i]<<'\n';
	}
	return 0;
}

