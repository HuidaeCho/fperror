# Demonstration of a floating-point error in double-precision accumulation

```bash
$ make
cc -Wall -Werror   -c -o fperror.o fperror.c
cc  -o fperror fperror.o
$ ./fperror
# Demonstration of a floating-point error in double-precision accumulation

* Orthogonal cell-to-cell distance:     1.000000
* Diagonal cell-to-cell distance:       1.41421356237309514547
  Different from the code:              1.41421356237309504880
* Orthogonal cells:                     1414213563
* Diagonal cells:                       1000000000
* Correct orthogonal length (lo):       1414213563.000000
* Correct diagonal length (ld):         1414213562.373095
* lo > ld?                              1

Accumulating distances...

* Accumulated orthogonal length (loa):  1414213563.000000
* Accumulated diagonal length (lda):    1414213572.194878
* lo == loa?                            1 (correct)
* ld == lda?                            0 (incorrect but expected)
* loa > lda?                            0 (incorrect and not desired)
```
