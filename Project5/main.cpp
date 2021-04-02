#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "Ticket.h"
#include "BoxOffice.h"

using namespace std;

int main()
{
	//test Ticket()

	Ticket t1("row", 10, "event", "venue", 35, Ticket::CONCERT, "day time");
	assert(t1.getRow() == "row");
	assert(t1.getSeat() == 10);
	assert(t1.getEvent() == "event");
	assert(t1.getVenue() == "venue");
	assert(t1.getPrice() == 35);
	assert(t1.getKind() == Ticket::CONCERT);
	assert(t1.getDayTime() == "day time");

	Ticket t2("Pavillion Row 13", 45, "Dodgers vs. Brewers",
		"Dodger Stadium", 150.00, Ticket::ATHLETICGAME, "August 1, 7:30PM");
	assert(t2.getRow() == "Pavillion Row 13");
	assert(t2.getSeat() == 45);
	assert(t2.getEvent() == "Dodgers vs. Brewers");
	assert(t2.getVenue() == "Dodger Stadium");
	assert(t2.getPrice() == 150);
	assert(t2.getKind() == Ticket::ATHLETICGAME);
	assert(t2.getDayTime() == "August 1, 7:30PM");

	//testing BoxOffice
	BoxOffice b;

	//testing buyTicket()
	Ticket t = b.buyTicket("row", 1, "event", "venue", Ticket::OTHER, "daytime");
	assert(t.getRow() == "row");
	assert(t.getSeat() == 1);
	assert(t.getEvent() == "event");
	assert(t.getVenue() == "venue");
	assert(t.getKind() == Ticket::OTHER);
	assert(t.getPrice() == 0);
	assert(t.getDayTime() == "daytime");

	//testing buyRoyceHallTicket
	t = b.buyRoyceHallTicket("Orchestra Row A", 12, "Barry Manilow Live In Concert",
		Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(t.getRow() == "Orchestra Row A");
	assert(t.getSeat() == 12);
	assert(t.getEvent() == "Barry Manilow Live In Concert");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::CONCERT);
	assert(t.getPrice() == 130);
	assert(t.getDayTime() == "November 1, 7:30PM");

	t = b.buyRoyceHallTicket("Balcony Row A", 12, "Barry Manilow Live In Concert",
		Ticket::KIND::ATHLETICGAME, "November 1, 10:00AM");
	assert(t.getRow() == "Balcony Row A");
	assert(t.getSeat() == 12);
	assert(t.getEvent() == "Barry Manilow Live In Concert");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::ATHLETICGAME);
	assert(t.getPrice() == 75);
	assert(t.getDayTime() == "November 1, 10:00AM");

	t = b.buyRoyceHallTicket("Orchestra Row A", 12, "Barry Manilow Live In Concert",
		Ticket::KIND::ATHLETICGAME, "November 1, 10:00AM");
	assert(t.getRow() == "Orchestra Row A");
	assert(t.getSeat() == 12);
	assert(t.getEvent() == "Barry Manilow Live In Concert");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::ATHLETICGAME);
	assert(t.getPrice() == 150);
	assert(t.getDayTime() == "November 1, 10:00AM");

	//testing buyRoyceHallStudentTicket()
	t = b.buyRoyceHallStudentTicket("Pavillion Row U", 20,
		"Episode VII: The Force Awakens", Ticket::MOVIE,
		"September 1, 7:30PM");
	assert(t.getRow() == "Pavillion Row U");
	assert(t.getSeat() == 20);
	assert(t.getEvent() == "Episode VII: The Force Awakens");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::MOVIE);
	assert(t.getPrice() == 10);
	assert(t.getDayTime() == "September 1, 7:30PM");

	t = b.buyRoyceHallStudentTicket("Pavillion Row U", 20,
		"Gymnastics", Ticket::ATHLETICGAME,
		"September 1, 7:30PM");
	assert(t.getRow() == "Pavillion Row U");
	assert(t.getSeat() == 20);
	assert(t.getEvent() == "Gymnastics");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::ATHLETICGAME);
	assert(t.getPrice() == 45);
	assert(t.getDayTime() == "September 1, 7:30PM");

	t = b.buyRoyceHallStudentTicket("Orchestra Row U", 20,
		"Lorde", Ticket::CONCERT,
		"September 1, 7:30PM");
	assert(t.getRow() == "Orchestra Row U");
	assert(t.getSeat() == 20);
	assert(t.getEvent() == "Lorde");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::CONCERT);
	assert(t.getPrice() == 100);
	assert(t.getDayTime() == "September 1, 7:30PM");

	//testing buyRoyceHallStaffTicket()
	t = b.buyRoyceHallStaffTicket("Balcony Row J", 120,
		"An Evening With David Sedaris", Ticket::OTHER,
		"October 1, 7:30PM");
	assert(t.getRow() == "Balcony Row J");
	assert(t.getSeat() == 120);
	assert(t.getEvent() == "An Evening With David Sedaris");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::OTHER);
	assert(t.getPrice() == 35);
	assert(t.getDayTime() == "October 1, 7:30PM");

	t = b.buyRoyceHallStaffTicket("Orchestra Row J", 120,
		"Spiderman: Into The Spiderverse", Ticket::MOVIE,
		"October 1, 7:30PM");
	assert(t.getRow() == "Orchestra Row J");
	assert(t.getSeat() == 120);
	assert(t.getEvent() == "Spiderman: Into The Spiderverse");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::MOVIE);
	assert(t.getPrice() == 22.5);
	assert(t.getDayTime() == "October 1, 7:30PM");

	t = b.buyRoyceHallStaffTicket("Orchestra Row J", 120,
		"Marina And The Diamonds Live", Ticket::CONCERT,
		"October 1, 11:00AM");
	assert(t.getRow() == "Orchestra Row J");
	assert(t.getSeat() == 120);
	assert(t.getEvent() == "Marina And The Diamonds Live");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::CONCERT);
	assert(t.getPrice() == 80);
	assert(t.getDayTime() == "October 1, 11:00AM");

	cout << "all tests passed!" << endl;

	return 0;

}