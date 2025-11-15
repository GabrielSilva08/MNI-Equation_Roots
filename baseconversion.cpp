#include "baseconversion.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int parenthesis_method(int N, int b);

int sum_method(int N, int b);

int frombase10tobaseb(int N, int b){
    int q = N, r, result; // quotient, remainder and final result
    std::vector<int> digits; // List of ints to track the b-ary digits 
    
    // Do successive divisions (storing the remainder) until q equals to 0
    while(q != 0){
        q = N / b;
        r = N % b;
        digits.push_back(r);
        N = q;
    }

    // Convert the list of digits into an integer
    result = digits[digits.size() - 1];
    for(int i = digits.size() - 2; i >= 0; i--){
        result = result * 10 + digits[i];
    }

    return result;
}

int frombasebtobase10(int N, int b, int flags){
    if(flags){
        return parenthesis_method(N, b);
    }
    return sum_method(N, b);
}

int parenthesis_method(int N, int b){
    /*
    Auxiliary function which implements the parenthesis convertion method.
    */
    std::string B_string = std::to_string(N);
    int size = B_string.size();
    // Get the most significative digit to an integer
    int B = static_cast<int>(B_string[0] - '0');

    for(int i = 1; i < size; i++){
        B = static_cast<int>(B_string[i] - '0') + b*B; // b_i = a_i + b x b_{i+1}
    }

    return B; // b_0
}

int sum_method(int N, int b){
    /*
    Auxiliary function which implements the sum convertion method.
    */
    std::string B_string = std::to_string(N);
    int size = B_string.size();
    int B = 0;
    // Compute the summation
    for(int i = 0; i < size; i++){
        B += static_cast<int>(B_string[i] - '0') * pow(b, (size-1) - i); // B = B[0] x b^(size-1) + B[1] x b^(size-2) + B[2] x b^(size-3) + B[3] x b^(size-4) + ...
    }

    return B;
}