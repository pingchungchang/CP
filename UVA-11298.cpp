#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        if(s.size()==5){
            cout<<3<<endl;
            continue;
        }
        else if((s[0] == 'o'&&s[1] == 'n')||(s[0] == 'o'&&s[2] == 'e')||(s[1] == 'n'&&s[2] == 'e')){
            printf("%d\n",1);
        }
        else{
            printf("%d\n",2);
        }
    }
    return 0;
}
