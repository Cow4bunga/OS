#include <iostream>
#include<string>
#include <sstream>
using namespace std;
const int number = 11;
int main() {
    string line, out;
    getline(cin,line);
    istringstream is(line);
    int x;
    long sum=0;
    while(is>>x){
        sum+=x;
    }
    cout<<sum<<endl;
    return 0;
}