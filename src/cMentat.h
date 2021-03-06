/*

	Dune II - The Maker

	Author : Stefan Hendriks
	Contact: stefanhen83@gmail.com
	Website: http://dune2themaker.fundynamic.com

	2001 - 2009 (c) code by Stefan Hendriks

	Mentat class

	The mentat class encapsulates all mentat specific functions.
	This is a global class. In the Mentat directory there will be:

	c<anyhouse>Mentat.cpp / c<anyhouse>Mentat.h which will be derived from this class.

	There is only one mentat in-game shown to the player. Therefore a good creation/deletion of it (when switching
	houses) is essential. These responsibilities should lay in the cMentatFactory class.
*/
#ifndef CMENTAT_H
#define CMENTAT_H

#include <GameState.h>

class cMentat {

private:
	virtual void draw_mouth()=0;
	virtual void draw_eyes()=0;
	virtual void draw_other()=0;

	// Timed animation
	int TIMER_Mouth;
	int TIMER_Eyes;
	int TIMER_Other;
	int TIMER_Speaking;

	// draw 2 sentences at once, so 0 1, 2 3, 4 5, 6 7, 8 9
	char sentence[10][255];

	int iMentatSentence;			// = sentence to draw and speak with (-1 = not ready)

	int iMentatMouth;
	int iMentatEyes;
	int iMentatOther;

public:
	virtual void draw()=0;

	void think();
	void prepare(bool bTellHouse, GameState state, int house, int region);

	cMentat();
	virtual ~cMentat();
};

#endif
