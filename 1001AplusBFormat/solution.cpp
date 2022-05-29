#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

extern "C" {
    #include <math.h>
}

using namespace std;

vector<char> seprated(long num) {
    string str = to_string(num);
    reverse(str.begin(), str.end());
    
    int ccounter = 0;

    vector<char> vect;

    for(char c : str) {
        vect.push_back(c);
        ccounter++;
        if(ccounter % 3 == 0 && ccounter < str.length()) {
            vect.push_back(',');
        }
    }
    reverse(vect.begin(), vect.end());
    return vect;
}

int main(void) {
    long num1, num2;
    cin >> num1 >> num2;
    long sum = num1 + num2;
    int flag = sum < 0 ? 1 : 0;
    auto res = seprated(abs(sum));
    cout << (flag == 1 ? "-" : "");
    for(char c : res) {
        cout << c;
    }
}