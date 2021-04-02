#include "BoxOffice.h"
#include "Ticket.h"
#include "Project5Helper.h"
#include <string>
using namespace std;

BoxOffice::BoxOffice(){}

//orchestra tickets: double price then apply discount

Ticket BoxOffice::buyTicket(string row, int seat,
	string event, string venue,
	Ticket::KIND kind, string daytime)
{
	Ticket t = Ticket(row, seat, event, venue, 0, kind, daytime);
	return t;
}


Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat,
	string event, Ticket::KIND kind, string daytime)
{
	double price = detPrice(kind, daytime, row);

	if (price >= 40)
	{
		price = price - 30;
	}
	else
	{
		price = price - (price * .2);
	}

	Ticket t = Ticket(row, seat, event, "Royce Hall", price, kind, daytime);
	return t;
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat,
	string event, Ticket::KIND kind, string daytime)
{
	double price = detPrice(kind, daytime, row);

	if (price >= 40)
	{
		price = price - 20;
	}
	else
	{
		price = price - (price * .1);
	}

	Ticket t = Ticket(row, seat, event, "Royce Hall", price, kind, daytime);
	return t;
}

//done
Ticket BoxOffice::buyRoyceHallTicket(string row, int seat,
	string event, Ticket::KIND kind, string daytime)
{
	double price = detPrice(kind, daytime, row);

	Ticket t = Ticket(row, seat, event, "Royce Hall", price, kind, daytime);
	return t;
}

double BoxOffice::detPrice(Ticket::KIND kind, string daytime, string row)
{
	double price(0);
	Project5Helper h = Project5Helper();

	switch (kind)
	{
	case Ticket::KIND::ATHLETICGAME:
		price = 75;
		break;
	case Ticket::KIND::CONCERT:
		if (h.endsWithPM(daytime))
		{
			price = 65;
		}
		else
		{
			price = 50;
		}
		break;
	case Ticket::KIND::MOVIE:
		price = 12.50;
		break;
	case Ticket::KIND::OTHER:
		if (h.endsWithPM(daytime))
		{
			price = 55;
		}
		else
		{
			price = 40;
		}
		break;
	}

	if (h.startsWithOrchestra(row))
	{
		price *= 2;
	}

	return price;
}