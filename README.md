# asciicaesar

A Caesar cipher utility that encrypts all ASCII characters.

## Features:
* Encrypts and decrypts text using the Caesar cipher
* Works with all ASCII characters
* Option to ignore specific characters during encryption/decryption
* Simple command-line interface

## Requirements:
* GCC (GNU Compiler Collection)
* Make

## Installation:
1. Clone the repository
2. Navigate to the project directory
3. Compile the project using 'make'

## Usage:

Run './asciicaesar [options]'<br>
For detailed information on available options, use './asciicaesar -h'

## Example:

Encrypt text while ignoring spaces and punctuation:

```bash
./asciicaesar -s 3 -i ' ,.!?'
```
or using pipes
```bash
cat input_file | ./asciicaesar -s 3 -i ' ,.!?' > output_file
```

## Contributing:

Contributions are welcome. Please fork the repository, create a feature branch, commit your changes, and open a Pull Request.

## License:
This project is licensed under GPL v3.0. See the LICENSE file for details.

## Contact:
Andrey Stekolnikov - honakac@yandex.ru <br>
Project Link: https://github.com/honakac/asciicaesar