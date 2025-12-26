*This project has been created as part of the 42 curriculum by **amansir**.*

# push_swap
Because `Swap_push` doesn’t feel as natural

## Description

The **ft_printf** project consists of recreating the standard C library function
`printf()`.

The objective is to gain a deep understanding of:
- Variadic functions in C (`va_list`, `va_start`, `va_arg`, `va_end`)
- Formatted output handling
- Low-level output using `write()`
- Modular and extensible code design
- Precise memory and error management

This project results in a static library `libftprintf.a` that can later be integrated
into **libft** and reused in future 42 projects.

The behavior of `ft_printf()` is compared against the original `printf()` function
from libc.

---

## Supported Conversions

The mandatory part supports the following format specifiers:

| Specifier | Description |
|---------|------------|
| `%c` | Print a single character |
| `%s` | Print a string |
| `%p` | Print a pointer address in hexadecimal |
| `%d` | Print a signed decimal integer |
| `%i` | Print an integer (base 10) |
| `%u` | Print an unsigned decimal integer |
| `%x` | Print a hexadecimal number (lowercase) |
| `%X` | Print a hexadecimal number (uppercase) |
| `%%` | Print a percent sign |

---

## Instructions

### Compilation

This project builds a **static library**.

To compile the library:

```bash
make
```

This will generate:

```bash
libftprintf.a
```

Available Makefile rules:

```bash
make        # compile the library
make clean  # remove object files
make fclean # remove object files and library
make re     # rebuild everything
```

Usage

Include the header in your project:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c libftprintf.a
```

Example usage:

```c
ft_printf("Hello %s! You have %d messages.\n", "world", 42);
ft_printf("Pointer: %p\n", ptr);
ft_printf("Hex: %x | %X\n", 255, 255);
```

The function returns:

- The number of characters printed

- Or a negative value in case of error

- Implementation Notes

- Output is written directly using write()

- The code is structured to make adding new flags or conversions easier

> [!WARNING]
> Buffer management of the original printf() is not implemented

The project follows 42 Norm strictly

## Resources

AI tools were used in a limited and controlled way, mainly to:
- Clarify theoretical concepts related to variadic functions
- Verify understanding of edge cases and expected behavior
- Improve documentation wording and structure<br>
[printf manual](https://man7.org/linux/man-pages/man3/printf.3.html)<br>
[Variadic functions in C](https://en.cppreference.com/w/c/variadic)<br>
[stdarg.h documentation](https://en.cppreference.com/w/c/variadic)<br>
[Hexadecimal numbers](https://en.wikipedia.org/wiki/Hexadecimal)<br>