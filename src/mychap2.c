/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** mychap2.c
*/

#include "mychap.h"

int mychap2(int ac, char **av)
{
    iph2_t *iph2 = init_iph2(ac, av);
    tcph_t *tcph = init_tcph(ac, av);

    char buffer[PCKT_LEN];
    struct ipheader *ip = (struct ipheader *)buffer;
    int one = 1;
    const int *val = &one;
    int sd;

    memset(buffer, 0, PCKT_LEN);
    sd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sd < 0) {
        perror("socket() error");
        exit(84);
    } else
        printf("socket()-SOCK_RAW and tcp protocol is OK.\n");

    iph2->csum = csum((unsigned short *)buffer,
    (sizeof(iph2_t) + sizeof(tcph_t)));

    if (setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("setsockopt() error");
        exit(84);
    } else
        printf("setsockopt() is OK\n");
    printf("Using:::::Source IP: %s port: %u, Target IP: %s port: %u.\n",
    av[1], atoi(av[2]), av[3], atoi(av[4]));

    sending2(sd, buffer, iph2);
    close(sd);
    return (0);
}