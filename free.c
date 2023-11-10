#include "unish.h"
/**
 *_free - free
 *@l:line
 *@c:l_cp
 *@args:array
 *@i:number
 */
void _free(char *l, char *c, char **args, int i)
{
        int j;

        l == NULL ? (void)l : free(l);
        c == NULL ? (void)c : free(c);
        if (args == NULL)
        {
                (void)args;
                (void)i;

        }
        else if ((i = 0))
                free(args);
        else
        {
                for (j = 0; args[j] != NULL; j++)
                {
                        free(args[j]);
                }
                free(args);

        }
}
