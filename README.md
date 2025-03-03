# Matrix Math

Just put the header file in your project then define above the include

``` c
#define MATRIX_IMPLEMENTATION
#include "matrix.h"
```

You can also define custom malloc, free and assert functions. Define these above the include statement.

``` c
#define MATRIX_MALLOC customMalloc
#define MATRIX_FREE customFree
#define MATRIX_ASSERT customAssert
```

