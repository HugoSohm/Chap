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

int main(int ac, char **av)
{
    if (av[1] == "-help")
        help();
    else if (ac != 7) {
        help();
        return (84);
    } else
        mychap(av);
    return (0);
}