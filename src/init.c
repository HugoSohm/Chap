/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** init.c
*/

#include "mychap.h"

iph_t *init_iph(int ac, char **av)
{
    iph_t *iph = malloc(sizeof(iph_t));

    iph->ihl = 5;
    iph->flags = 3;
    iph->version = 4;
    iph->tos = 16;
    iph->len = sizeof(iph_t) + sizeof(udph_t);
    iph->id = htons(54321);
    iph->ttl = 64;
    iph->protocol = 17;
    iph->offset = 13;
    iph->src = inet_addr(av[1]);
    iph->dest = inet_addr(av[3]);

    iph->sin.sin_family = AF_INET;
    iph->din.sin_family = AF_INET;
    iph->sin.sin_port = htons(atoi(av[2]));
    iph->din.sin_port = htons(atoi(av[4]));
    iph->sin.sin_addr.s_addr = inet_addr(av[1]);
    iph->din.sin_addr.s_addr = inet_addr(av[3]);

    return (iph);
}

iph2_t *init_iph2(int ac, char **av)
{
    iph2_t *iph2 = malloc(sizeof(iph2_t));

    iph2->ihl = 5;
    iph2->version = 4;
    iph2->tos = 16;
    iph2->len = sizeof(iph2_t) + sizeof(tcph_t);
    iph2->id = htons(54321);
    iph2->offset = 0;
    iph2->ttl = 64;
    iph2->protocol = 6;
    iph2->csum = 0;
    iph2->src = inet_addr(av[1]);
    iph2->dest = inet_addr(av[3]);

    iph2->sin.sin_family = AF_INET;
    iph2->din.sin_family = AF_INET;
    iph2->sin.sin_port = htons(atoi(av[2]));
    iph2->din.sin_port = htons(atoi(av[4]));
    iph2->sin.sin_addr.s_addr = inet_addr(av[1]);
    iph2->din.sin_addr.s_addr = inet_addr(av[3]);

    return (iph2);
}

udph_t *init_udph(int ac, char **av)
{
    udph_t *udph = malloc(sizeof(udph_t));

    udph->udph_srcport = htons(atoi(av[2]));
    udph->udph_destport = htons(atoi(av[4]));
    udph->udph_len = htons(sizeof(udph_t));

    return (udph);
}

tcph_t *init_tcph(int ac, char **av)
{
    tcph_t *tcph = malloc(sizeof(tcph_t));

    tcph->srcport = htons(atoi(av[2]));
    tcph->destport = htons(atoi(av[4]));
    tcph->seqnum = htonl(1);
    tcph->acknum = 0;
    tcph->offset = 5;
    tcph->syn = 1;
    tcph->ack = 0;
    tcph->win = htons(32767);
    tcph->chksum = 0;
    tcph->urgptr = 0;

    return (tcph);
}