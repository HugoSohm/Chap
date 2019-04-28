/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** main.c
*/

#include "mychap.h"

void help(void)
{
    printf("The program takes 3 parameters:\n");
    printf("\t-t (or --target) followed by the target of the remote ");
    printf("authenticating entity.\n");
    printf("\t-p (or --port) followed by the port.\n");
    printf("\t-P (or --password) followed by the password that allows you to ");
    printf("authenticate to the entity.\n");
}

void check_addr(char **av)
{
    if (strcmp(av[2], "localhost") == 0)
        av[2] = "127.0.0.1";
}

int main(int ac, char **av)
{
    if (ac != 7) {
        help();
        return (84);
    } else {
        check_addr(av);
        mychap(av);
    }

    return (0);
}