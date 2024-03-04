#include "ip_lib.h"

int main(void) {
    oneSubnet(getAddress(), getAddress()) ? printf("YES") : printf("NO");
    exit(EXIT_SUCCESS);
}