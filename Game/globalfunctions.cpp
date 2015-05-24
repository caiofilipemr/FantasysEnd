#include "globalfunctions.h"

int random(int num_rand) {
    srand(time(NULL));
    return (rand() % num_rand);
}

std::stack<Direction> shortPass(int begin_i, int begin_j, int end_i, int end_j)
{

    Cell **pto = CellArray::instance()->get();
    std::stack<Direction> path;
    std::queue<Cell*> short_pass_queue;
    pto[begin_i][begin_j].pos_i = begin_i;
    pto[begin_i][begin_j].pos_j = begin_j;
    pto[begin_i][begin_j].back_direction = SLEEP;
    pto[begin_i][begin_j].visited = true;
    short_pass_queue.push(&pto[begin_i][begin_j]);


    Cell * first;
    int i, j, xb = begin_i - 5, xe = begin_i + 5, yb = begin_j - 5, ye = begin_j + 5;
    while (!short_pass_queue.empty() && (short_pass_queue.front()->pos_i != end_i || short_pass_queue.front()->pos_j != end_j)) {

        first = short_pass_queue.front();
        short_pass_queue.pop();
        i = first->pos_i;
        j = first->pos_j;
        if (hasPoint(i+1, j) && pto[i+1][j].free && !pto[i+1][j].visited) {
            pto[i+1][j].back_cell = &pto[i][j];
            pto[i+1][j].back_direction = DOWN;
            pto[i+1][j].visited = true;
            short_pass_queue.push(&pto[i+1][j]);
        }
        if (hasPoint(i, j+1) && pto[i][j+1].free && !pto[i][j+1].visited) {
            pto[i][j+1].back_cell = &pto[i][j];
            pto[i][j+1].back_direction = RIGHT;
            pto[i][j+1].visited = true;
            short_pass_queue.push(&pto[i][j+1]);
        }
        if (hasPoint(i-1, j) && pto[i-1][j].free && !pto[i-1][j].visited) {
            pto[i-1][j].back_cell = &pto[i][j];
            pto[i-1][j].back_direction = UP;
            pto[i-1][j].visited = true;
            short_pass_queue.push(&pto[i-1][j]);
        }
        if (hasPoint(i, j-1) && pto[i][j-1].free && !pto[i][j-1].visited) {
            pto[i][j-1].back_cell = &pto[i][j];
            pto[i][j-1].back_direction = LEFT;
            pto[i][j-1].visited = true;
            short_pass_queue.push(&pto[i][j-1]);
        }
    }
    if (short_pass_queue.empty()) throw "Out of Range!";



    first = short_pass_queue.front();
    i = first->pos_i;
    j = first->pos_j;

    Cell *pt_aux = &pto[i][j];
    while (pt_aux->back_cell) {
        path.push(pt_aux->back_direction);
        pt_aux = pt_aux->back_cell;
    }
    return path;
}


