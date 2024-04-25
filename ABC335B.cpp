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
	int N;
	cin>>N;
	for(int i = 0;i<=N;i++){
		for(int j = 0;j<=N;j++){
			for(int k = 0;k<=N;k++){
				if(i+j+k<=N){
					cout<<i<<' '<<j<<' '<<k<<'\n';
				}
			}
		}
	}
	return 0;
}
