//
//  Pig.cpp
//  Pig
//
//

#include "Pig.h"
#include <iostream>

namespace cs31
{
    Pig::Pig()
    {
        
    }
    
    // stringify this Game by stringifying this Game's Board
    std::string Pig::display( std::string msg )
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Pig!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Pig!\n";
            }
        }
        return( s );
    }
    
    // let the human player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the human's turn, set the board's rolled value and update the board's
    // human score accordingly
    int Pig::humanPlay( int amount )
    {
		if (Pig::isGameOver() == true)
		{
			return 0;
		}
		mBoard.setRolledValue(mHuman.roll(amount));
		mBoard.setHumanTurn();
		mBoard.setHumanScore(mBoard.getRolledValue());

		int amountrolled = mBoard.getRolledValue();
        return( amountrolled );
    }
    
    // inform the human Player that their turn has ended
    // update the board's human total
    void Pig::humanEndTurn()
    {
        mHuman.endTurn();
        mBoard.setHumanTotal( mHuman.getTotal() );
    }
    
    // let the computer player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the computer's turn, set the board's rolled value and update the board's
    // computer score accordingly
    int Pig::computerPlay( int amount )
    {
		if (Pig::isGameOver() == true)
		{
			return 0;
		}

		mBoard.setRolledValue(mComputer.roll(amount));
		mBoard.setComputerTurn();
		mBoard.setComputerScore(mBoard.getRolledValue());

		int amountrolled = mBoard.getRolledValue();
		return(amountrolled);
    }
    
    // when keeprolling returns true, the computer will keep rolling
    // this method implements a 60% chance to keep rolling...
    // unless the score plus the existing total >= SCORENECESSARYTOWIN
    bool Pig::computerKeepRolling() const
    {
        bool result( false );
        Die d( 5 );
        d.roll();
        if (d.getValue() >= 3)
        {
            result = true;
        }
        if (mComputer.getScore() + mComputer.getTotal() >= SCORENECESSARYTOWIN)
        {
            // stop...
            result = false;
        }
        return( result );
    }
    
    // inform the computer Player that their turn has ended
    // update the board's computer total
    void Pig::computerEndTurn()
    {
        mComputer.endTurn();
        mBoard.setComputerTotal( mComputer.getTotal() );
    }
    
    // determine the game outcome at this moment
    Pig::GAMEOUTCOME  Pig::determineGameOutcome( ) const
    {
		if (mComputer.getTotal() < SCORENECESSARYTOWIN && mHuman.getTotal() < SCORENECESSARYTOWIN)
		{
			GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
			return result;
		}
		else if (mHuman.getTotal() >= SCORENECESSARYTOWIN)
		{
			GAMEOUTCOME result = GAMEOUTCOME::HUMANWONGAME;
			return result;
		}
		else
		{
			GAMEOUTCOME result = GAMEOUTCOME::COMPUTERWONGAME;
			return result;
		}
    }
    
    // determine if the game is over
    // if it has, return true and inform the board that the game is over and
    // inform the board that the Human won or the Computer won, accordingly
    bool Pig::isGameOver()
    {
		if (mHuman.getTotal() >= SCORENECESSARYTOWIN || mComputer.getTotal() >= SCORENECESSARYTOWIN)
		{
			mBoard.setGameOver(true);
			if (mHuman.getTotal() >= SCORENECESSARYTOWIN)
			{
				mBoard.markHumanAsWinner();
			}
			else if (mComputer.getTotal() >= SCORENECESSARYTOWIN)
			{
				mBoard.markComputerAsWinner();
			}
			return true;
		}
		else
		{
			return(false);
		}
    }

}
