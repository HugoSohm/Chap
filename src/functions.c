/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** functions.c
*/

#include "mychap.h"

unsigned short csum(unsigned short *buf, int nwords)
{
    unsigned long sum;

    for (sum = 0; nwords > 0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (unsigned short)(~sum);
}

void error_msg(char *msg)
{
    perror(msg);
    exit(84);
}