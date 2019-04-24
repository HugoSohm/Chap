/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** mychap.c
*/

#include "mychap.h"

int mychap(int ac, char **av)
{
    iph_t *iph = init_iph(ac, av);
    udph_t *udph = init_udph(ac, av);

    char buffer[PCKT_LEN];
    struct ipheader *ip = (struct ipheader *)buffer;
    int one = 1;
    const int *val = &one;
    int sd;

    memset(buffer, 0, PCKT_LEN);
    sd = socket(PF_INET, SOCK_RAW, IPPROTO_UDP);

    if (sd < 0) {
        perror("socket() error");
        exit(84);
    } else
        printf("socket() - Using SOCK_RAW socket and UDP protocol is OK.\n");
    iph->csum = csum((unsigned short *)buffer, sizeof(iph_t) + sizeof(udph_t));

    if (setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("setsockopt() error");
        exit(84);
    } else
        printf("setsockopt() is OK.\n");
    printf("Trying...\n");
    printf("Using raw socket and UDP protocol\n");
    printf("Using Source IP: %s port: %u, Target IP: %s port: %u.\n", av[1], atoi(av[2]), av[3], atoi(av[4]));

    sending(sd, buffer, iph);
    close(sd);
    return (0);
}