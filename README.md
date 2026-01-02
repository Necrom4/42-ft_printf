_This project has been created as part of the 42 curriculum by dferreir_

# Description

> This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.<br>- <ins>42 Intra description</ins>

# Instructions

## Generate `libftprintf.a`

```sh
make # normal
make bonus # bonus
```

## Compilation

```sh
gcc <test.c> libftprintf.a
```

## Execution

```sh
./a.out
```

# Resources

- `man printf`
- **AI** was not used as this project was completed in 2022, back before this subject mentioned AI.

# Chosen Algorithm

The program receives a string and data to replace in the string, the string is then parsed to the first specifier and sent to be formatted, where it first searches for flags and applies their effect, and then replaces the specified by the data given by using a specific function for each specifier kind. The length of the output is also calculated.
