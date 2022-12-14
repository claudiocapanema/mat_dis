//
// Created by claudio on 23/10/22.
//

#ifndef UNTITLED_PASSEIO_H
#define UNTITLED_PASSEIO_H

#endif //UNTITLED_PASSEIO_H


#include <stdio.h>
#define N 8

int is_valid(int i, int j, int sol[N+1][N+1]) {
    if (i>=1 && i<=N && j>=1 && j<=N && sol[i][j]==-1)
        return 1;
    return 0;
}

int knight_tour(int sol[N+1][N+1], int i, int j, int step_count, int x_move[], int y_move[]) {
    if (step_count == N*N)
        return 1;

    int k;
    for(k=0; k<8; k++) {
        int next_i = i+x_move[k];
        int next_j = j+y_move[k];

        if(is_valid(i+x_move[k], j+y_move[k], sol)) {
            sol[next_i][next_j] = step_count;
            if (knight_tour(sol, next_i, next_j, step_count+1, x_move, y_move))
                return 1;
            sol[i+x_move[k]][j+y_move[k]] = -1; // backtracking
        }
    }

    return 0;
}

int start_knight_tour(int x0, int y0) {
    int sol[N+1][N+1];

    int i, j;
    for(i=1; i<=N; i++) {
        for(j=1; j<=N; j++) {
            sol[i][j] = -1;
        }
    }

    int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[x0][y0] = 0; // placing knight at cell(1, 1)

    if (knight_tour(sol, x0, y0, 1, x_move, y_move)) {
        FILE* f = fopen("saida.txt", "a");
        for(i=1; i<=N; i++) {
            for(j=1; j<=N; j++) {
                printf("%d ",sol[i][j] + 1);
                fprintf(f,"%d ", sol[i][j] + 1);

            }
            fprintf(f,"\n");
            printf("\n");

        }
        fprintf(f,"64 0\n");
        fclose(f);
        return 1;
    }
    return 0;
}

void passeio(int x0, int y0) {
    printf("funcao\n");
    printf("x %d y %d\n", x0, y0);
    //printf("%d\n",start_knight_tour(x0, y0));
}