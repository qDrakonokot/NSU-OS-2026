#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>



int main () {
    uid_t uid = getuid();
    uid_t euid = geteuid();
    printf("UID: %u\n", (unsigned int)uid);
    printf("EUID: %u\n", (unsigned int)euid);

    FILE* file = fopen("file", "r");
    if (file == NULL) {
        perror("Failed to open file for the first time");
    } else {
        printf("Succesfull opened file\n");
        fclose(file);
    }
    
    int ret_c = setuid(uid); //set up EIUD equals to UID 
    if (ret_c != 0) {
        perror("failed to set EUID");
        return 1;
    }

    uid = getuid();
    euid = geteuid();
    printf("UID: %u\n", (unsigned int)uid);
    printf("EUID: %u\n", (unsigned int)euid);

    file = fopen("file", "r");
    if (file == NULL) {
        perror("Failed to open file for the second time");
    } else {
        printf("Succesfull opened file\n");
        fclose(file);
    }

    return 0;
}

