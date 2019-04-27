/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** sending.c
*/

#include "mychap.h"

void send_msg(client_t *client)
{
    if (sendto(client->sock, client->buffer, strlen(client->data) +
    sizeof(struct iphdr) + sizeof(struct udphdr), 0, (struct sockaddr *)
    &client->sin, sizeof(client->sin)) < 0)
        error_msg("Sendto error");
}

void get_msg(client_t *client)
{
    if (recvfrom(client->sock, client->rec, BUFSIZE, MSG_WAITALL,
    (struct sockaddr *)&client->sin, &client->len) < 0)
        error_msg("Recv error");
}