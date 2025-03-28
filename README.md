## Custom `printf` Implementation

This project is a custom implementation of the standard `printf` function in C, designed to demonstrate expertise in **variadic functions**, **function pointers**, and **modular I/O handling**. Key to its flexibility is the use of **function pointers** to associate format specifiers with corresponding handler functions.

This implementation allows easy addition of new format specifiers by simply adding a structure. This design showcases a strong understanding of **low-level function dispatching**, a crucial concept for system-level programming.

## Key Features
- **Extensible Format Specifiers**: The format specifiers are dynamically linked to respective functions using function pointers.  
- **Custom Handler Functions**: Supports a variety of data types, including characters, strings, integers, and binary formats.
- **Error Handling**: Gracefully handles edge cases, like null pointers and extra spaces in format strings.

## Design Highlight
The heart of this implementation lies in the `Specifier` structure, where each format specifier is paired with a corresponding function pointer. This design not only makes the system extensible but also demonstrates a **dynamic dispatch mechanism**, which is an essential aspect of more complex C programming tasks.

### Example Usage:

```c
_printf("Hello %s, your balance is %d\n", "John", 2500);
_printf("Binary: %b\n", 5); // Output: 101
_printf("Reversed: %r\n", "abc"); // Output: cba
```
