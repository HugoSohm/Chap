/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** sending.c
*/

#include "mychap.h"

void sending(int sd, char *buffer, iph_t *iph)
{
    if (sendto(sd, buffer, iph->len, 0, (struct sockaddr *)&iph->sin,
    sizeof(iph->sin)) < 0) {
        perror("sendto() error");
        exit(84);
    } else
        printf("hello world\n");
}