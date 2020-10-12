#include "minishell.h"
/*
void tenv_swap(t_env **e1, t_env **e2)
{
    char *tmp_name;
    char *tmp_value;

    tmp_name = (*e1)->name;
    tmp_value = (*e1)->value;
    (*e1)->name = (*e2)->name;
    (*e1)->value = (*e2)->value;
    (*e2)->name = tmp_name;
    (*e2)->value = tmp_value;
}
*/

void tenv_swap(t_env *e1, t_env *e2)
{
    char *tmp_name;
    char *tmp_value;

    tmp_name = e1->name;
    tmp_value = e1->value;
    e1->name = e2->name;
    e1->value = e2->value;
    e2->name = tmp_name;
    e2->value = tmp_value;
}

int tenv_len(t_env *env)
{
    int i;

    i = 0;
    while (env)
    {
        i++;
        env = env->next;
    }
    return (i);
}

void ft_export_sort(t_env *env)
{
    int i;
    t_env *ptr;

    i = tenv_len(env);
    while (i)
    {
        ptr = env;
        while (ptr->next)
        {
            if (ft_strcmp(ptr->name, ptr->next->name) > 0)
            { 
                tenv_swap(ptr, ptr->next);
            }
            ptr = ptr->next;
        }
        i--;
    }
    printf("\n\n");
    tenv_print(env);
}
