#include "common.h"

void shell_sort(list_t *lp)
{
    uint16_t incre = lp->len;

    while (TRUE) {
        incre /= 2;
        for (uint16_t k = 0; k < lp->len; k++) {
            for (uint16_t i = k+incre; i < lp->len; i++) {
                for (uint16_t j = i; j > 0; j -= incre) {
                    if (LGT(lp->data[j-incre], lp->data[j])) {
                        SWAP(lp->data[j-incre], lp->data[j]);
                    } else {
                        break;
                    }
                }
            }
        }

        if (incre == 1)
            break;
    }
}
