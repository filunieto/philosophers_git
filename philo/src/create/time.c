/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:11:13 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/13 12:30:55 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	struct timeval 
		time_t      tv_sec;      seconds 
		suseconds_t tv_usec;     microseconds 
	}
	La funcion imprimira el estado del filososfo (sleeps, thinks,..) 
	con su respectivo id.
	Si un threads llama a la función la bloqueará hasta que imprima, 
	y acto seguido se desbloqueará.
	Hacemos mutex en print y en run , porque  tanto la impresion por pantalla 
	como  cambio de estado debe ser asegurado , para que otro thread no acceda
	a él en ese instante.
*/


int	print_time_msg(t_philosop *philos, char *messg)
{
	int	running;
	int	new_diff;

	new_diff = gettimediff((struct timeval *)&philos->philo->start_dinner);
	pthread_mutex_lock(&philos->philo->mutex_print);
	pthread_mutex_lock(&philos->philo->mutex_run);
	running = philos->philo->running;
	//printf("En print_time_msg: Philosofer %i, estado %i \n", philos->id, philos->status_phi);
	if (running)
		printf(GRAY"%d "BLUE"%d %s\n", new_diff, philos->id, messg);
	pthread_mutex_unlock(&philos->philo->mutex_run);
	pthread_mutex_unlock(&philos->philo->mutex_print);
	return (running);
}

/*
	Devuelve la diferencia del instante dado con el
	instante actual
*/
int	gettimediff(struct timeval *t)
{
	struct timeval	now;
	int				diff_time;
	//struct timeval	*time_diff;     usar esta variable para devolverla en lugar 
	gettimeofday(&now, NULL); //habría que asegurarla?
	diff_time = ((now.tv_sec - t->tv_sec) * 1000 + (now.tv_usec - t->tv_usec) / 1000);

	return (diff_time);
}

/*
	Devuelve la hora actual en ms
*/
long	get_actual_time(void)
{
	struct	timeval time_act;
	long	millsecond;
	
	gettimeofday(&time_act, NULL);
	millsecond = time_act.tv_sec * 1000;
	millsecond = millsecond +  time_act.tv_usec / 1000;
	return (millsecond);
}

/*
	Devuelve el status del philosofo
	Ejemplo caso en el que un filosofo come por primera vez:
	started_eating: instante en el que comienza a comer el filosofo. Actualizado en funcion void philo_eats()
	Start y now, instantes actuales, al comienzo de la función.
	time_count: intervalo de tiempo durante el que come.
	A partir del whuile que es dńde se desarrolla la función:
	Mientras que now (instamte actualizado) no alcance al intervalo en el que el filossfo come (basicamente mientras el filosofo come)
	Si , desde  quue nace el filosofo más el tiempo para morir, no ha empezado a comer (now). Muere
*/
t_status_phi	time_countdown(t_philosop *philos, int time_count) //time count = tiempo necesario para comer
{
	long	start;
	long	now;
	long	started_eating;

	start = get_actual_time();
	now = start;
	started_eating = philos->start_eating.tv_sec * 1000  //Momento en el que comienza a comer el filososo, antes de que esta función sea llamada
		+ philos->start_eating.tv_usec / 1000;
	while (now < (start + time_count)) //mientras no transcurra el periodo en el que el filosofo come
	{
		//write(1, "llega al usleep?\n", 19);
		usleep(100);//debajo del if ?? Por qué 100?
		now = get_actual_time();//debajo de if 
		//si empieza a comer después de que haya pasaod el tiempo time to die , morirá
		if (started_eating + philos->philo->time_die < now) //el momento en el que . Creeo que este if tendría que estar justo debajo del while y despues el usleep
		{
			//write(1, "muere en time_countdown?\n", 27);
			philos->status_phi = DIEDS;
			return (philos->status_phi);
		}
	}
	return (philos->status_phi);
}
