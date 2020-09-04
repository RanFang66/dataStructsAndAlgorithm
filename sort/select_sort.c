#include "common.h"

void select_sort(list_t *lp)
{
    uint16_t min_index = 0;
    for (uint16_t i = 0; i < lp->len-1; i++) {
        min_index = i;
        for (uint16_t j = i+1; j < lp->len; j++) {
            if (LGT(lp->data[min_index], lp->data[j]))
                min_index = j;
        }
        if (min_index != i) {
            SWAP(lp->data[min_index], lp->data[i]);
        }
    }
}
