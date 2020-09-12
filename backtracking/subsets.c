#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

void OutputSubset(int i, list_t A, list_t B, int *num);

int
main(int argc, char* argv[])
{
    list_t A, B;
    int d, len, num;

    printf("please input the number of element in Set A:\n");
    scanf("%d", &len);
    list_init(&A, len);
    list_init(&B, len);

    printf("please input the %d element of set A:\n", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &d);
        list_append(A, d);
    }

    num = 0;
    OutputSubset(0, A, B, &num);
    printf("There's %d subsets of set A.\n", num);

    list_free(&A);
    list_free(&B);

    return 0;
}

list_status_t
print_elem(elem_t d)
{
    printf("%d\t", d);
    return LIST_OK;
}

void
OutputSubset(int i, list_t A, list_t B, int *num)
{
    elem_t d;

    if (i >= A->len) {
        list_traverse(B, print_elem);
        putchar('\n');
        (*num)++;
    }
    else {
        list_get_elem(A, i, &d);        

        list_append(B, d);
        OutputSubset(i+1, A, B, num);
        
        list_delete(B, B->len-1);
        OutputSubset(i+1, A, B, num);
    }
}

