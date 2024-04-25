#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string arr[3];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			if(arr[i][j] != arr[2-i][2-j]){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}
