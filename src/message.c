/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** message.c
*/

#include "mychap.h"

void send_msg(client_t *client)
{
    if (sendto(client->sock, client->buffer, strlen(client->data) +
    sizeof(struct iphdr) + sizeof(struct udphdr), 0, (struct sockaddr *)
    &client->sin, sizeof(client->sin)) < 0)
        error_msg("Sendto error");
}

void get_msg(client_t *client, char **av)
{
    char tmp[strlen(av[6]) + 10];

    if (recv(client->sock, NULL, 0, 0) < 0)
        error_msg("Recv error");
    if (recv(client->sock, client->rec, BUFSIZE, 0) < 0)
        error_msg("Recv error");

    strcpy(tmp, client->rec + sizeof(struct iphdr) + sizeof(struct udphdr));
    strcat(tmp, av[6]);
}