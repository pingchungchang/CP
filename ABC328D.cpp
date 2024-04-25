#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


string st;
string s;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(auto &i:s){
		st += i;
		if(st.size()>=3&&st.end()[-3] == 'A'&&st.end()[-2] == 'B'&&st.end()[-1] == 'C'){
			for(int j = 0;j<3;j++)st.pop_back();
		}
	}
	cout<<st;
}
