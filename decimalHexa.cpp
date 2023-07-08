#include <iostream>

using namespace std;

string decimalToHexa(int num){
    // Defining an answer varible for storing the converted answer
    string ans = "";
    // Defining a variable to set the state position
    int dec = 1;

    while (dec < num) {
        dec *= 16;
    }

    dec /= 16;

    while (dec > 0) {
        int last = num / dec;
        num -= last * dec;
        dec /=16;

        if (last <= 9) {
            ans = ans + to_string(last);
        }
        else {
            char ch = 'A' + last - 10;
            ans.push_back(ch);
        }
    }

    // Returning the answer variable.
    return ans;
}

int main() {
    int num;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<decimalToHexa(num);

    return 0;
}