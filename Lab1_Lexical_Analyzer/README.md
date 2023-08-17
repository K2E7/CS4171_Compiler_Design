# Custom C-Based Lexical Analyzer

This repository contains a custom lexical analyzer implemented in C. The purpose of this tool is to identify and categorize various tokens present in the input code without using Lex/Flex.

## Description

The provided code implements a C-based lexical analyzer that can identify and classify different tokens within a source code. The recognized tokens include operators, reserved words, identifiers, string literals, and constants.

## Usage

Follow these steps to compile and run the custom C-based lexical analyzer:

1. **Compilation:**

   Compile the C file using a C compiler like `gcc`. Open your terminal and navigate to the directory containing the `lexical_analyzer.c` file, then execute the following command:

   ```bash
   gcc lexical_analyzer.c -o lexer
   ```

   This will create an executable named `lexer`.

2. **Execution:**

   Run the lexical analyzer on an input file by executing the following command:

   ```bash
   ./lexer input_file_name
   ```

   Replace `input_file_name` with the name of the file you want to analyze.

3. **Output:**

   The lexical analyzer will process the input file and display the recognized tokens in the console output. Tokens are classified as operators, reserved words, identifiers, string literals, and constants.

## Token Categories

- **Operators:** Single-character operators like `(`, `>`, `)`, `=`, `-`, `;`.

- **Reserved Words:** Keywords like `while`, `for`, `if`, `else`, `int`, `float`, `char`.

- **Identifiers:** Variables or user-defined names following the rules for C identifiers.

- **String Literals:** Text enclosed in double quotes, e.g., `"Hello, World!"`.

- **Constants:** Integer and floating-point constants.

## Customization

You can customize the code in `lexical_analyzer.c` to add more token patterns or modify existing ones to suit your needs.
