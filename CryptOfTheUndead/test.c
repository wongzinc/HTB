#include <stdio.h>
#include <string.h>

bool ends_with(char *param1,char *param2) {
    if (strlen(param2) <= strlen(param1)) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    printf("%s\n",argv[2]);
    int var1 = ends_with("1234","123");
    return 0;
}