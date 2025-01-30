/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banksys.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:28:15 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/30 00:29:41 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANKSYS_HPP
# define BANKSYS_HPP

# define DELIMITER "#//#"

# include <iostream>
# include <string.h>
# include <fstream>
# include <iomanip>

using namespace std;

typedef struct client
{
	string	accountNumber;
	string	pinCode;
	string	Name;
	string	phoneNumber;
	double	accountBalance;
} t_client;

//CLIENT_SYSTEM
t_client	EnterClientData(void);
string		CreateRecordLine(t_client client, string sep = DELIMITER);
t_client	ExtractRecordLine(string record, string sep = DELIMITER);
void		PrintClientData(t_client client);

//ADD
void	AddNewClient(string filename);
//LIST
void	ListClients(string fileName);
//SEARCH
void	SearchForClient(string fileName);

#endif
