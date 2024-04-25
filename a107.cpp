#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> v(2);
pair<int,int> f(vector<string> &v,char c){
	for(int i = 0;i<5;i++){
		for(int j = 0;j<5;j++){
			if(v[i][j] == c)return make_pair(i,j); 
		}
	}
//	cout<<c<<endl;
	return make_pair(0,0);
}
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	char sss = s[0];
	v[0] = {"abcde","fghij","klmno","prstu","vwxyz"};
	v[1] = {"EXAMP","LBCDF","GHIJK","NORST","UVWYZ"};
	reverse(s.begin(),s.end());
	for(int i = 0;i<n;i+= 2){
		if(sss>='a'){
			pair<int,int> a,b;
			a = f(v[0],s[i]);
			b = f(v[0],s[i+1]);
//			cout<<a.first<<a.second<<b.first<<b.second<<endl;
			s[i] = v[1][a.first][b.second];
			s[i+1] = v[1][b.first][a.second];
		}
		else{
			pair<int,int> a,b;
			a = f(v[1],s[i]);
			b = f(v[1],s[i+1]);
			s[i] = v[0][a.first][b.second];
			s[i+1] = v[0][b.first][a.second];
		}
	}
	cout<<s;
	
}
