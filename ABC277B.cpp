#include <bits/stdc++.h>
using namespace std;

int main(){
	set<string> st;
	int n;
	cin>>n;
	set<char> head,tail;
	head.insert('H');head.insert('D');head.insert('C');head.insert('S');
	tail.insert('K');tail.insert('J');tail.insert('Q');tail.insert('T');
	for(char i = '2';i <='9';i++)tail.insert(i);tail.insert('A');
	for(int i = 0;i<n;i++){
		string t;
		cin>>t;
		if(head.find(t[0]) == head.end()||tail.find(t[1]) == tail.end()){
			cout<<"No\n";
			return 0;
		}
		else if(st.find(t) != st.end()){
			cout<<"No\n";
			return 0;
		}
		st.insert(t);
	}
	cout<<"Yes";
	return 0;
}
