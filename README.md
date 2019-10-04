# ft_printf
42 School Project | Representation of printf function

## Subject
The task was to rebuild the printf function with basic functionality called "ft_printf".
At 42, students are not allowed to use standard library functions. We can only submit wholly self-written functions.

ft_printf must achieve the following mandatory requirements:  
  
* Manage the following conversions: `s`, `p`, `d`, `i`, `o`, `u`, `x`, `X`, `c`
* Manage `%%`
* Manage the flags `#`, `0`, `-`, `+` & `space`
* Manage the minimum field-width
* Manage the precision
* Manage the flags `hh`, `h`, `l`, `ll`

## How to use
1. To compile, run `make`. This will compile **libftprintf.a**. 
2. To use, include `ft_printf.h` and use just like `printf`:
```
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s, %d", "Hello", 42);
	return (0);
}
```
3. Compile
```
gcc -o main main.c libftprintf.a
```
4. Run
```
./main
```

5.Output
```
Hello, 42
```
