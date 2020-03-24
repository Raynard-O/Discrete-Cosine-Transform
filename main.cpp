//discrete cosine transform
#include <bits/stdc++.h>

float pi = 3.142857;
const int row = 8 , col = 8;
using namespace std;

// DCT
int TransformTooDct(int ImageMatrix[][col])
{
    int i, j, k, l;

    // dct will store the discrete cosine transform
    float dct[row][col];

    float ci, cj, dct1, sum;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {

            // ci and cj depends on frequency as well as
            // number of row and columns of specified matrix
            if (i == 0)
                ci = 1 / sqrt(row);
            else
                ci = sqrt(2) / sqrt(col);
            if (j == 0)
                cj = 1 / sqrt(row);
            else
                cj = sqrt(2) / sqrt(col);

            // sum will temporarily store the sum of
            // cosine signals
            sum = 0;
            for (k = 0; k < row; k++) {
                for (l = 0; l < col; l++) {
                    dct1 = ImageMatrix[k][l] *
                           cos((2 * k + 1) * i * pi / (2 * row)) *
                           cos((2 * l + 1) * j * pi / (2 * col));
                    sum = sum + dct1;
                }
            }
            dct[i][j] = ci * cj * sum;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%f\t", dct[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main(int argc,  char* argv[])
{
    if (argc != 3) {
        std::cout << "set values for row and col" << std::endl;
       // exit(0);
    };


    int ImageMatrix[row][col] = { { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 } };
   TransformTooDct(ImageMatrix);
    return 0;
}

