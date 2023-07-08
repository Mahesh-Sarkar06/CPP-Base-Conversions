#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int hexaToDecimal(string num){
    // Defining a result variable for storing the hexadecimal conversion result
    int ans = 0;

    // Defined a temporary variable which will get increased by 16 times
    int inc = 1;

    // Saving the size of the string
    int sz = num.size();

    // Taking a loop which will start from end of the string
    for (int i=sz-1; i>=0; i--){
        
        // Checking the condition if the character is between [0,9]
        if (num[i] >= '0' && num[i] <= '9') {
            
            // if condition is true then we will multiple the increment value with the current character value minus the 0 character value
            ans += inc * (num[i] - '0');
        }
        // If upper condition is false i.e., the character lies between [A-F]
        else if (num[i] >= 'A' && num[i] <= 'F') {
            
            // Now if condition is true then we have to fetch the position i.e., if it is A then it represent 10. So we are subracting
            // character 'A' & adding 10 to it then we will get the count from 10 to 15
            ans += inc * (num[i] - 'A' + 10);
        }

        // Now incrementing the variable by 16 times
        inc *= 16;
    }

    // Returning the converted hexadecimal number to decimal
    return ans;
}

int main() {
    string num;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<hexaToDecimal(num);

    return 0;
}