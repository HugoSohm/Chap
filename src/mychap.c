/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** mychap.c
*/

#include "mychap.h"

void send_get(client_t *client)
{
    send_msg(client);
    get_msg(client);
    new_size(client);
    send_mdp(client);
    get_mdp(client);
}

int mychap(char **av)
{
    client_t *client = init_client(av);
    struct iphdr *iph = init_iphdr(client);
    struct udphdr *udph = init_udphdr(client);

    if (client->sock < 0)
        error_msg("Socket error");

    if (setsockopt(client->sock, IPPROTO_IP, IP_HDRINCL, &client->on,
    sizeof(client->on)) < 0)
        error_msg("Setsockopt error");

    memcpy(client->buffer, iph, sizeof(struct iphdr));
    memcpy(client->buffer + sizeof(struct iphdr), udph, sizeof(struct udphdr));
    memcpy(client->buffer + sizeof(struct iphdr) + sizeof(struct udphdr),
    client->data, client->len);

    send_get(client);
    close(client->sock);
    return (0);
}