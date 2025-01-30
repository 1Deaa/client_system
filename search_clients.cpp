/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_clients.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:22:12 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/30 18:22:13 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banksys.hpp"

void	SearchForClient(string fileName)
{
	fstream		File;
	string		Line;
	t_client	client;
	string		Target;

	File.open(fileName, ios::in);
	if (!File.is_open())
	{
		cerr << "Couldn't open file: " << fileName << endl;
		return ;
	}
	cout << "Please enter an Account Number? "; cin >> Target;
	while (getline(File, Line))
	{
		client = ExtractRecordLine(Line, DELIMITER);
		if (client.accountNumber == Target)
		{
			PrintClientData(client);
			File.close();
			return ;
		}
	}
	File.close();
	cout << "Client with Account Number (" << Target << ") was not found!" << endl;
}