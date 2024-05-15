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
	int sum = 0;
	for(int i = 0;i<9;i++){
		int k;
		cin>>k;
		sum += k;
	}
	sum++;
	for(int i = 0;i<8;i++){
		int k;
		cin>>k;
		sum -= k;
	}
	cout<<max(0,sum);
}
