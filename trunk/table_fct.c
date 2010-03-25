/*
** table_init for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Mar 23 13:34:55 2010 francois1 ancel
** Last update Tue Mar 23 13:34:55 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "define.h"
#include "t_phil.h"
#include "t_table.h"

int	table_init(t_table *table)
{
  int	i;

  i = 0;
  while (i < NB_PHIL)
    {
      table->phil_tab[i].table = table;
      table->phil_tab[i].uid = i;
      table->phil_tab[i].chopsticks = 1;
      table->phil_tab[i].eaten = 0;
      i++;
    }
  table->ressource = NB_RESS;
  return (EXIT_SUCCESS);
}

/*
int	table_init(t_table *table)
{
  int	i;

  i = 0;
  while (i < NB_PHIL)
    {
      table->phil_tab[i].table = table;
      table->phil_tab[i].uid = i;
      if (i &1)
	table->phil_tab[i].chopsticks = 2;
      else
	table->phil_tab[i].chopsticks = 0;
      table->phil_tab[i].eaten = 0;
      i++;
    }
  table->ressource = NB_RESS;
  return (EXIT_SUCCESS);
}
*/

int	check_ress(t_table *table)
{
  int	ress;

  pthread_mutex_lock(&(table->mx_ress));
  ress = table->ressource;
  pthread_mutex_unlock(&(table->mx_ress));
  return (ress);
}

int	phil_display(t_phil *phil)
{
  printf("le philosophe %i possede %i baguette et a mange %i fois\n",
	 phil->uid, phil->chopsticks, phil->eaten);
  fflush(stdout);
  return (EXIT_SUCCESS);
}

int	table_display(t_table *table)
{
  int	i;

  i = 0;
  printf("=========================\n");
  while (i < NB_PHIL)
    {
      phil_display(table->phil_tab + i);
      i++;
    }
  printf("il reste %i part a manger\n", table->ressource);  
  printf("=========================\n");
  fflush(stdout);
  return (EXIT_SUCCESS);
}
