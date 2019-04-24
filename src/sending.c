/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** sending.c
*/

#include "mychap.h"

void sending(int sd, char *buffer, iph_t *iph)
{
    for (int count = 1; count <= 20; count++) {
        if (sendto(sd, buffer, iph->len, 0, (struct sockaddr *)&iph->sin, sizeof(iph->sin)) < 0) {
            perror("sendto() error");
            exit(84);
        } else {
            printf("Count #%u - sendto() is OK.\n", count);
            sleep(2);
        }
    }
}

void sending2(int sd, char *buffer, iph2_t *iph2)
{
    for (int count = 1; count <= 20; count++) {
        if (sendto(sd, buffer, iph2->len, 0, (struct sockaddr *)&iph2->sin, sizeof(iph2->sin)) < 0) {
            perror("sendto() error");
            exit(-1);
        } else
            printf("Count #%u - sendto() is OK\n", count);
        sleep(2);
    }
}