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

    int sd;
    char buffer[PCKT_LEN];
    struct ipheader *ip = (struct ipheader *)buffer;
    struct tcpheader *tcp = (struct tcpheader *)(buffer + sizeof(iph2_t));
    struct sockaddr_in sin, din;
    int one = 1;
    const int *val = &one;

    memset(buffer, 0, PCKT_LEN);

    if (ac != 5) {
        printf("- Invalid parameters!!!\n");
        printf("- Usage: %s <source hostname/IP> <source port> <target hostname/IP> <target port>\n", av[0]);
        exit(-1);
    }
    sd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sd < 0) {
        perror("socket() error");
        exit(-1);
    } else
        printf("socket()-SOCK_RAW and tcp protocol is OK.\n");

    sin.sin_family = AF_INET;
    din.sin_family = AF_INET;
    sin.sin_port = htons(atoi(av[2]));
    din.sin_port = htons(atoi(av[4]));
    sin.sin_addr.s_addr = inet_addr(av[1]);
    din.sin_addr.s_addr = inet_addr(av[3]);

    iph2->csum = csum((unsigned short *)buffer, (sizeof(iph2_t) + sizeof(tcph_t)));

    if (setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("setsockopt() error");
        exit(-1);
    } else
        printf("setsockopt() is OK\n");
    printf("Using:::::Source IP: %s port: %u, Target IP: %s port: %u.\n", av[1], atoi(av[2]), av[3], atoi(av[4]));

    unsigned int count;

    for (count = 0; count < 20; count++) {
        if (sendto(sd, buffer, iph2->len, 0, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
            perror("sendto() error");
            exit(-1);
        } else
            printf("Count #%u - sendto() is OK\n", count);
        sleep(2);
    }
    close(sd);
    return (0);
}