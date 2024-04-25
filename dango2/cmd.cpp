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
	string s = "input_0";
	for(int i = 1;i<=6;i++){
		string tmp = "a "+s+to_string(i)+".txt";
		cout<<i<<endl;
		system(tmp.c_str());
	}
	return 0;
}
