# Lex/Flex Lexical Analyzer

This repository contains a simple Lex/Flex lexical analyzer for a C-like language. The purpose of this tool is to recognize and classify various tokens present in the input code.

## Getting Started

Follow these steps to compile, test, and use the Lex/Flex lexical analyzer:

### Prerequisites

Ensure you have `flex` and `gcc` installed on your system.

### Compilation

1. Open your terminal and navigate to the directory containing the `lex_file_name.l` (replace with the actual file name) Lex/Flex file.

2. Generate the C code from the Lex/Flex file using the following command:

   ```bash
   flex lex_file_name.l
   ```

   This will create a C file named `lex.yy.c`.

3. Compile the generated C code into an executable using the following command:

   ```bash
   gcc -o lexer lex.yy.c -lfl
   ```

   This will create an executable named `lexer`.

### Usage

1. Run the lexical analyzer on an input file by executing the following command:

   ```bash
   ./lexer input_file_name
   ```

   Replace `input_file_name` with the name of the file you want to analyze.

2. The lexical analyzer will process the input file and display the recognized tokens in the console output. Tokens include reserved words, operators, identifiers, integer constants, etc.

### Example Output

For example, if you have an input file containing code, running the lexer might produce output like:

```
Reserved Word:     int
Identifier:        main
Parenthesis:       (
Parenthesis:       )
Curly Brace:       {
...
```

## Customization

You can customize the Lex/Flex file (`lex_file_name.l`) to add new token patterns, modify existing ones, or adapt the behavior of the lexical analyzer to match your specific needs.

## Cleaning Up

To remove the generated files after usage, simply delete the `lex.yy.c` file and the `lexer` executable.
