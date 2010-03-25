/*
** philo_start for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Mar 23 13:20:39 2010 francois1 ancel
** Last update Thu Mar 25 18:15:29 2010 francois1 ancel
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
  int		ress;

  phil = (t_phil *)strct;
  table = (t_table *)phil->table;
  ress = check_ress(table);
  phil_display(phil);
  while (ress)
    {
      pthread_mutex_lock(table->mx_tab + phil->uid);
      if (phil->chopsticks >= 2)
	eat_rice(table, phil);
      pthread_mutex_unlock(table->mx_tab + phil->uid);
      pthread_mutex_lock(table->mx_tab + phil->uid);
      if (phil->chopsticks)
	transmit_chopstick(table, phil->uid, phil->uid + 1);
      pthread_mutex_unlock(table->mx_tab + phil->uid);
      ress = check_ress(table);
    }
  pthread_exit(NULL);
}

int		check_ind(int ind)
{
  int		i;

  if (ind < 0)
    ind = NB_PHIL - 1;
  i = ind % NB_PHIL;
  return (i);
}

int		eat_rice(t_table *table, t_phil *phil)
{
  printf("phil-%i > je tente de manger\n", phil->uid);
  pthread_mutex_lock(&(table->mx_ress));
  phil->eaten++;
  table->ressource--;
  pthread_mutex_unlock(&(table->mx_ress));
  sleep(1);
  printf("phil-%i > j'ai manger\n", phil->uid);
  return (EXIT_SUCCESS);
}

int		transmit_chopstick(t_table *table, int from, int to)
{
  from = check_ind(from);
  to = check_ind(to);
  printf("je tente de transmit\n");
  pthread_mutex_lock(table->mx_tab + to);
  if (table->phil_tab[from].chopsticks == 2
      && table->phil_tab[to].chopsticks == 0)
    {
      table->phil_tab[to].chopsticks = 2;
      table->phil_tab[from].chopsticks = 0;
    }
  else if (table->phil_tab[from].chopsticks == 1
      && table->phil_tab[to].chopsticks == 0)
    {
      table->phil_tab[to].chopsticks = 1;
      table->phil_tab[from].chopsticks = 0;
    }
  else if (table->phil_tab[from].chopsticks == 1
      && table->phil_tab[to].chopsticks == 1)
    {
      table->phil_tab[to].chopsticks = 2;
      table->phil_tab[from].chopsticks = 0;
    }
  pthread_mutex_unlock(table->mx_tab + to);
  printf("j'ai transmit\n");
  return (EXIT_SUCCESS);
}

int		phil_creat(pthread_t *thd, t_table *table)
{
  int		i;
  int		err;

  i = 0;
  pthread_mutex_init(&(table->mx_ress), NULL);
  pthread_mutex_init(&(table->mx_trans), NULL);
  while (i < NB_PHIL)
    {
      pthread_mutex_init(table->mx_tab + i, NULL);
      err = pthread_create(thd + i, NULL, phil_start, table->phil_tab + i);
      if (err)
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}
