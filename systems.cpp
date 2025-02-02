/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systems.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:43:45 by drahwanj          #+#    #+#             */
/*   Updated: 2025/02/02 13:43:45 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_system.h"

void	SearchClientSystem(string fileName)
{
	string		Target;
	string		Record;

	cout << "Please enter an Account Number? "; cin >> Target;
	Record = SearchForRecord(fileName, Target);
	if (Record == NOTFOUND)
	{
		cout << "Client with Account Number (" << Target << ") was not found!" << endl;
		return ;
	}
	PrintClientData(ExtractRecordLine(Record, DELIMITER));
}

void	ListClientSystem(string fileName)
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

void	DeleteClientSystem(string fileName)
{
	string	Target;
	string	Record;
	string	Answer;

	cout << "Please enter Account Number? "; cin >> Target;
	Record = SearchForRecord(fileName, Target);
	if (Record == NOTFOUND)
	{
		cout << "Client with Account Number (" << Target << ") was not found!" << endl;
		return ;
	}
	PrintClientData(ExtractRecordLine(Record, DELIMITER));
	cout << "Are you sure you want to delete this client? y/n ? "; cin >> Answer;
	if (Answer == "Yes" || Answer == "y" || Answer == "yes" || Answer == "Y" || Answer == "YES")
	{
		if (DeleteClient(fileName, Record) == false)
		{
			cout << "Couldn't delete client!" << endl;
			return ;
		}
		cout << "\n\nClient Deleted Successfully.\n" << endl;
	}
	else
	{
		cout << "\nNo changes were made!" << endl;
	}
}

void	AddClientSystem(string fileName)
{
	fstream		File;
	t_client	client;
	string		record;
	string		Ans;

	File.open(fileName, ios::out | ios::app);
	if (File.is_open())
	{
		cout << "Adding New Client: \n" << endl;
		client = EnterClientData();
		record = CreateRecordLine(client, DELIMITER);
		if (SearchForRecord(fileName, client.accountNumber) != NOTFOUND)
		{
			cout << "\nClient with this Account Number already exist!\n";
			return ;
		}
		File << record << endl;
		File.close();
		cout << "\nAdded new client successfully, do you want to add more clients? ";
		cin >> Ans;
		if (Ans == "Y" || Ans == "y" || Ans == "yes" || Ans == "Yes" || Ans == "YES")
		{
			system(CLEAN_SCREEN);
			AddClientSystem(fileName);
		}
	}
	else
	{
		cout << "Failed to open file: " << endl;
		cout << "Couldn't add new client." << endl;
	}
}

void	UpdateClientSystem(string fileName)
{
	string		Target;
	string		Record;
	string		Answer;
	t_client	client;

	cout << "Please enter Account Number? "; cin >> Target;
	Record = SearchForRecord(fileName, Target);
	if (Record == NOTFOUND)
	{
		cout << "Client with Account Number (" << Target << ") was not found!" << endl;
		return ;
	}
	client = ExtractRecordLine(Record, DELIMITER);
	PrintClientData(client);
	cout << "Are you sure you want to update this client? y/n ? "; cin >> Answer;
	if (Answer == "Yes" || Answer == "y" || Answer == "yes" || Answer == "Y" || Answer == "YES")
	{
		if (UpdateClient(fileName, client) == false)
		{
			cout << "Couldn't update client!" << endl;
			return ;
		}
		cout << "\n\nClient Updated Successfully." << endl << endl;
	}
	else
	{
		cout << "\nNo changes were made!" << endl;
	}
}

int	ShowMainMenu(void)
{
	int	Answer;

	PrintMainMenu();
	cout << "Choose what do you want to do? [1 to 6]? ";
	cin >> Answer;
	return (Answer);
}