#include <iostream>

using namespace std;

int octalToDecimal(int num){
    // Defining a result variable for storing the octal conversion result
    int ans = 0;
    // Defined a temporary variable which will get increased by 8 times
    int inc = 1;

    // Defined a loop till the number is greater than 0
    while(num > 0){
        // Defined a last variable which will take the last digit from the number
        int last = num % 10;
        // Now adding the ans variable to the converted binary value to decimal (last digit * 8^n) n= 0,1,2,3...
        ans += last * inc;
        // Incrementing the inc variable to multiplicative factor of 8
        inc *= 8;
        // Now Removing the last digit from the number
        num /= 10;
    }

    // Returning the converted octal number to decimal
    return ans;
}

int main() {
    int num;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<octalToDecimal(num);

    return 0;
}