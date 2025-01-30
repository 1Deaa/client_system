/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_client.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:24:28 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/30 16:24:28 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banksys.hpp"

void	AddNewClient(string filename)
{
	fstream		File;
	t_client	client;
	string		record;
	string		Ans;

	File.open(filename, ios::out | ios::app);
	if (File.is_open())
	{
		cout << "Adding New Client: \n" << endl;
		client = EnterClientData();
		record = CreateRecordLine(client);
		File << record << endl;
		File.close();
		cout << "\nAdded new client successfully, do you want to add more clients? ";
		cin >> Ans;
		if (Ans == "Y" || Ans == "y" || Ans == "yes" || Ans == "Yes" || Ans == "YES")
		{
			system("clear"); // NOTE: Change for Windows "cls"
			AddNewClient(filename);
		}
	}
	else
	{
		cout << "Failed to open file: " << endl;
		cout << "Couldn't add new client." << endl;
	}
}
