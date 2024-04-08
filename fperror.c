#include <stdio.h>

int main()
{
    /* M_SQRT2 in /usr/include/math.h */
    double dd = 1.41421356237309504880;
    long no = 1414213563;
    long nd = 1000000000;

    /* correct lengths */
    double lo = no, ld = 1414213562.37309504880;
    long i;
    double loa, lda;

    printf
        ("# Demonstration of a floating-point error in double-precision accumulation\n");
    printf("\n");
    printf("* Orthogonal cell-to-cell distance:\t%f\n", 1.);
    printf("* Diagonal cell-to-cell distance:\t%.20f\n", dd);
    printf("  Different from the code:\t\t1.41421356237309504880\n");
    printf("* Orthogonal cells:\t\t\t%ld\n", no);
    printf("* Diagonal cells:\t\t\t%ld\n", nd);
    printf("* Correct orthogonal length (lo):\t%f\n", lo);
    printf("* Correct diagonal length (ld):\t\t%f\n", ld);
    printf("* lo > ld?\t\t\t\t%d\n", lo > ld);
    printf("\n");

    printf("Accumulating distances...\n");
    loa = lda = 0;
    for (i = 0; i < no; i++)
        loa += 1;
    for (i = 0; i < nd; i++)
        lda += dd;

    printf("\n");
    printf("* Accumulated orthogonal length (loa):\t%f\n", loa);
    printf("* Accumulated diagonal length (lda):\t%f\n", lda);
    printf("* lo == loa?\t\t\t\t%d (%s)\n", lo == loa,
           lo == loa ? "correct" : "incorrect");
    printf("* ld == lda?\t\t\t\t%d (%s)\n", ld == lda,
           ld == lda ? "correct" : "incorrect but expected");
    printf("* loa > lda?\t\t\t\t%d (%s)\n", loa > lda,
           loa > lda ? "correct" : "incorrect and not desired");
}
