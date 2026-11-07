*This project has been created as part of the 42 curriculum by skaprash.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`. The goal of the project is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_end`), how to parse a format string, and how to build a small, well-structured library that can be reused in later projects.

The result is a static library, `libftprintf.a`, exposing a single function:

```c
int ft_printf(const char *format, ...);
```

It writes the formatted output to standard output and returns the number of characters printed (or `-1` on error), just like the original `printf`.

### Supported conversions

| Conversion | Output |
|------------|--------|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is `NULL`) |
| `%p` | A pointer address in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` | A signed decimal integer |
| `%i` | A signed integer in base 10 |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned hexadecimal number, lowercase |
| `%X` | An unsigned hexadecimal number, uppercase |
| `%%` | A literal percent sign |

## Instructions

### Requirements

- A C compiler (`cc`) and `make`
- Compiled with `-Wall -Wextra -Werror`

### Repository layout

```
.
├── Makefile
├── libft/        # my libft, built and merged into libftprintf.a
├── inc/          # header file(s)
└── src/          # ft_printf source files
```

### Compilation

```sh
make        # builds libftprintf.a (and libft)
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + make
```

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hello %s, you are %d years old (%x in hex)\n", "Aries", 25, 25);
    ft_printf("Printed %d characters\n", n);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -Iinc -L. -lftprintf -o test
./test
```

## Algorithm and data structure

### Parsing the format string

`ft_printf` walks the format string once, from left to right:

1. Ordinary characters are written directly with `write()` and counted.
2. When a `%` is found, the next character is read as the conversion specifier.
3. The specifier is passed, together with the `va_list`, to a dispatch function that pulls the correct argument type with `va_arg` and calls the matching print helper.
4. Each helper returns how many characters it wrote; these are added to a running total, which is the final return value.

This single-pass approach is O(n) in the length of the format string plus the length of the output, needs no extra memory, and mirrors how the real `printf` reads its format.

### Data structure

No complex data structure is needed: the state is just the format string pointer, the `va_list`, and an `int` counter. Keeping it this small was a deliberate choice:

- **No buffer / no `malloc`** — characters are written as soon as they are known, so there is nothing to allocate or free and no risk of leaks.
- **One helper per conversion** — each conversion (`char`, string, pointer, signed number, unsigned number in a given base) has its own small function, which keeps every function within the Norm limits and makes it easy to add new specifiers.
- **Shared base conversion** — `%u`, `%x`, `%X` and `%p` all go through the same recursive "print number in base" routine, with only the base and digit set changing. Recursion prints digits in the correct order without needing a temporary array.
- **`%p` uses `unsigned long`** — addresses are cast to an unsigned type wide enough for a pointer on 64-bit systems before conversion.
- **`%d` / `%i` handle `INT_MIN`** — the value is promoted to `long` before negating, so the minimum integer prints correctly.

## Resources

- `man 3 printf` — reference behavior for every conversion
- `man 3 stdarg` — variadic function macros (`va_start`, `va_arg`, `va_copy`, `va_end`)
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
- [GNU C Library manual — Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

### Use of AI

AI (Claude) was used to help draft and structure this README. All code in `src/` and `inc/` was written by me.
