#include "ip_lib.h"

char* getAddress() {
    char* string = NULL;
    int length = 0;
    char curr;
    while ((curr = getchar()) != '\n' && curr != EOF) {
        void* temp = realloc(string, ++length * sizeof(char));
        if (temp != NULL) {
            string = temp;
            string[length - 1] = curr;
        }
    }
    void* temp = realloc(string, (length + 1) * sizeof(char));
    if (temp != NULL) {
        string = temp;
        string[length] = '\0';
    }
    return string;
}

int stringValidity(char* string) {
    int status = 0;
    char pattern[] = "^([0-9]{1,4}.){3}[0-9]{1,4}$";
    if (match(string, pattern)) status = 1;
    return status;
}

int addressValidity(char* address) {
    int status = 0;
    char pattern[] =
        "^((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9]).){3}(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])$";
    if (match(address, pattern)) status = 1;
    return status;
}

int match(char* string, char* pattern) {
    int status = 1;
    regex_t regex;
    if (!regcomp(&regex, pattern, REG_EXTENDED)) {
        status = regexec(&regex, string, 0, NULL, 0);
        regfree(&regex);
    }
    return !status;
}

int oneSubnet(char* address1, char* address2) {
    int status = 0;
    if (addressValidity(address1) && addressValidity(address2)) {
        int index = strrchr(address1, '.') - address1;
        status = strncmp(address1, address2, index * sizeof(char));
    }
    return !status;
}

int menu(int itemMenu) {
    int status = 1;
    switch (itemMenu) {
        case 1:
            char* address = getAddress();
            stringValidity(address) ? (addressValidity(address) ? printf("VALID") : printf("INVALID"))
                                    : exception();
            break;
        case 2:
            char* address1 = getAddress();
            char* address2 = getAddress();
            stringValidity(address1) && stringValidity(address2)
                ? (oneSubnet(address1, address2) ? printf("YES") : printf("NO"))
                : exception();
            break;
        default:
            status = 0;
            break;
    }
    return status;
}

void exception() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}