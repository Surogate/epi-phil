/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Mar 23 13:05:26 2010 francois1 ancel
** Last update Tue Mar 23 13:05:26 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<pthread.h>
#include	"define.h"
#include	"t_phil.h"
#include	"t_table.h"
#include	"table_fct.h"
#include	"phil_fct.h"

int		main()
{
  int		err;
  int		i;
  pthread_t	thd[NB_PHIL];
  t_table	table;

  i = 0;
  table_init(&table);
  table_display(&table);
  err = phil_creat(thd, &table);
  if (err == EXIT_FAILURE)
    perror("phil_creat fail");
  while(i < NB_PHIL && !pthread_join(thd[i], NULL))
    i++;
  table_display(&table);
  pthread_exit(NULL);
}
