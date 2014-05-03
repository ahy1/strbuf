
# strbuf

## Description

**strbuf** is a simple library for creating strings in C.

The strings are stored in a continous buffer, separated by '\0'.

## Usage

Just add strbuf.c to your project file / Makefile and include strbuf.h where needed.

## Functions

### STRBUF *sballoc(size_t size)

Create a new string buffer.

* _sb_ - Initial buffer capacity

Return: A new string buffer handle (to be freed with _sbfree_)

### STRBUF *sbrealloc(STRBUF *sb, size_t size)

Resize a string buffer.

* _sb_ - String buffer handle
* _size_ - New size of string buffer

Return: The handle of the reallocated string buffer, og _NULL_ for error

### int sbfree(STRBUF *sb)

Release all allocations related to a string buffer.

* _sb_ - String buffer handle or _NULL_

Return: 0 => OK, -1 => Error 

### STRBUF *sbexpand(STRBUF *sb, size_t needed_capacity)

Make sure the capacity of a string buffer is at least _needed_capacity_.

* _sb_ - String buffer handle
* _needed_capacity_ - Minimum capacity

Return: The handle of the possibly reallocated string buffer

### int sbcat(STRBUF *sb, const char *str)

Append a string to the current string (could be considered a checked _strcat_).

* _sb_ - String buffer handle
* _str_ - String to be appended

Return: 0 => OK, -1 => Error

### int sbput(STRBUF *sb, int ch)

Append a character to the current string.

* _sb_ - String buffer handle
* _ch_ - Character to be appended

Return: _ch_ => OK, -1 => Error

### int sbstop(STRBUF *sb)

Terminate a string, starting a new one. Following calls to _sbcat()_ or _sbput()_ will append to a new string.

* _sb_ - String buffer handle

Return: 0 => OK, -1 => Error

### size_t sbix(STRBUF *sb)

Return the current index in the string buffer.

* _sb_ - String buffer handle

Return: Index

### int sbforeach(STRBUF *sb, size_t ix, int (*fn)(const char *))

Do something on each string in the string buffer.

* _sb_ - String buffer handle
* _ix_ - Index to where in the string buffer to start
* _fn_ - Function to be called on each string

Return: 0 => OK

### size_t sbsearch(STRBUF *sb, size_t ix, int (*fn)(const char *, const char *), const char *what)

Search for a string in the string buffer.

* _sb_ - String buffer handle
* _ix_ - Index to where in the string buffer to start searching

Return: Index of found string, or (size_t)-1 for error

### const char *sbcstr(STRBUF *sb, size_t ix)

Return a C string.

* _sb_ - String buffer handle
* _ix_ - Index to where in the string buffer

Return: The '\0'-terminated C string

### int sbwritejson(STRBUF *sb, size_t ix, int (*fn)(const char *))

Write a JSON array containing all strings in the string buffer.

* _sb_ - String buffer handle
* _ix_ - Index of where in the string buffer to start printing
* _fn_ - Function that will actually do the printing

Return: 0 => OK

### int sbwritecsv(STRBUF *sb, size_t ix, int sep, int quote, int (*fn)(const char *))

Write a CSV array containing all strings in the string buffer.

* _sb_ - String buffer handle
* _ix_ - Index of where in the string buffer to start printing
* _sep_ - Which separator to use
* _quote_ - Which quote character to use
* _fn_ - Function that will actually do the printing

Return: 0 => OK





