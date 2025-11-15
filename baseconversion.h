#ifndef BASECONVERSION_H
#define BASECONVERSION_H

int frombase10tobaseb(int N, int b);
/*
Do numeric base conversion between a number in base 10 to a base b.
    Args:
        (int) N: Number in base 10
        (int) b: Numeric base

    Returns: 
        (int): N in base b
*/

int frombasebtobase10(int N, int b, int flags);
/*
Do numeric base conversion between a number in base b to a base 10 according to a specified method.
    Args:
        (int) N: Number in base b
        (int) b: Numeric base of N
        (int) flags: A flag to indicate which method to use.
            0 -> Parethensis method
            1 -> Sum method

    Returns: 
        (int): N in base 10
*/

#endif