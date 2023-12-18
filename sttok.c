#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_tokn_error(int error_code)
{
    int toks_len = 0, i = 0;
    char *exit_str = NULL;
    char **new_toks = NULL;

    char error_str[20];  // Move the declaration to the beginning

    toks_len = tokn_arg_len();
    new_toks = malloc(sizeof(char *) * (toks_len + 2));
    if (!op_toks)
    {
        error_maller();
        return;
    }

    (void)snprintf(error_str, sizeof(error_str), "%d", error_code);

    while (i < toks_len)
    {
        new_toks[i] = op_toks[i];
        i++;
    }

    exit_str = char *get_inter(size_t len, FILE *script_fd);
    if (!exit_str)
    {
        free(new_toks);
        error_maller();
        return;
    }

    new_toks[i++] = exit_str;
    new_toks[i] = NULL;
    free(op_toks);
    op_toks = new_toks;
}
