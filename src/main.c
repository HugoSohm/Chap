/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** main.c
*/

#include "mychap.h"

void help()
{
    printf("The program takes 3 parameters:");
    printf("\t-t (or --target) followed by the target of the remote authenticating entity.");
    printf("\t-p (or --port) followed by the port.");
    printf("\t-P (or --password) followed by the password that allows you to authenticate to the entity.");
}

int main(int ac, char **av)
{
    if (av[1] == "-help")
        help();
    else if (ac != 5) {
        help();
        return (84);
    } else
        mychap(ac, av);
    return (0);
}