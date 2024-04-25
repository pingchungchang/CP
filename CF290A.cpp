#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


vector<string> v;
string s[] = 
{
	"Washington","Adams","Jefferson","Madison","Monroe","Adams","Jackson","Van Buren","Harrison","Tyler","Polk","Taylor","Fillmore","Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes","Garfield","Arthur","Cleveland","Harrison","Cleveland","McKinley","Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt","Truman","Eisenhower","Kennedy","Johnson","Nixon","Ford","Carter","Reagan"
};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	/*
	for(int i = 0;i<40;i++){
		string in;
		getline(cin,in);
		v.push_back(in);
	}
	cout<<"{";for(int i = 0;i<40;i++){
		cout<<(i?",":"")<<"\""<<v[i]<<"\"";
	}cout<<"}";return 0;

   */
	int n;
	cin>>n;
	cout<<s[n-1];
}
