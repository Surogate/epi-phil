/*
** philo_start for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Mar 23 13:20:39 2010 francois1 ancel
** Last update Tue Mar 23 13:20:39 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "define.h"
#include "t_phil.h"
#include "t_table.h"
#include "table_fct.h"
#include "phil_fct.h"

void		*phil_start(void *strct)
{
  t_phil	*phil;
  t_table	*table;

  phil = (t_phil *)strct;
  table = (t_table *)phil->table;
  phil_display(phil);
  pthread_exit(NULL);
}

int		check_ind(int ind)
{
  if (ind < 0)
    ind = NB_PHIL - 1;
  ind = ind % NB_PHIL;
  return (ind);
}

int		transmit_chopstick(t_table *table, int from, int to)
{
  from = check_ind(from);
  to = check_ind(to);
  pthread_mutex_lock(table->mx_tab + from);
  pthread_mutex_lock(table->mx_tab + to);
  table->phil_tab[from].chopstick--;
  table->phil_tab[to].chopstick++;
  pthread_mutex_unlock(table->mx_tab + from);
  pthread_mutex_unlock(table->mx_tab + to);
}

int		phil_creat(pthread_t *thd, t_table *table)
{
  int		i;
  int		err;

  i = 0;
  while (i < NB_PHIL)
    {
      err = pthread_create(thd + i, NULL, phil_start, table->phil_tab + i);
      if (err)
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}
