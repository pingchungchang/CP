#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


bool check(int k){
	return (k/100)*(k/10%10) == k%10;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = n;i<=999;i++){
		if(check(i)){
			cout<<i;
			return 0;
		}
	}
}
