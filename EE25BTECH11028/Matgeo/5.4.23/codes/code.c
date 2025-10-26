#include <stdio.h>

int main() {
    float a, b, c, d;
    float det;
    
    // Input matrix
    printf("Enter the elements of 2x2 matrix:\n");
    scanf("%f %f", &a, &b);
    scanf("%f %f", &c, &d);

    // Determinant
    det = a * d - b * c;

    if (det == 0) {
        printf("Inverse does not exist (determinant = 0)\n");
        return 0;
    }

    printf("Determinant = %.2f\n", det);

    // Inverse formula:  1/det * [ d   -b ]
    //                             [ -c   a ]
    float inv_a =  d / det;
    float inv_b = -b / det;
    float inv_c = -c / det;
    float inv_d =  a / det;

    printf("Inverse matrix is:\n");
    printf("%.2f   %.2f\n", inv_a, inv_b);
    printf("%.2f   %.2f\n", inv_c, inv_d);

    return 0;
}