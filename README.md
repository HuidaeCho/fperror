# Demonstration of a floating-point error in double-precision accumulation

```bash
$ make
cc -Wall -Werror   -c -o fperror.o fperror.c
cc  -o fperror fperror.o
cc -Wall -Werror   -c -o fperror_float.o fperror_float.c
cc  -o fperror_float fperror_float.o

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

## Accumulation of a float constant of sqrt(), the function itself, and its direct multiplication

```
$ ./fperror_float
init=210.0000000000
x=210.0000000000
dx=30*sqrt(2)=42.4264068604
y=210.0000000000
z=210.0000000000

 i          x+=dx  y+=30*sqrt(2) z=init+i*30*sqrt(2)           x-y           x-z
 1 252.4264068604 252.4264068604 252.4264068604       0.0000000000  0.0000000000
 2 294.8528137207 294.8528137207 294.8528137207       0.0000000000  0.0000000000
 3 337.2792358398 337.2792358398 337.2792358398       0.0000000000  0.0000000000
 4 379.7056274414 379.7056579590 379.7056274414      -0.0000305176  0.0000000000
 5 422.1320190430 422.1320800781 422.1320495605      -0.0000610352 -0.0000305176
 6 464.5584106445 464.5585021973 464.5584411621      -0.0000915527 -0.0000305176
 7 506.9848022461 506.9849243164 506.9848632812      -0.0001220703 -0.0000610352
 8 549.4111938477 549.4113159180 549.4112548828      -0.0001220703 -0.0000610352
 9 591.8375854492 591.8377075195 591.8376464844      -0.0001220703 -0.0000610352
10 634.2639770508 634.2640991211 634.2640991211      -0.0001220703 -0.0001220703
```
