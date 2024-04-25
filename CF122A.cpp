#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool f(int i){
	while(i != 0){
		if(i%10 != 4&&i%10 != 7)return false;
		i /=10;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		if(n%i == 0&&f(i)){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";

}

