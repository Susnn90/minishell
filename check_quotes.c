#include "minishell.h"

int check_single_quotes(char *input) 
{
    int i = 0;
    int n_of_squotes = 0;
    int in_squote_string = 0;

    while (input[i]) {
        if (input[i] == S_QUOTE) {
            n_of_squotes++;
            in_squote_string = !in_squote_string;
        }
        i++;
    }
    if (n_of_squotes % 2 != 0) {
        printf("A single Quote is missing\n");
        return 1;
    }
    return 0;
}

int check_double_quotes(char *input) 
{
    int i = 0;
    int n_of_dquotes = 0;
    int in_dquote_string = 0;

    while (input[i]) {
        if (input[i] == D_QUOTE) {
            n_of_dquotes++;
            in_dquote_string = !in_dquote_string;
        }
        i++;
    }
    if (n_of_dquotes % 2 != 0) {
        printf("A double Quote is missing\n");
        return 1;
    }
    return 0;
}

int check_quotes(char *input) 
{
    if (check_single_quotes(input) || check_double_quotes(input)) {
        return 1; 
    }
    return 0; 
}
