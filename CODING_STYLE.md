
# Coding style guidelines for Cemu

This document describes the latest version of our coding-style guidelines. Since we did not use this style from the beginning, older code may not adhere to these guidelines. Never the less, use these rules even if the surrounding code does not match.

## Names for variables, functions and classes

- Always prefix member variables with `m_`
- Always prefix static class variables with `s_`. Also use this prefix for global variables.
- For variable names: Camel case, starting with a lower case letter after the prefix. Examples: `m_option`, `s_audioVolume`
- For functions/class names: Use camel case starting with a capital letter. Examples: `MyClass`, `SetActive`
- Avoid underscores in variable names. `m_myVariable` instead of `m_my_variable`

## About types

Cemu provides it's own set of basic fixed-width types. They are:
`uint8`, `sint8`, `uint16`, `sint16`, `uint32`, `sint32`, `uint64`, `sint64`

Always use these types over something like `uint32_t`. Using `size_t` is also acceptable when suitable. Avoid C types like `int` or `long`. The only exception is when interacting with external libraries which expect these types as parameters.

## When and where to put brackets

Always put curly-brackets (`{ }`) on their own line. Example:

```
void FooBar()
{
   if (m_hasFoo)
   {
       ...
   }
}
```

You can skip brackets for single-statement ifs. Example:

```
if (cond)
    action();
```

As an exception, you can put short lambdas into the same line:
```
SomeFunc([]() { .... });
```

## Printing

Avoid sprintf and similar API. Use `fmt::format()` instead. 
In UI related code you can use `wxString::Format`, but be aware that number formatting will be locale dependent!

## HLE and endianness

A pretty large part of Cemu's code base are re-implementations of various Cafe OS modules. These generally run in the context of the emulated process, thus special care has to be taken to use types with the correct endianness and size when interacting with memory.

Keep in mind that the Espresso CPU is big-endian, the Latte GPU is generally little-endian but supports mixed-endianness for some operations, while x86 is litte-endian! 

To keep code simple and remove the need for manual endian-swapping, Cemu has templates and aliases of the basic types with explicit endian-ness.
For big-endian types add the suffix `be` and for little-endian add the suffix `le`. Example: `uint32be`

## Asserts and logging

TODO

## HLE interfaces

The implementation for each HLE module is inside a namespace with a matching name. E.g. `coreinit.rpl` functions go into `coreinit` namespace.

TODO
