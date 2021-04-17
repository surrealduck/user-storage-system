#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nickname[64];
    char password[64];
    char info[256];
} user;

bool check_nick_existance(char nick[]);

user log_in(char nick[], char pass[])
{
    user new_user;

    FILE *storage = fopen("storage.txt", "r");
    char file_nick[64];
    char file_pass[64];
    char file_info[256];

    // check all users in file
    while (!feof(storage))
    {
        fscanf(storage, "%[^,],%[^,],%[^\n]\n", file_nick, file_pass, file_info);


        if (strcmp(file_nick, nick) == 0 && strcmp(file_pass, pass) == 0)
        {
            strcpy(new_user.nickname, file_nick);
            strcpy(new_user.password, file_pass);
            strcpy(new_user.info, file_info);

            fclose(storage);

            return new_user;
        }
    }

    fclose(storage);

    strcpy(new_user.nickname, "");
    strcpy(new_user.password, "");
    strcpy(new_user.info, "");

    return new_user;
}

int sign_up(char newnick[], char newpass[], char newinfo[])
{
    bool nick_exists = check_nick_existance(newnick);
    if (nick_exists)
    {
        return 1;
    }

    FILE *storage = fopen("storage.txt", "a");
    fprintf(storage, "%s,%s,%s\n", newnick, newpass, newinfo);

    fclose(storage);
}

bool check_nick_existance(char nick[])
{
    FILE *storage = fopen("storage.txt", "r");
    char file_nick[64];

    while (!feof(storage))
    {
        fscanf(storage, "%[^,],%*[^,],%*[^\n]\n", file_nick);

        if (strcmp(file_nick, nick) == 0)
        {
            fclose(storage);
            return true;
        }
    }

    fclose(storage);
    return false;
}
