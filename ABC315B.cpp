#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m;
	cin>>m;
	int arr[m];
	int total = 0;
	for(auto &i:arr)cin>>i,total += i;
	int sum = 0;
	for(int i =0;i<m;i++){
		for(int j = 1;j<=arr[i];j++){
			sum++;
			if(sum == total/2+1){
				cout<<i+1<<' '<<j;
				return 0;
			}
		}
	}
}
