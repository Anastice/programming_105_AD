#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main() {
    char sentence[64];
    do     {
    printf("Enter a sentence (\"stop\" to exit): ");
    if (scanf("%[^\n]s", sentence) != 1)
        {
            perror("Invalid sentence input\n");
            continue;         }

    if (!strcmp(sentence, "stop")) {
                break;
}
        char *p;
        int punct_count = 0;
        for (p = sentence; *p; ++p)  {
    if (ispunct(*p))
        ++punct_count;         }
    printf("Punts: %d\n",  punct_count);
    fflush(stdin);
        }
        while (1);
    return 0;
    }
