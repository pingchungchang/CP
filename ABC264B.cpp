#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	int r,c;
	cin>>r>>c;
	int arr[15][15];
	for(int i = 0;i<8;i++){
		for(int j = i;j<15-i;j++){
			for(int k = i;k<15-i;k++){
				arr[j][k] = (i&1);
			}
		}
	}
//	for(int i = 0;i<15;i++){
//		for(int j = 0;j<15;j++)cout<<arr[i][j];
//		cout<<endl;
//	}
	r--,c--;
	if(arr[r][c] == 0)cout<<"black";
	else cout<<"white";
}

