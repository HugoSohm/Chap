/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** init.c
*/

#include "mychap.h"

client_t *init_client(char **av)
{
    client_t *client = malloc(sizeof(*client));

    client->data = strdup("client hello");
    client->data = "client hello";
    client->sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    client->on = 1;
    client->port = atoi(av[4]);
    client->addr = av[2];
    client->pass = av[6];
    client->len = strlen(client->data);
    client->sin.sin_family = AF_INET;
    client->sin.sin_port = htons(client->port);
    client->sin.sin_addr.s_addr = inet_addr(av[2]);

    return (client);
}

struct iphdr *init_iphdr(client_t *client)
{
    struct iphdr *iph = malloc(sizeof(*iph));
    memset(iph, 0, sizeof(*iph));

    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = htons(sizeof(struct iphdr) +
    sizeof(struct udphdr) + client->len);
    iph->id = htons(54321);
    iph->ttl = 64;
    iph->protocol = 17;
    iph->saddr = inet_addr("127.0.0.1");
    iph->daddr = inet_addr(client->addr);
    iph->check = 0;

    return (iph);
}

struct udphdr *init_udphdr(client_t *client)
{
    struct udphdr *udph = malloc(sizeof(*udph));

    udph->uh_sport = htons(54321);
    udph->uh_dport = htons(client->port);
    udph->len = htons((uint16_t)(sizeof(struct udphdr) + client->len));
    udph->check = 0;

    return (udph);
}