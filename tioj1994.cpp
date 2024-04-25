#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1<<12;
int arr[mxn][mxn];
pii dir[] = {{0,1},{1,0},{0,-1},{-1,0}};

void calc(int sx,int sy,int len){
	if(len == 0){
		arr[sx][sy] = 0;
		return;
	}
	int half = 1<<(len-1);
	calc(sx,sy,len-1);
	for(int i = 0;i<half;i++){
		for(int j = 0;j<half;j++){
			arr[sx+half+i][sy+j] = arr[sx+half+i][sy+half+j] = arr[sx+i][sy+half+j] = arr[sx+i][sy+j];
			arr[sx+half+i][sy+j] += half*half;
			arr[sx+half+i][sy+half+j] += half*half*2;
			arr[sx+i][sy+half+j] += half*half*3;
		}
	}
	for(int i = 0;i<half;i++){
		for(int j = 0;j+j<half;j++)swap(arr[sx+i][sy+half+j],arr[sx+i][sy+half+half-1-j]);
	}
	for(int i = 0;i<half;i++){
		for(int j = 0;j<i;j++){
			swap(arr[sx+i][sy+j],arr[sx+j][sy+i]);
			swap(arr[sx+i][sy+half+j],arr[sx+j][sy+half+i]);
		}
	}
	for(int i = 0;i<half;i++){
		for(int j = 0;j+j<half;j++)swap(arr[sx+i][sy+half+j],arr[sx+i][sy+half+half-1-j]);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	calc(0,0,n);
	for(int i= 0;i<(1<<n);i++){
		for(int j = 0;j<(1<<n);j++){
			//cout<<setw(3)<<arr[i][j]<<' ';
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
