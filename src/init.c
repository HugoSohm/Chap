/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** init.c
*/

#include "mychap.h"

void init_iph(int ac, char **av, iph_t *iph)
{
    iph->ihl = 5;
    iph->flags = 3;
    iph->version = 4;
    iph->tos = 16;
    iph->len = sizeof(iph_t) + sizeof(udph_t) + 1000;
    iph->id = htons(54321);
    iph->ttl = 64;
    iph->protocol = 17;
    iph->offset = 13;
    iph->src = inet_addr(av[1]);
    iph->dest = inet_addr(av[3]);
    iph->sin.sin_family = AF_INET;
    iph->din.sin_family = AF_INET;
    iph->sin.sin_port = htons(atoi(av[4]));
    iph->sin.sin_addr.s_addr = inet_addr(av[2]);
}

void init_udph(int ac, char **av, udph_t *udph)
{
    udph->udph_srcport = htons(atoi(av[2]));
    udph->udph_destport = htons(atoi(av[4]));
    udph->udph_len = htons(sizeof(udph_t));
}