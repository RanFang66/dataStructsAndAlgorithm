#include <stdio.h>
#include "common.h"

void bubble_sort(list_t *lp)
{
    uint16_t    flag = FALSE;
    for (uint16_t i = 0; i < lp->len-1; i++) {
        flag = FALSE;
        for (uint16_t j = lp->len-1; j > i; j--) {
            if (LGT(lp->data[j-1], lp->data[j])) {
                SWAP(lp->data[j-1], lp->data[j]);
                flag = TRUE;
            }
        }
        if (flag == FALSE)
            break;
    }
}
