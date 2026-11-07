*This project has been created as part of the 42 curriculum by skaprash.*

---

## Description

So, `libft` is basically the very first proper C project at 42. The goal is to recreate a bunch of standard C library functions from scratch (like `strlen`, `strdup`, `memset`, etc.), plus a few extra helper functions that didn't make it into the standard library or are just super useful to have around for future projects (like string splitting, fd put functions, and linked list handlers).

It acts as our foundational personal library (`libft.a`) that we can carry over and reuse throughout the rest of the common core. Honestly, writing `memcpy` or `strlcat` by hand makes you realize how much C actually abstracts away!

---

## Instructions

Compiling this library is straightforward. Just clone the repo and run `make` inside the root directory.

```bash
# Compile the mandatory part
make

# Compile with the bonus part (linked lists)
make bonus

# Clean up object files
make clean

# Clean up object files and the compiled library (libft.a)
make fclean

# Re-compile everything from scratch
make re

```

### How to use it in your own projects:

Just include the header in your C files:

```c
#include "libft.h"

```

And link the static library when compiling your code:

```bash
gcc main.c libft.a

```

---

## Function List

Here is what's packed inside this library:

### 1. Libc Functions (Part 1)

* **Character checks & conversion:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
* **Memory manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
* **String operations:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
* **Conversion & others:** `ft_atoi`

### 2. Additional Functions (Part 2)

* `ft_substr` - Extracts a substring from a string.
* `ft_strjoin` - Concatenates two strings into a new one.
* `ft_strtrim` - Trims the beginning and end of a string with specified reference characters.
* `ft_split` - Splits a string using a character as a delimiter, returning an array of strings.
* `ft_itoa` - Converts an integer into a string.
* `ft_strmapi` - Applies a function to each character of a string to create a new string.
* `ft_striteri` - Applies a function to each character of a string in-place.
* **File descriptor outputs:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 3. Linked List Functions (Part 3)

* `ft_lstnew` - Creates a new list node.
* `ft_lstadd_front` - Adds a node at the beginning of a list.
* `ft_lstsize` - Counts the number of nodes in a list.
* `ft_lstlast` - Returns the last node of a list.
* `ft_lstadd_back` - Adds a node at the end of a list.
* `ft_lstdelone` - Deletes a node's content and frees the node.
* `ft_lstclear` - Deletes and frees all nodes in a list.
* `ft_lstiter` - Iterates through a list and applies a function to each node's content.
* `ft_lstmap` - Iterates through a list, applies a function to create a new list, and handles cleanups if allocations fail.

---

## Resources

* **Documentation & Manuals:**
* Linux `man` pages (e.g., `man 3 memset`, `man 3 strlcpy`)


* [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)


* [C Reference - cppreference.com](https://en.cppreference.com/)




* **AI Usage:**
* AI tools (like ChatGPT / Claude) were used selectively during this project.


* Specifically, AI helped with debugging tricky edge cases (like handling null terminators and pointers inside `ft_lstmap`), formatting Makefile templates, and clarifying confusing logic regarding double pointer handling in linked lists. All core logic, structure, and final code implementations were thoroughly reviewed, tested, and written by hand.
