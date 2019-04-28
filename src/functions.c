/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** functions.c
*/

#include "mychap.h"

void new_size(client_t *client)
{
    struct iphdr *iph = (struct iphdr *)client->buffer;
    struct udphdr *udph = (struct udphdr *)
    (client->buffer + sizeof(struct iphdr));

    iph->tot_len = sizeof(struct iphdr) + sizeof(struct udphdr) +
    strlen(client->sha);
    udph->len = htons(sizeof(struct udphdr) + strlen(client->sha));
}

char *sha256(client_t *client, const char *str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH] = {0};
    SHA256_CTX sha256;
    char *output_buffer;

    if (!(output_buffer = calloc(1, sizeof(char) *
    ((SHA256_DIGEST_LENGTH * 2) + 1))))
        return (NULL);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, NONCE_LENGTH + strlen(client->pass));
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output_buffer + (i * 2), "%02x", hash[i]);
    output_buffer[64] = 0;

    return (output_buffer);
}

unsigned short csum(unsigned short *buf, int nwords)
{
    unsigned long sum;

    for (sum = 0; nwords > 0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (unsigned short)(~sum);
}

void error_msg(char *msg)
{
    perror(msg);
    exit(84);
}