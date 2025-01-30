/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clients.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:16:30 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/30 17:16:30 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banksys.hpp"

static int	CountLines(string fileName)
{
	fstream	File;
	string	Line;
	int		line_count = 0;

	File.open(fileName, ios::in);
	if (!File.is_open())
	{
		return (-1);
	}
	while (getline(File, Line))
	{
		line_count++;
	}
	File.close();
	return (line_count);
}

static void	PrintHeader(string fileName)
{
	cout << setw(50) <<"Client List (" << CountLines(fileName) << ") Client(s)" << endl;
	cout << "_____________________________________________________________________________________________________" << endl;
	cout << "                                                                                                     " << endl;
	cout << "| Account Number  | Pin Code  | Client Name                            | Phone          | Balance    " << endl;
	cout << "_____________________________________________________________________________________________________" << endl;
}

static void	PrintFooter(void)
{
	cout << "_____________________________________________________________________________________________________" << endl;
}

void	ListClients(string fileName)
{
	fstream		File;
	string		Line;
	t_client	client;

	File.open(fileName, ios::in);
	if (!File.is_open())
	{
		cerr << "Couldn't open file: " << fileName << endl;
		return ;
	}
	PrintHeader(fileName);
	while (getline(File, Line))
	{
		client = ExtractRecordLine(Line, DELIMITER);
		cout << "| " << setw(16) << left << client.accountNumber 
             << "| " << setw(10) << left << client.pinCode 
             << "| " << setw(39) << left << client.Name
             << "| " << setw(15) << left << client.phoneNumber 
             << "| " << setw(10) << left << client.accountBalance 
             << endl;
	}
	File.close();
	PrintFooter();
}