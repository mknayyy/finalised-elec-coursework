#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// 3x3 Array
double M[4][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {-3.0, -4.0, -5.0, -6.0},
    {10.0, 11.0, 12.0, 13.0}
};

void displayArray(const double A[][4])
{
    for (unsigned row=0; row<3; row++) {
        for (unsigned col=0; col<3; col++) {
            printf("%8.1f\t", A[row][col]);
        }
        printf("\n");
    }
}

// ***** WRITE YOUR FUNCTION HERE *****


// *****  END YOUR FUNCTION HERE  *****

int main()
{
    displayArray(M);

    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Create another 3x3 Array MT

    // 2. Write a nested loop to transpose M. Given Matrix A, the transpose A'[i][j]=A[j][i]
    //    For full marks, you must do this "in place" (without making another matrix) and as efficiently as possible

    // 3. Write a function to transpose a NxM array to a MxN array. Write code below to demonstrate it

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

