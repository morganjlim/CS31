#ifndef BOXOFFICE_H
#define BOXOFFICE_H

#include "Ticket.h"
#include <string>
using namespace std;

class BoxOffice
{
public:
	BoxOffice();
	double detPrice(Ticket::KIND kind, string daytime, string row);
	
	Ticket buyTicket(string row, int seat,
		string event, string venue,
		Ticket::KIND kind, string daytime);
	Ticket buyRoyceHallStudentTicket(string row, int seat,
		string event, Ticket::KIND kind, string daytime);
	Ticket buyRoyceHallStaffTicket(string row, int seat,
		string event, Ticket::KIND kind, string daytime);
	Ticket buyRoyceHallTicket(string row, int seat,
		string event, Ticket::KIND kind, string daytime);

};

#endif // !BOXOFFICE_H
