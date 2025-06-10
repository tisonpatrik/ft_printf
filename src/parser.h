#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
    int     flag_minus;     // '-'
    int     flag_zero;      // '0'
    int     flag_dot;       // '.'
    int     flag_hash;      // '#'
    int     flag_space;     // ' '
    int     flag_plus;      // '+'
    int     width;
    int     precision;
    char    type;           // conversion char
}   t_format;

t_format parse_format(const char *format, int *i, va_list args);

#endif

