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
    &client->sin, sizeof(client->sin)) < 0) {
        printf("No such hostname: '%s'\n", client->addr);
        exit(84);
    }
}

void send_mdp(client_t *client)
{
    if (sendto(client->sock, client->buffer, strlen(client->sha) +
    sizeof(struct iphdr) + sizeof(struct udphdr), 0, (struct sockaddr *)
    &client->sin, sizeof(client->sin)) < 0)
        error_msg("Sendto error");
}

void get_msg(client_t *client)
{
    char tmp[strlen(client->pass) + 10];

    if (recv(client->sock, NULL, 0, 0) < 0)
        error_msg("First recv error");
    if (recv(client->sock, client->rec, BUFSIZE, 0) < 0)
        error_msg("Second recv error");

    strcpy(tmp, client->rec + sizeof(struct iphdr) + sizeof(struct udphdr));
    strcat(tmp, client->pass);

    client->sha = sha256(client, tmp);

    memset(client->buffer + sizeof(struct iphdr) + sizeof(struct udphdr), 0,
    BUFSIZE - sizeof(struct iphdr) - sizeof(struct udphdr));
    memcpy(client->buffer + sizeof(struct iphdr) + sizeof(struct udphdr),
    client->sha, strlen(client->sha));
}

void get_mdp(client_t *client)
{
    char mdp[BUFSIZE];

    if (recv(client->sock, NULL, 0, 0) < 0)
        error_msg("first recv error");
    if (recv(client->sock, mdp, BUFSIZE, 0) < 0)
        error_msg("Second recv error");
    if (strcmp(mdp + sizeof(struct iphdr) +
        sizeof(struct udphdr), "KO") == 0)
        printf("KO\n");
    else
        printf("Secret: '%s'\n", mdp + sizeof(struct iphdr) +
        sizeof(struct udphdr));
}