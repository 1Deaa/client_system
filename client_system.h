/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_system.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:28:15 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/30 00:29:41 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_SYSTEM_H
# define CLIENT_SYSTEM_H

# define DELIMITER "#//#"
# define NOTFOUND "NOF"
# define TEMPFILE "X9tG7Lq2ZfA8B3N1.txt"
# define CLEAN_SCREEN "clear"
# define GO_BACK "read -p '\n\nPress Enter to go back to Main Menu...' var"

# include <iostream>
# include <string.h>
# include <fstream>
# include <iomanip>
# include <vector>

using namespace std;

typedef struct client
{
	string	accountNumber;
	string	pinCode;
	string	Name;
	string	phoneNumber;
	double	accountBalance;
} t_client;

//SYSTEMS
void		ListClientSystem(string fileName);
void		SearchClientSystem(string fileName);
void		DeleteClientSystem(string fileName);
void		AddClientSystem(string fileName);
void		UpdateClientSystem(string fileName);
int			ShowMainMenu(void);
//UTILS
int			CountLines(string fileName);
void		PrintHeader(string fileName);
void		PrintFooter(void);
bool		DeleteClient(string fileName, string Record);
void		PrintClientData(t_client client);
string		CreateRecordLine(t_client client, string sep);
t_client	ExtractRecordLine(string record, string sep);
t_client	EnterClientData(void);
string		SearchForRecord(string fileName, string accnum);
bool		UpdateClient(string fileName, t_client client);
void		PrintMainMenu(void);

#endif
