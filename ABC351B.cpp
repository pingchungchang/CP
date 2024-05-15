#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 110;
int N,M;
string arr[mxn],brr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	M = N;
	for(int i = 0;i<N;i++)cin>>arr[i];
	for(int i = 0;i<N;i++)cin>>brr[i];
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			if(arr[i][j] != brr[i][j]){
				cout<<i+1<<' '<<j+1<<'\n';
			}
		}
	}
	return 0;
}
