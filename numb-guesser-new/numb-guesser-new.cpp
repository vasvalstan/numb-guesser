// Name : NumberGuesser.cpp

#include <iostream>
#include <cmath>

using namespace std;

/*
Create a program called number guesser.
There will be a secret number that is set at the start of the program without any user input.
The secret number should be picked from a certain range.
The range of the number should be output to the player.
The player should be prompted to enter his guess.
The prompt should show how many guesses the player has left.
The player will then enter his guess
If the guess is too high then the game will output that the guess was to high.
If the guess was to low then the game will output that it was too low.
The player only has a certain number of guesses.
The number of guesses should be based on the range of the secret number.
Any wrong guess will decrement the number of guesses left.
The game ends by saying what secret number was regardless of if the player guessed the right number.
When the game is over, the player should be prompted if he would like to play again.
If yes, then the secret number should change.
Any input errors by the player should have proper handling.
*/

void PlayGame();
bool WantToPlayAgain();

bool IsGameOver(int secretNumber, int numberOfTries, int guess);
int GetGuess(int numberOfTries);

void DisplayResult(int secretNumber, int numberOfTries);

const int IGNORE_CHARS = 256;

int main()
{
	//we need a variable that stores the secret number
	//range: 0 - 100
	//we need a variable that stores the number of guesses the player has left
	//we need a variable that will store the player's guess
	//the number of guesses will be the log base 2 of the upper range - log2(100) ~ 6.64 -> 7
	//how do we change the secret number? after the first round ended

	/*

	do
	{
		Play the game

	}while (want to play again)


	//////////////
	Play the Game:
	//////////////

	1. set the secret number - set it to a known value for now
	2. set the number of guesses -> ceil(log2(100))

	do
	{

		3. prompt the user to make a guess (output the number of guesses left)
		4. get the guess from the player
		5. check to see if the guess is equal to the secret number
			5a. if the guess is not equal to SN(secret number) then
				5a1. decrement the number of guesses left
				5a2. check to see if the guess was higher or lower than the SN
					5a2a. if it was higher, print that the guess was too high
					5a2b. if it was lower, print that the guess was too low

	}while(the game is not over)

	Display the result of the game - tell the player if he got it or not

	Functions:

	*Play the Game -> PlayGame()
	*Want to play again -> WantToPlayAgain()
	*Get the guess from the player -> GetGuess()

	*The game is not over -> IsGameOver()

		number of guesses left == 0 || player's guess == secret number

	*Display result -> DisplayResult()

		if(the player got it)
		{
			print that they got it and print the secret number
		}
		else
		{
			print that hey didn't get it and also print the secret number
		}


	*/
	do
	{
		PlayGame();
	} while (WantToPlayAgain());

	return 0;
}

void PlayGame()
{
	const int UPPER_BOUND = 100;
	int secretNumber = 65;
	int numberOfTries = ceil(log2(UPPER_BOUND));
	int guess = 0;

	cout << "The range of the number is between 0 and 100" << endl;

	do
	{
		guess = GetGuess(numberOfTries);
		if (guess != secretNumber)
		{
			numberOfTries--;

			if (guess > secretNumber)
			{
				cout << "Your guess was too high!";
			}
			else
			{
				cout << "Your guess was too low!";
			}
		}


	} while (!IsGameOver(secretNumber, numberOfTries, guess));

	DisplayResult(secretNumber, numberOfTries);

}

bool WantToPlayAgain()
{
	char input;
	bool failure;

	do
	{
		failure = false;

		cout << "Would you like to play again? (y/n)";
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Input Error! Please try again" << endl;
			failure = true;
		}

	} while (failure);

		return input == 'y';
}

bool IsGameOver(int secretNumber, int numberOfTries, int guess)
{
	return secretNumber == guess || numberOfTries <= 0;
}

int GetGuess(int numberOfTries)
{
	int guess;
	bool failure;

	do
	{
		failure = false;

		cout << "Please enter your guess (number of guesses left: " << numberOfTries << "): ";
		cin >> guess;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Input error! Please try again." << endl;
			failure = true;
		}

	} while (failure);

	return guess;
}

void DisplayResult(int secretNumber, int numberOfTries)
{
	if (numberOfTries > 0)
	{
		cout << "You got it! It was: " << secretNumber << endl;
	}
	else
	{
		cout << "You didn't get it! It was: " << secretNumber << endl;
	}
}
