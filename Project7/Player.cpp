//
//  Player.cpp
//  Pig
//
//

#include "Player.h"
#include "Board.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    
    // roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Player::roll( int amount )
    {
		int roll(0);
		if (amount == 0)
		{
			mDie.roll();
			roll = mDie.getValue();
		}
		else if (amount >= 1 && amount <= 6)
		{
			roll = amount;
		}
		if (roll >= 2 && roll <= 6)
		{
			mScore += roll;
		}
		else
		{
			mScore = 0;
		}
		return (roll);
    }
    
    // add the current score into the running total since the turn ended
    //       reset the current score to 0 for the next round of play
    void Player::endTurn()
	{
		mTotal += mScore;
		mScore = 0;
    }
    
    // return the current total
    int Player::getTotal( ) const
    {
		return mTotal;
    }
    
    // return the current total
    int  Player::getScore( ) const
    {
		return mScore;
    }
    

}
