/*
** xpthread for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Mar 30 17:19:26 2010 francois1 ancel
** Last update Tue Mar 30 17:19:26 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include "t_xpth.h"



void		mutex_error(int err)
{
  int		i;
  static t_xpth tab[] =
    {
      {EINVAL, "mutex not init"},
      {EDEADLK, "mutex already lock"},
      {EBUSY, "mutex already lock"},
      {EPERM, "mutex lock by other"},
      {0, NULL}
    };

  i = 0;
  while (tab[i].err)
    {
      if (tab[i].err == err)
	fprintf(stderr,"error :: %s\n", tab[i].str);
      i++;
    }
  fflush(stdout);
}

int		xpmutex_lock(pthread_mutex_t *mutex)
{
  int		err;

  err = pthread_mutex_lock(mutex);
  if (err)
    mutex_error(err);
  return (err);
  }

int		xpmutex_unlock(pthread_mutex_t *mutex)
{
  int		err;

  err = pthread_mutex_unlock(mutex);
  if (err)
    mutex_error(err);
  return (err);
}

int		xpmutex_destroy(pthread_mutex_t *mutex)
{
  int		err;

  err = pthread_mutex_destroy(mutex);
  if (err)
    mutex_error(err);
  return (err);
}
