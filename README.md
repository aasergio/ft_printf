*This project has been created as part of the 42 curriculum by skaprash.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`. The goal of the project is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_end`), how to parse a format string, and how to package the result as a reusable static library.

The project builds `libftprintf.a`, which contains my `libft` plus a single public function:

```c
int ft_printf(const char *s, ...);
```

It writes the formatted output to standard output and returns the number of characters printed.

### Supported conversions

| Conversion | Output |
|------------|--------|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is `NULL`) |
| `%p` | A pointer address in lowercase hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` | A signed decimal integer |
| `%i` | A signed integer in base 10 |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned hexadecimal number, lowercase |
| `%X` | An unsigned hexadecimal number, uppercase |
| `%%` | A literal percent sign |

## Instructions

### Requirements

- `cc` and `make`
- Everything compiles with `-Wall -Wextra -Werror`

### Repository layout

```
.
├── Makefile
├── ft_printf.h         # prototypes and base-digit macros
├── ft_printf.c         # ft_printf() and the conversion dispatcher
├── ft_printf_utils.c   # character, string and number printers
└── libft/              # my libft (built and merged into libftprintf.a)
```

### Compilation

```sh
make        # builds libft, then libftprintf.a
make clean  # removes the obj/ directory (and libft objects)
make fclean # also removes libftprintf.a and libft.a
make re     # fclean + all
```

The Makefile first builds `libft/libft.a`, copies it to `libftprintf.a`, and then adds the `ft_printf` object files to it with `ar -rcs`. The result is one archive that contains both libraries. Object files go into `obj/`, and `-MMD -MP` generates dependency files so that changing a header triggers a rebuild.

### Usage

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hello %s, %d in hex is %x, ptr: %p\n", "world", 42, 42, &n);
    ft_printf("Printed %d characters\n", n);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -I. -Ilibft -L. -lftprintf -o test
./test
```

`-Ilibft` is needed because `ft_printf.h` includes `<libft.h>`.

## Algorithm and data structure

### Parsing: a single left-to-right pass

`ft_printf` walks the format string once with an index `i`:

1. An ordinary character is written immediately with `write()`, and the counter goes up by one.
2. When the function finds `%`, it passes the next character to `ft_letter()`, a dispatcher. The dispatcher pulls the matching argument type with `va_arg` and calls the right printer.
3. A `%` at the very end of the string (with nothing after it) stops the loop.
4. An unrecognised specifier prints nothing.

This runs in O(n) time in the length of the format string plus the output, and it uses constant extra memory.

### State: one `int` passed by pointer

The only state is the `va_list` and an `int res`, the number of characters written so far. Every printer receives `int *res` and adds the number of bytes it writes, so the total is always correct, whichever helpers run and however deep the recursion goes. `ft_printf` returns `res` at the end.

I chose this design over having each helper return its own count because it keeps the dispatcher very small. Every branch is just a function call, with no return values to collect and add together.

### Printers

- **`ft_putchar_pr` / `ft_putstr_pr`** write a character or a whole string in one `write()` call. A `NULL` string prints `(null)`.
- **`ft_putnbr_any(unsigned long n, char *system, int *res)`** is a generic base printer. The base is the length of the digit string (`DEC`, `HEXLOW` or `HEXUP`, defined as macros in the header), and the digit for each value is just `system[n]`. It recurses on `n / base` before printing `n % base`, so the digits come out in the right order without a temporary buffer. The same function handles `%u`, `%x`, `%X` and `%p`.
- **`ft_putnbr_d`** handles signed integers. It prints a `-` and negates negative numbers, then prints the digits recursively. `INT_MIN` (`-2147483648`) cannot be negated in an `int`, so the function special-cases it and writes it as a fixed string.
- **`%p`** casts the pointer to `uintptr_t`, an integer type guaranteed to hold a pointer. The function writes `0x` and then prints the value with `ft_putnbr_any` in lowercase hex. A `NULL` pointer prints `(nil)`, which matches glibc's `printf`.

### Why no buffer and no `malloc`

The function writes output as soon as it knows each character. This means:
- there is nothing to allocate, so there are no leaks and no allocation failures to handle;
- every function stays short enough for the Norm;
- adding a new conversion only takes one new branch in `ft_letter()`, and usually no new printer, because most numeric formats can reuse `ft_putnbr_any` with a different base string.

The trade-off is many small `write()` calls instead of one large one. That is slower than a buffered `printf`, but it is much simpler and fast enough for this project.

## Resources

- `man 3 printf` — reference behavior for every conversion
- `man 3 stdarg` — `va_start`, `va_arg`, `va_end`
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
- [GNU C Library manual — Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

### Use of AI

AI (Claude) was used to help write and structure this README from my source files. <!-- Add any other way you used AI here, e.g. explaining va_list or testing edge cases. --> The code itself was written by me.
