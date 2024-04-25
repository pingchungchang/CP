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
	string s;
	cin>>s;
	int a =stoi(s.substr(0,2)),b = stoi(s.substr(2,2));
	if((a>12||a == 0)&&(b>12||b==0)){
		cout<<"NA";
	}
	else if((a<=12&&a != 0)&&(b<=12&&b != 0)){
		cout<<"AMBIGUOUS";
	}
	else if(a>12||a == 0){
		cout<<"YYMM";
	}
	else cout<<"MMYY";
}

