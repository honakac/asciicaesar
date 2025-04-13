/*
 * asciicaesar - Caesar cipher utility
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

#include "include/asciicaesar.h"
#include <string.h>

void asciicaesar(FILE* output, FILE* input, const char* ignore_chars, int shift)
{
    for (char c; (c = fgetc(input)) != EOF; fputc(c, output)) {
        if ((ignore_chars != NULL && !strchr(ignore_chars, c))
            || ignore_chars == NULL)
            c = c + shift;
    }
}
