#include "so_long.h"
#include <time.h>

int random_num(int lower, int upper)
{
    srand(time(NULL));
    return lower + rand() % (upper - 0 + 1);
}
