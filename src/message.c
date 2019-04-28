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

void get_msg(client_t *client)
{
    char tmp[strlen(client->pass) + 10];

    if (recv(client->sock, NULL, 0, 0) < 0)
        error_msg("Recv error");
    if (recv(client->sock, client->rec, BUFSIZE, 0) < 0)
        error_msg("Recv error");

    strcpy(tmp, client->rec + sizeof(struct iphdr) + sizeof(struct udphdr));
    strcat(tmp, client->pass);
    sha256(client, tmp);

    memset(client->buffer + sizeof(struct iphdr) + sizeof(struct udphdr), 0, BUFSIZE - sizeof(struct iphdr) - sizeof(struct udphdr));
    memcpy(client->buffer + sizeof(struct iphdr) + sizeof(struct udphdr), tmp, sizeof(tmp));
}

void send_mdp(client_t *client)
{
    if (sendto(client->sock, client->buffer, strlen(client->data) +
    sizeof(struct iphdr) + sizeof(struct udphdr), 0, (struct sockaddr *)
    &client->sin, sizeof(client->sin)) < 0)
        error_msg("Sendto error");
}