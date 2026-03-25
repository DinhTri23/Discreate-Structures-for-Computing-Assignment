#ifndef _BELLMAN_H_
#define _BELLMAN_H_

#include "main.h"

using namespace std;
void BF(const int graph[][20], int num_vertices, char start_vertex,
        int distance[], int pre[]);
string BF_Path(const int graph[][20], int num_vertices, char start, char goal);
#endif 