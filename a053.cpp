#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        int s = n/10;
        if(n>=40){
            cout<<100<<endl;
        }
        else if(s == 0){
            cout<<6*n<<endl;
        }
        else if(s == 1){
            cout<<60+2*(n%10)<<endl;
        }
        else if(s >= 2){
            cout<<80+n%20<<endl;
        }
    }
    return 0;
}
