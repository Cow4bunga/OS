#include <iostream>
#include<string>
#include <sstream>
#include <cmath>
using namespace std;
const int number = 11;
int main() {
    string line, out;
    getline(cin,line);
    istringstream is(line);
    int x;
    long sum=0;
    while(is>>x){
        out.append(to_string(x*x*x) + " ");
    }
    cout<<out<<endl;
    return 0;
}