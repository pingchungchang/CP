#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n;
	cin>>n;
	if(n == 1){
		cout<<-1;
		return 0;
	}
	cout<<n<<' '<<n+1<<' '<<n*n+n;
	return 0;
}
