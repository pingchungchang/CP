#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int arr[9][9];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:arr)for(auto &j:i)cin>>j;
	bool flag = true;
	for(int i = 0;i<9;i++){
		int mask = 0;
		for(int j = 0;j<9;j++)mask |= 1<<(arr[i][j]-1);
		if(__builtin_popcount(mask) != 9)flag = false;
		mask = 0;
		for(int j= 0;j<9;j++)mask|=1<<(arr[j][i]-1);
		if(__builtin_popcount(mask) != 9)flag = false;
	}
	for(int i = 0;i<9;i+=3){
		for(int j = 0;j<9;j+=3){
			int mask = 0;
			for(int ii = 0;ii<3;ii++)for(int jj = 0;jj<3;jj++){
				mask |= 1<<(arr[i+ii][j+jj]-1);
			}
			if(__builtin_popcount(mask) != 9)flag = false;
		}
	}
	cout<<(flag?"Yes":"No");
}
