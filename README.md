*This project has been created as part of the 42 curriculum by spuschma.*

# Description
This project recreates a basic version of `printf()`.
It handles conversion of `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` and escapes `%%`.
The function always writes up until the next '%' or '\0' at once. For handling variables it dispatches to the appropriate functions.

# Instructions
To use the library build it using `make`. `make clean` removes old object and dependency files, `make fclean` also removes the library and `make re` cleans and builds the library again.
To use the library `#include "ft_printf.h"` and compile with 
```shell
cc main.c -I path/to/ft_printf path/to/ft_printf/libftprintf.a
```

# Resources
The main reference for this project was the `printf()` man page.
The new concept in this project was **variadic functions** using `va_start`, `va_arg` and `va_end`. Here also the man page and asking peers were the main resources.

## AI Usage
This entire project is ***✨handgedacht✨***. No AIs were used in the making of this project.
In the very end Claude was used to see if I missed anything.
