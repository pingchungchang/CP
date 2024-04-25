#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a,b;
	cin>>a>>b;
	int m = (a+1)/2;
	if(m<b){
		cout<<-1<<'\n';
		return;
	}
	for(int i = 0;i<a;i++){
		for(int j = 0;j<a;j++){
			if(i == j&&b !=0&&i%2 == 0){
				b--;
				cout<<'R';
			}
			else cout<<'.';
		}
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		solve();
	}
}
