/*
** phil_start.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Mar 23 15:24:12 2010 francois1 ancel
** Last update Tue Mar 23 15:24:12 2010 francois1 ancel
*/

#ifndef PHIL_START_C_INCLUDED
# define PHIL_START_C_INCLUDED

void		*phil_start(void *strct);
int		phil_creat(pthread_t *thd, t_table *table);
int		check_ind(int ind);
int		transmit_chopstick(t_table *table, int from, int to);

#endif
