/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:49 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/30 14:23:50 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_system.h"

int main(void)
{
	string	fileName = "clients.txt";
	int		Answer = 0;

	while (true)
	{
		Answer = ShowMainMenu();
		if (Answer == 1)
		{
			system(CLEAN_SCREEN);
			ListClientSystem(fileName);
			system(GO_BACK);
			system(CLEAN_SCREEN);
		}
		else if(Answer == 2)
		{
			system(CLEAN_SCREEN);
			AddClientSystem(fileName);
			system(GO_BACK);
			system(CLEAN_SCREEN);
		}
		else if (Answer == 3)
		{
			system(CLEAN_SCREEN);
			DeleteClientSystem(fileName);
			system(GO_BACK);
			system(CLEAN_SCREEN);
		}
		else if (Answer == 4)
		{
			system(CLEAN_SCREEN);
			UpdateClientSystem(fileName);
			system(GO_BACK);
			system(CLEAN_SCREEN);
		}
		else if (Answer == 5)
		{
			system(CLEAN_SCREEN);
			SearchClientSystem(fileName);
			system(GO_BACK);
			system(CLEAN_SCREEN);
		}
		else
		{
			system(CLEAN_SCREEN);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
