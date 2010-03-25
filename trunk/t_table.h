/*
** t_table for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Mar 23 13:31:02 2010 francois1 ancel
** Last update Tue Mar 23 13:31:02 2010 francois1 ancel
*/

#ifndef T_TABLE_INCLUDED
# define T_TABLE_INCLUDED

typedef struct
{
  t_phil		phil_tab[NB_PHIL];
  pthread_mutex_t	mx_tab[NB_PHIL];
  pthread_mutex_t	mx_ress;
  int			ressource;
}			t_table;

#endif
