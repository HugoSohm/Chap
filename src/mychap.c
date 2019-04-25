/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** mychap.c
*/

#include "mychap.h"

int mychap(int ac, char **av)
{
    int target = atoi(av[2]);
    int port = atoi(av[4]);
    char *password = av[6];
    char buffer[PCKT_LEN];
    int one = 1;
    const int *val = &one;
    int sd;

    iph_t *iph = (iph_t *)buffer;
    udph_t *udph = (udph_t *)(buffer + sizeof(iph_t));
    init_iph(ac, av, iph);
    init_udph(ac, av, udph);

    memset(buffer, 0, PCKT_LEN);
    sd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);

    if (sd < 0) {
        perror("socket() error");
        exit(84);
    } else
        printf("socket : OK\n");
    iph->csum = csum((unsigned short *)buffer,
    sizeof(iph_t) + sizeof(udph_t));

    if (setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("setsockopt() error");
        exit(84);
    } else
        printf("setsockopt : OK\n");

    sending(sd, buffer, iph);
    close(sd);
    return (0);
}