#include "ip_lib.h"

int main(void) {
    addressValidity(getAddress()) ? printf("VALID") : printf("INVALID");
    exit(EXIT_SUCCESS);
}
