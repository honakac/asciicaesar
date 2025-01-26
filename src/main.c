/*
 * BrainGear - Caesar cipher utility
 * Copyright (C) 2025 Andrey Stekolnikov <honakac@yandex.ru>
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "include/asciicaesar.h"
#define VERSION "v1.0"

void usage(char* prog)
{
    fprintf(stderr, "Usage: %s [OPTIONS]...\n", prog);
    fprintf(stderr, "Description:\n");
    fprintf(stderr, "  This program performs an ASCII shift on the given input, with options for customization.\n\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -s SHIFT         Set the ASCII shift value (must be an integer).\n");
    fprintf(stderr, "  -i CHARS         Specify characters to be ignored during the operation.\n");
    fprintf(stderr, "  -d               Invert the shift value (apply the inverse shift).\n");
    fprintf(stderr, "  -h               Show this help message and exit.\n");
    fprintf(stderr, "  -v               Show the program version.\n\n");

    exit(1);
}

int main(int argc, char** argv)
{
    int opt;
    struct {
        char isDecrypt;
        int shift;
        char* ignore_chars;
    } options;
    options.isDecrypt = 0;
    options.shift = 2;
    options.ignore_chars = NULL;
    
    while ((opt = getopt(argc, argv, "s:i:dhv")) != -1) {
        switch (opt) {
            case 's':
                options.shift = atoi(optarg);
                break;
            case 'i':
                options.ignore_chars = optarg;
                break;
            case 'd':
                options.isDecrypt = 1;
                break;
            case 'v':
                fprintf(stderr, "asciicaesar " VERSION "\n");
                fprintf(stderr, "Copyright (C) 2025 Andrey Stekolnikov <honakac@yandex.ru>\n");
                fprintf(stderr, "License: GNU General Public License v3\n");
                return 0;
            case 'h':
            default:
                usage(argv[0]);
        }
    }

    if (options.isDecrypt)
        options.shift = -options.shift;
    
    asciicaesar(stdout, stdin, options.ignore_chars, options.shift);

    return 0;
}