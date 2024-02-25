/*
 * asciicaesar - Caesar cipher utility
 * Copyright (C) 2024 Andrew Stekolnikov <honakac@yandex.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <getopt.h>
#define ASCIICAESAR_VERSION "1.0"

static void usage(char *prog) {
    std::cerr << "Usage: " << prog << " [OPTIONS]" << std::endl;
    std::cerr << "  -i FILE                    input file(default read from stdin)" << std::endl;
    std::cerr << "  -o FILE                    output file(default write to stdout)" << std::endl;
    std::cerr << "  -s COUNT                   character offset(default: 2)\n" << std::endl;
    std::cerr << "  -v                         show version" << std::endl;
    std::cerr << "  -h                         show this message" << std::endl;
    std::exit(1);
}

int main(int argc, char **argv) {
    struct {
        FILE *input     = stdin;
        FILE *output    = stdout;
        int shift       = 2;
    } flags;

    int opt;
    while ((opt = getopt(argc, argv, "i:o:s:vh")) != -1) {
        switch (opt) {
            case 'i':   flags.input = fopen(optarg, "r");  break;
            case 'o':   flags.output = fopen(optarg, "w");  break;
            case 's':   flags.shift = std::atoi(optarg);              break;
            case 'v':
                std::cerr << "asciicaesar " ASCIICAESAR_VERSION << std::endl;
                std::exit (-1);
            case '?':
            case 'h':
                usage(argv[0]);
        }
    }

    fseek(flags.input, 0L, SEEK_END);
    size_t size = ftell(flags.input);
    fseek(flags.input, 0L, SEEK_SET);
    rewind(flags.input);

    for (size_t pos = 0; pos < size; ++pos) {
        int ch = fgetc(flags.input);
        if (ch != '\n')
            ch += flags.shift;

        fputc(ch, flags.output);
    }

    return 0;
}