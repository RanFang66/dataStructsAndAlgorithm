#include "common.h"

void insert_sort(list_t *lp)
{
    for (uint16_t i = 0; i < lp->len-1; i++) {
        for (uint16_t j = i+1; j > 0; j--) {
            if (LGT(lp->data[j-1], lp->data[j])) {
                SWAP(lp->data[j-1], lp->data[j]);
            } else {
                break;
            }
        }
    }
}
