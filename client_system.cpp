/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:13:36 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/30 15:13:39 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banksys.hpp"

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

void	PrintClientData(t_client client)
{
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


