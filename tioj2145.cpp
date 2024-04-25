#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = pow(3,7);
int arr[mxn][mxn];
int pw[8];

void calc(int sx,int sy,int len){
	if(len == 1){
		arr[sx+1][sy+1] = 1;
		return;
	}
	calc(sx,sy,len-1);
	int sz = pw[len-1];
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			if(!i&&!j)continue;
			for(int ii = 0;ii<sz;ii++){
				for(int jj = 0;jj<sz;jj++){
					arr[sx+sz*i+ii][sy+sz*j+jj] = arr[sx+ii][sy+jj];
				}
			}
		}
	}
	for(int i = 0;i<sz;i++){
		for(int j = 0;j<sz;j++){
			arr[sx+sz+i][sy+sz+j] = 1;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pw[0] = 1;
	for(int i = 1;i<8;i++)pw[i] = pw[i-1]*3;
	calc(0,0,n);
	for(int i = 0;i<pw[n];i++){
		for(int j =0 ;j<pw[n];j++){
			cout<<(arr[i][j]?'#':'.');
		}
		cout<<'\n';
	}
	return 0;
}
