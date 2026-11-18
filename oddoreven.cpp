#include <iostream>
using namespace std;
int prod (int a,int b) {
    return a*b;
}
bool iseven ( int n ) {
    if( n%2 == 0) {
        return true ;;
    } else {
        return false ;
    }
}
int main () {
    cout<< iseven(20)<<endl;
    return 0 ;
    }

