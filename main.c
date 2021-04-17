// don't include .c files on larger projects
#include "utilities.c"

int main(int argc, char *argv[])
{

    if (argc == 2 && strcmp("add_user", argv[1]) == 0)
    {
        printf("Please enter here your nickname: ");
        char inp_nick[64];
        fgets(inp_nick, 9, stdin);
        inp_nick[strlen(inp_nick) - 1] = '\0';

        printf("Please enter here your password: ");
        char inp_pass[64];
        fgets(inp_pass, 9, stdin);
        inp_pass[strlen(inp_pass) - 1] = '\0';

        printf("Please enter here your personal information: ");
        char inp_info[256];
        fgets(inp_info, 100, stdin);
        inp_info[strlen(inp_info) - 1] = '\0';

        int status = sign_up(inp_nick, inp_pass, inp_info);
        if (status == 1)
        {
            fprintf(stderr, "Error: nickname already exists.");
            return 1;
        }

        return 0;
    }

    else if (argc == 1)
    {
        printf("Please enter here your nickname: ");
        char inp_nick[64];
        fgets(inp_nick, 9, stdin);
        inp_nick[strlen(inp_nick) - 1] = '\0';

        printf("Please enter here your password: ");
        char inp_pass[64];
        fgets(inp_pass, 9, stdin);
        inp_pass[strlen(inp_pass) - 1] = '\0';

        user current_user = log_in(inp_nick, inp_pass);

        if (strcmp(current_user.nickname, "") == 0)
        {
            fprintf(stderr, "Error: Login unsuccesful.\n");
            return 1;
        }
        else
        {
            printf("Hello, %s\n\nYour personal information:\n %s\n", current_user.nickname, current_user.info);

            return 0;
        }

    }

    else
    {
        fprintf(stderr, "Usage: ./main add_user to add a user or ./main to log in.");
    }
}
