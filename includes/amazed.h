/*
** EPITECH PROJECT, 2025
** B-CPE-200-STG-2-1-amazed-mansur.khabibov
** File description:
** amazed
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>

#ifndef A_MAZE_D
    #define A_MAZE_D

typedef struct robot {
    int id;
    char **path;
    int path_index;
    int finished;
} robot_t;

typedef struct link {
    char *name;
    int x;
    int y;
    struct link *next;
} link_t;

typedef struct node {
    link_t *room;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
} queue_t;


typedef struct tunnel {
    int source;
    int destination;
    struct tunnel *next;
} tunnel_t;

typedef struct list {
    link_t *head;
    tunnel_t *tunnel_head;
} list_t;

typedef struct graph {
    int v;
    list_t *array;
} graph_t;

typedef struct data_s {
    int nb_robots;
    int nb_rooms;
    graph_t elements;
    link_t start_room;
    link_t end_room;
} data_t;

void bfs(graph_t *graph, link_t *start_room);
link_t *build_my_graph(void);
void print_data_of_connected_links(link_t *link);
void connect_links(link_t *link1, link_t *link2);
void print_link(link_t *link);
link_t *create_link(int data);
void print_my_graph_data(graph_t *graph);

#endif /* A_MAZE_D */
