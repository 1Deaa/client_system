/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:45:55 by drahwanj          #+#    #+#             */
/*   Updated: 2025/02/02 13:45:56 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_system.h"

int	CountLines(string fileName)
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

void	PrintHeader(string fileName)
{
	cout << setw(50) <<"Client List (" << CountLines(fileName) << ") Client(s)" << endl;
	cout << "_____________________________________________________________________________________________________" << endl;
	cout << "                                                                                                     " << endl;
	cout << "| Account Number  | Pin Code  | Client Name                            | Phone          | Balance    " << endl;
	cout << "_____________________________________________________________________________________________________" << endl;
}

void	PrintFooter(void)
{
	cout << "_____________________________________________________________________________________________________" << endl;
}

bool	DeleteClient(string fileName, string Record)
{
	fstream			file;
	fstream			new_file;
	string			line = " ";

	new_file.open(TEMPFILE, ios::out);
	file.open(fileName, ios::in);
	if (!new_file.is_open())
	{
		cout << "Couldn't write to file: Temp.txt" << endl;
		return (false);
	}
	if (!file.is_open())
	{
		cout << "Couldn't open file: " << fileName<< endl;
		return (false);
	}
	while (getline(file, line))
	{
		if (line != Record)
		{
			new_file << line << endl;
		}
	}
	file.close();
	new_file.close();
	remove(fileName.c_str());
	rename(TEMPFILE, fileName.c_str());
	return (true);
}

void	PrintClientData(t_client client)
{
	cout << "\nThe following are the client details: \n" << endl;
	cout << "Account Number  : " << client.accountNumber << endl;
	cout << "Pin Code        : " << client.pinCode << endl;
	cout << "Name            : " << client.Name << endl;
	cout << "Phone           : " << client.phoneNumber << endl;
	cout << "Account Balance : " << client.accountBalance << endl;
}

string	CreateRecordLine(t_client client, string sep)
{
	string	str;

	str += client.accountNumber + sep;
	str += client.pinCode + sep;
	str += client.Name + sep;
	str += client.phoneNumber + sep;
	str += to_string(client.accountBalance);
	return (str);
}

t_client	ExtractRecordLine(string record, string sep)
{
	t_client	client;
	string		str[5];
	int			pos = 0;
	int			i = 0;

	while (record.find(sep) != std::string::npos)
	{
		pos = record.find(sep);
		str[i] = record.substr(0, pos);
		i++;
		record.erase(0, pos + sep.length());
	}
	if (record != "")
		str[i] = record;
	client.accountNumber = str[0];
	client.pinCode = str[1];
	client.Name = str[2];
	client.phoneNumber = str[3];
	client.accountBalance = stod(str[4]);
	return (client);
}

t_client	EnterClientData(void)
{
	t_client client;

	printf("Enter Account Number? ");
	cin >> client.accountNumber;
	printf("Enter PinCode? ");
	cin >> client.pinCode;
	printf("Enter Name? ");
	cin.ignore();
	getline(cin, client.Name);
	printf("Enter Phone? ");
	cin >> client.phoneNumber;
	printf("Enter AccountBalance? ");
	cin >> client.accountBalance;
	return (client);
}

string	SearchForRecord(string fileName, string accnum)
{
	fstream		file;
	string		line;
	t_client	client;

	
	file.open(fileName, ios::in);
	if (!file.is_open())
	{
		cerr << "Couldn't open file: " << fileName << endl;
		return (NOTFOUND);
	}
	while (getline(file, line))
	{
		client = ExtractRecordLine(line, DELIMITER);
		if (client.accountNumber == accnum)
		{
			return (line);
			file.close();
		}
	}
	file.close();
	return (NOTFOUND);
}

bool	UpdateClient(string fileName, t_client client)
{
	string		Record;
	string		Old_Record;
	fstream		file;
	

	Old_Record = CreateRecordLine(client, DELIMITER);
	cout << "Enter PinCode? "; cin >> client.pinCode;
	cout << "Enter Name? "; cin >> client.Name;
	cout << "Enter Phone? "; cin >> client.phoneNumber;
	cout << "Enter AccountBalance? "; cin >> client.accountBalance;
	Record = CreateRecordLine(client, DELIMITER);
	if (DeleteClient(fileName, Old_Record) == false)
	{
		file.close();
		return (false);
	}
	file.open(fileName, ios::app);
	if (!file.is_open())
	{
		cerr << "Couldn't open file: " << fileName << endl;
		return (false);
	}
	file << Record << endl;
	file.close();
	return (true);
}

void	PrintMainMenu(void)
{
	cout << "=====================================" << endl;
	cout << setw(15) << "[1] Show Client List." << endl;
	cout << setw(15) << "[2] Add New Client." << endl;
	cout << setw(15) << "[3] Delete Client." << endl;
	cout << setw(15) << "[4] Update Client Info." << endl;
	cout << setw(15) << "[5] Find Client." << endl;
	cout << setw(0) << "[6] Exit." << endl;
	cout << "=====================================" << endl;
}