#include <stdlib.h>
#include "common.h"
#include <stdio.h>

void merge(list_t *lp, int16_t l, int16_t mid, int16_t r, elem_t *tmp)
{
    int16_t i = l, j = mid;
    int16_t m = mid, n = r;
    int16_t k = 0;

    while (i < m && j < n) {
        if (LGT(lp->data[i], lp->data[j])) {
            tmp[k++] = lp->data[j++];
        } else {
            tmp[k++] = lp->data[i++];
        }

        while (i < m) {
            tmp[k++] = lp->data[i++];
        }

        while (j < n) {
            tmp[k++] = lp->data[j++];
        }

        for (i = 0; i < k; i++) {
            lp->data[l+i] = tmp[i];
        }
    }
}

void merge_recur(list_t *lp, int16_t l, int16_t r, elem_t *tmp)
{
    if (l < r) {
        int16_t mid = (l + r) / 2;
        merge_recur(lp, l, mid, tmp);
        merge_recur(lp, mid+1, r, tmp);
        merge(lp, l, mid, r, tmp);
    }
}

void merge_sort(list_t *lp)
{
    elem_t *tmp;
    tmp = malloc(MAXLEN * sizeof(elem_t));
    if (tmp == NULL)
        exit(1);
    merge_recur(lp, 0, lp->len-1, tmp);

    free(tmp);
}
