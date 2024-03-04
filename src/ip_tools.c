#include "ip_lib.h"

int main(void) {
    int itemMenu;
    if (scanf("%d", &itemMenu) != 1) exception();
    getchar();
    if (!menu(itemMenu)) exception();
    exit(EXIT_SUCCESS);
}