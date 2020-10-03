#include "Player.h"

Player::Player()
{
  m_ships_remaining = 0;
  m_player_number = "";
  m_bs_remaining = 100;
  m_cs_remaining = 100;
  m_fs_remaining = 100;
  m_ss_remaining = 100;
  m_ds_remaining = 100;
}

Player::~Player()
{

}

vector<string> Player::getCoords()
{
  getCoordinatesFromBoard();
  return m_playerCoords;
}

bool Player::checkValidPlacement(std::string ship_coord1, std::string ship_coord2, int ship_size)
{
	if (ship_coord1.length() + ship_coord2.length() != 4) //is it exactly 5 characters long?
  {
		return false;
	}

  //breaks down the coordinates into their individual parts
	char letter1 = ship_coord1[0];
	int number1 = ship_coord1[1] - '0';
  char letter2 = ship_coord2[0];
  int number2 = ship_coord2[1] - '0';

  if ((number1 < 1) || (number1 > 9) || (number2 < 1) || (number2 > 9)) //makes sure the numbers are between 1-9
  {
    return false;
  }

  if ((letter1 < 'A') || (letter1 > 'I') || (letter2 < 'A') || (letter2 > 'I')) //are the letters within the correct range?
  {
    return false;
  }

  //checks if the user has previously placed a ship at this location
  if ((m_ship_board.getpointat(ship_coord1) == 'B') || m_ship_board.getpointat(ship_coord2) == 'B')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'C') || m_ship_board.getpointat(ship_coord2) == 'C')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'S') || m_ship_board.getpointat(ship_coord2) == 'S')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'D') || m_ship_board.getpointat(ship_coord2) == 'D')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'F') || m_ship_board.getpointat(ship_coord2) == 'F')
  {
    return false;
  }

  //converts the letters in their integer ASCII form
  int letter1_int = letter1 - '0';
  int letter2_int = letter2 - '0';

  //these if statements are necessary so the user can write coordinates forwards or backwards. Example: both A1 A5 and A5 A1 are valid.
  if ((number2 > number1))
  {
    if ((number2-number1+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
    {
      return true;
    }
    else if ((letter2_int-letter1_int+1 == ship_size) && (number1-number2 == 0)) //else checks if the ship is placed horizontally the right # of spaces
    {
      return true;
    }
    else //the ship must be placed diagonal, which isn't valid
    {
      return false;
    }
  }
  else if (number2 < number1)
  {
    if ((number1-number2+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
    {
      return true;
    }
    else if ((letter1_int-letter2_int+1 == ship_size) && (number1-number2 == 0)) //else checks if the ship is placed horizontally the right # of spaces
    {
      return true;
    }
    else //the ship must be placed diagonal, which isn't valid
    {
      return false;
    }
  }
  else if (letter1_int < letter2_int)
  {
    if ((number1-number2+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
    {
      return true;
    }
    else if ((letter2_int-letter1_int+1 == ship_size) && (number1-number2 == 0)) //else checks if the ship is placed horizontally the right # of spaces
    {
      return true;
    }
    else //the ship must be placed diagonal, which isn't valid
    {
      return false;
    }
  }
  else
  {
    if ((number1-number2+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
    {
      return true;
    }
    else if ((letter1_int-letter2_int+1 == ship_size) && (number1-number2 == 0)) //else checks if the ship is placed horizontally the right # of spaces
    {
      return true;
    }
    else //the ship must be placed diagonal, which isn't valid
    {
      return false;
    }
  }
}

void Player::markBoard(Ship ship)
{
  bool vertical = false;
  std::string coord1 = ship.getCoord1();
  std::string coord2 = ship.getCoord2();

  //breaks down the coordinates into their individual parts
  char letter1 = coord1[0];
  int number1_string = coord1[1];
	int number1 = coord1[1] - '0';
  char letter2 = coord2[0];
  int number2 = coord2[1] - '0';

  //if the letter remains the same for both coordinates that must mean it is a vertical ship
  if (letter1 == letter2)
  {
    vertical = true;
  }

  if (vertical) //the ship must be vertical
  {
    if (number1 < number2)
    {
      for (int i = 0; i < ship.getLength(); i++)
      {
        //places the correct ship type
        if (ship.getName() == "battleship")
        {
          m_ship_board.changepointat(coord1, 'B');
        }
        else if (ship.getName() == "cruiser")
        {
          m_ship_board.changepointat(coord1, 'C');
        }
        else if (ship.getName() == "submarine")
        {
          m_ship_board.changepointat(coord1, 'S');
        }
        else if (ship.getName() == "destroyer")
        {
          m_ship_board.changepointat(coord1, 'D');
        }
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord1, 'F');
        }
        coord1.pop_back();                          //if coord1 before equaled A5, it is now just A
        number1++;                                  //the number is now increased by one, so using the last comment's example, 5+1=6
        std::string num = std::to_string(number1);  //the number is now converted to a string, so "6"
        coord1 += num;                              //coord1 is now A6, as A is concatenated with 6
      }
    }
    else
    {
      for (int i = 0; i < ship.getLength(); i++)
      {
        if (ship.getName() == "battleship")
        {
          m_ship_board.changepointat(coord2, 'B');
        }
        else if (ship.getName() == "cruiser")
        {
          m_ship_board.changepointat(coord2, 'C');
        }
        else if (ship.getName() == "submarine")
        {
          m_ship_board.changepointat(coord2, 'S');
        }
        else if (ship.getName() == "destroyer")
        {
          m_ship_board.changepointat(coord2, 'D');
        }
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord2, 'F');
        }
        coord2.pop_back();                          //same as the previous code but just with the letters
        number2++;
        std::string num = std::to_string(number2);
        coord2 += num;
      }
    }
  }
  else //the ship must be horizontal
  {
    if (letter1 < letter2)
    {
      for (int i = 0; i < ship.getLength(); i++)
      {
        if (ship.getName() == "battleship")
        {
          m_ship_board.changepointat(coord1, 'B');
        }
        else if (ship.getName() == "cruiser")
        {
          m_ship_board.changepointat(coord1, 'C');
        }
        else if (ship.getName() == "submarine")
        {
          m_ship_board.changepointat(coord1, 'S');
        }
        else if (ship.getName() == "destroyer")
        {
          m_ship_board.changepointat(coord1, 'D');
        }
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord1, 'F');
        }
        letter1++;                      //same code as above for the letters
        coord1 = letter1;
        coord1 += number1_string;
      }
    }
    else
    {
      for (int i = 0; i < ship.getLength(); i++)
      {
        if (ship.getName() == "battleship")
        {
          m_ship_board.changepointat(coord2, 'B');
        }
        else if (ship.getName() == "cruiser")
        {
          m_ship_board.changepointat(coord2, 'C');
        }
        else if (ship.getName() == "submarine")
        {
          m_ship_board.changepointat(coord2, 'S');
        }
        else if (ship.getName() == "destroyer")
        {
          m_ship_board.changepointat(coord2, 'D');
        }
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord2, 'F');
        }
        letter2++;                  //same
        coord2 = letter2;
        coord2 += number1_string;
      }
    }
  }
}

void Player::replaceShip(int number_ships, int player_number)
{
  std::string ship_coord1;
  std::string ship_coord2;

  if (player_number == 1)
  {
    m_player_number = "ONE";
  }
  else
  {
    m_player_number = "TWO";
  }

  //Replace ships
  char replacemyship = ' ';
  int choose_size = 0;

  Replaceship:
  std::cout << '\n';
  m_ship_board.print();
  std::cout <<"==Here is your SHIP POSITION layout==\n";
  std::cout << "Do you want to Replace your ship? (Enter Y to replace, enter other to continue the game): ";
  std::cin >> replacemyship;

  if (replacemyship == 'Y')
  {
      Correctsize:
      std::cout << "Which SIZE you want to replace (Enter(1 - 5)): ";
      std::cin >> choose_size;

      if(choose_size <= number_ships && choose_size == 5)
      {
        for(int i = 0; i < 9; i++)
        {
          for(int j = 0; j < 9; j++)
          {
            if(m_ship_board.getValue(i+1, j+1) == 'B')
            {
                m_ship_board.getValue(i+1, j+1);
                m_ship_board.setValue(i+1, j+1, '~');
            }
          }
        }
        std::cout << "Where would you like to place your SIZE FIVE battleship?: ";
        std::cin >> ship_coord1;
        std::cin >> ship_coord2;
        while (!checkValidPlacement(ship_coord1, ship_coord2, 5))
        {
          std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
          std::cin >> ship_coord1;
          std::cin >> ship_coord2;
        }
        Ship battleship(5, ship_coord1, ship_coord2, "battleship");
        m_bs_remaining = 5;
        markBoard(battleship);

        goto Replaceship;
      }

      else if(choose_size <= number_ships && choose_size == 4)
      {
        for(int i = 0; i < 9; i++)
        {
          for(int j = 0; j < 9; j++)
          {
            if(m_ship_board.getValue(i+1, j+1) == 'C')
            {
                m_ship_board.getValue(i+1, j+1);
                m_ship_board.setValue(i+1, j+1, '~');
            }
          }
        }
        std::cout << "Where would you like to place your SIZE FOUR cruiser?: ";
        std::cin >> ship_coord1;
        std::cin >> ship_coord2;
        while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
        {
          std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
          std::cin >> ship_coord1;
          std::cin >> ship_coord2;
        }
        Ship cruiser(4, ship_coord1, ship_coord2, "cruiser");
        m_cs_remaining = 4;
        markBoard(cruiser);

        goto Replaceship;
      }

      else if(choose_size <= number_ships && choose_size == 3)
      {
        for(int i = 0; i < 9; i++)
        {
          for(int j = 0; j < 9; j++)
          {
            if(m_ship_board.getValue(i+1, j+1) == 'S')
            {
                m_ship_board.getValue(i+1, j+1);
                m_ship_board.setValue(i+1, j+1, '~');
            }
          }
        }
        std::cout << "Where would you like to place your SIZE THREE submarine?: ";
        std::cin >> ship_coord1;
        std::cin >> ship_coord2;
        while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
        {
          std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
          std::cin >> ship_coord1;
          std::cin >> ship_coord2;
        }
        Ship submarine(3, ship_coord1, ship_coord2, "submarine");
        m_ss_remaining = 3;
        markBoard(submarine);

        goto Replaceship;
      }

      else if(choose_size <= number_ships && choose_size == 2)
      {
        for(int i = 0; i < 9; i++)
        {
          for(int j = 0; j < 9; j++)
          {
            if(m_ship_board.getValue(i+1, j+1) == 'D')
            {
                m_ship_board.getValue(i+1, j+1);
                m_ship_board.setValue(i+1, j+1, '~');
            }
          }
        }
        std::cout << "Where would you like to place your SIZE TWO destroyer?: ";
        std::cin >> ship_coord1;
        std::cin >> ship_coord2;
        while (!checkValidPlacement(ship_coord1, ship_coord2, 2))
        {
          std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
          std::cin >> ship_coord1;
          std::cin >> ship_coord2;
        }
        Ship destroyer(2, ship_coord1, ship_coord2, "destroyer");
        m_ds_remaining = 2;
        markBoard(destroyer);

        goto Replaceship;
      }

      else if(choose_size <= number_ships && choose_size == 1)
      {
        for(int i = 0; i < 9; i++)
        {
          for(int j = 0; j < 9; j++)
          {
            if(m_ship_board.getValue(i+1, j+1) == 'F')
            {
                m_ship_board.getValue(i+1, j+1);
                m_ship_board.setValue(i+1, j+1, '~');
            }
          }
        }
        std::cout << "Where would you like to place your SIZE ONE frigate?: ";
        std::cin >> ship_coord1;
    		std::cin.clear();
    		std::cin.ignore(10000, '\n'); //this has to be cleared and ignored in case the user types two coordinates instead of one, so it flushes the stream
        ship_coord2 = ship_coord1;    //so that checkValidPlacement works correctly
        while (!checkValidPlacement(ship_coord1, ship_coord2, 1)) //runs until a valid placement is made
        {
          std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
          std::cin >> ship_coord1;
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          ship_coord2 = ship_coord1;
        }
        Ship frigate(1, ship_coord1, ship_coord2, "frigate"); //creates the correct ship
        m_fs_remaining = 1; //updates how many parts of it remain
        markBoard(frigate); //marks it on the map

        goto Replaceship;
      }

      else
      {
        std::cout << "Invalid Ship Size! Please enter number NO MORE than "<<number_ships<<'\n';
        goto Correctsize;
      }
  }
}

void Player::placeShips(int number_ships, int player_number)
{
  std::string ship_coord1;
  std::string ship_coord2;

  if (player_number == 1)
  {
    m_player_number = "ONE";
  }
  else
  {
    m_player_number = "TWO";
  }

  //prints out the board the user references to place their ships and the instructions
  m_ship_board.print();
  std::cout << "\nINSTRUCTIONS\n";
  std::cout << "To place a ship, type its starting coordinate as one word, hit space, and then type its last coordinate as one word.\n";
  std::cout << "The letter must be capitalized.\n";
  std::cout << "For example: A4 B4 is valid, a4 b4 is invalid, A 4 B 4 is invalid, and (A,4) (B,4) is invalid.\n";
  std::cout << "Remember, ships can only be placed vertically and horizontally, NOT diagonally.\n";
  std::cout << "-------------------------------------------------------------------------------\n";
  std::cout << "PLAYER " << m_player_number << ", ";

  //--------------------------------------------------------------------------------------------------------
  //Five if statements depending on how many ships the players are playing with. This determines how many ships the
  //users will be placing and what sizes they will be.


  if (number_ships == 1)
  {
    //ReplaceNum1size1:
    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n'); //this has to be cleared and ignored in case the user types two coordinates instead of one, so it flushes the stream
    ship_coord2 = ship_coord1;    //so that checkValidPlacement works correctly
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1)) //runs until a valid placement is made
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      ship_coord2 = ship_coord1;
    }
    Ship frigate(1, ship_coord1, ship_coord2, "frigate"); //creates the correct ship
    m_fs_remaining = 1; //updates how many parts of it remain
    markBoard(frigate); //marks it on the map
    //--------------------------------------------------------------------------------------------------------

  }
  //--------------------------------------------------------------------------------------------------------
  //the rest of the if statements are the same as above, just with more ships
  else if (number_ships == 2)
  {
    //ReplaceNum2size2:
    std::cout << "Where would you like to place your SIZE TWO destroyer?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 2))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship destroyer(2, ship_coord1, ship_coord2, "destroyer");
    m_ds_remaining = 2;
    markBoard(destroyer);

    //ReplaceNum2size1:
    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
    ship_coord2 = ship_coord1;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      ship_coord2 = ship_coord1;
    }
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
    //--------------------------------------------------------------------------------------------------------
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 3)
  {
    //ReplaceNum3size3:
    std::cout << "Where would you like to place your SIZE THREE submarine?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship submarine(3, ship_coord1, ship_coord2, "submarine");
    m_ss_remaining = 3;
    markBoard(submarine);

    //ReplaceNum3size2:
    std::cout << "Where would you like to place your SIZE TWO destroyer?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 2))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship destroyer(2, ship_coord1, ship_coord2, "destroyer");
    m_ds_remaining = 2;
    markBoard(destroyer);

    //ReplaceNum3size1:
    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
    ship_coord2 = ship_coord1;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      ship_coord2 = ship_coord1;
    }
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
    //--------------------------------------------------------------------------------------------------------
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 4)
  {
    //ReplaceNum4size4:
    std::cout << "Where would you like to place your SIZE FOUR cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship cruiser(4, ship_coord1, ship_coord2, "cruiser");
    m_cs_remaining = 4;
    markBoard(cruiser);

    //ReplaceNum4size3:
    std::cout << "Where would you like to place your SIZE THREE submarine?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship submarine(3, ship_coord1, ship_coord2, "submarine");
    m_ss_remaining = 3;
    markBoard(submarine);

    //ReplaceNum4size2:
    std::cout << "Where would you like to place your SIZE TWO destroyer?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 2))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship destroyer(2, ship_coord1, ship_coord2, "destroyer");
    m_ds_remaining = 2;
    markBoard(destroyer);

    //ReplaceNum4size1:
    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
    ship_coord2 = ship_coord1;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      ship_coord2 = ship_coord1;
    }
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
    //--------------------------------------------------------------------------------------------------------
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 5)
  {
    //ReplaceNum5size5:
    std::cout << "Where would you like to place your SIZE FIVE battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 5))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship battleship(5, ship_coord1, ship_coord2, "battleship");
    m_bs_remaining = 5;
    markBoard(battleship);

    //ReplaceNum5size4:
    std::cout << "Where would you like to place your SIZE FOUR cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship cruiser(4, ship_coord1, ship_coord2, "cruiser");
    m_cs_remaining = 4;
    markBoard(cruiser);

    //ReplaceNum5size3:
    std::cout << "Where would you like to place your SIZE THREE submarine?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship submarine(3, ship_coord1, ship_coord2, "submarine");
    m_ss_remaining = 3;
    markBoard(submarine);

    //ReplaceNum5size2:
    std::cout << "Where would you like to place your SIZE TWO destroyer?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 2))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship destroyer(2, ship_coord1, ship_coord2, "destroyer");
    m_ds_remaining = 2;
    markBoard(destroyer);

    //ReplaceNum5size1:
    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
    ship_coord2 = ship_coord1;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      ship_coord2 = ship_coord1;
    }
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
    //--------------------------------------------------------------------------------------------------------
  }
  //--------------------------------------------------------------------------------------------------------
  else
  {
    std::cout << "\nInvalid number of ships.\n";
    return;
  }
  m_ships_remaining = number_ships; //updates the ships remaining counter to however many ships the game is being played with
}

void Player::markShot(std::string shot, bool hit)
{
  if (hit)  //if the shot is a hit
  {
    m_shoot_board.changepointat(shot, 'X');
  }
  else      //if it is a miss
  {
    m_shoot_board.changepointat(shot, '*');
  }
}

void Player::markEnemyMiss(std::string shot)
{
  m_ship_board.changepointat(shot, '*');
}

void Player::printShootBoard()
{
  m_shoot_board.print();
}

void Player::printShipBoard()
{
  m_ship_board.print();
}

bool Player::uniqueShot(std::string shot)
{
  if (m_shoot_board.getpointat(shot) == '*') //if this coordinate has already been shot at and was a miss
  {
    return false;
  }
  else if (m_shoot_board.getpointat(shot) == 'X') //if already shot at and was a hit
  {
    return false;
  }
  return true;
}

bool Player::isHit(std::string shot)
{
  //if the player's ship was hit, it will enter the correct if statement depending on which type of ship was hit
  if (m_ship_board.getpointat(shot) == 'B')
  {
    m_ship_board.changepointat(shot, 'X'); //updates it from a B to show its been hit
    m_bs_remaining--;                      //lowers how many B's remain on the board. When this hits 0, you know the ship has been sunk.
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'C')
  {
    m_ship_board.changepointat(shot, 'X'); //same as above
    m_cs_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'F')
  {
    m_ship_board.changepointat(shot, 'X');
    m_fs_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'S')
  {
    m_ship_board.changepointat(shot, 'X');
    m_ss_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'D')
  {
    m_ship_board.changepointat(shot, 'X');
    m_ds_remaining--;
    return true;
  }
  return false;
}

bool Player::isSunk(std::string shot)
{
  //if there are no more parts of a certain ship left un-hit, then it will be sunk.
  if (m_bs_remaining == 0)
  {
    m_ships_remaining--; //decrements the ships remaining counter since a ship has been sunk
    return true;
  }
  else if (m_cs_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  else if (m_fs_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  else if (m_ss_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  else if (m_ds_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  return false;
}

int Player::shipsRemaining()
{
  return m_ships_remaining;
}

bool Player::hasSpecialShot()
{
	return(m_SpecialShot.inArsenal(0));
}

int Player::selectShot()
{
	std::string shotType;

	if(!hasSpecialShot())
	{
		shotType = "1";
	}
	else
	{
		//validate shotType input
		do
		{
			std::cout << "========================\n";
			std::cout << "1) Select SINGLE shot\n";
			std::cout << "2) Select SPECIAL shot\n";
			std::cout << "========================\n";
			std::cout << "Enter your choice: ";
			std::cin >> shotType;

			if(shotType != "1" && shotType != "2")
			{
				std::cout << "\nPlease enter 1 or 2.\n\n";
			}
		}while(shotType != "1" && shotType != "2");

		if(shotType == "2")
		{
			do
			{
				m_SpecialShot.menu();
				std::cout << "Enter your choice: ";
				std::cin >> shotType;

				if(shotType != "1" && shotType != "2" && shotType != "3" &&
					 shotType != "4" && shotType != "5" && shotType != "6")
				{
					std::cout << "\nPlease enter a number (1-6).\n";
				}
				else if(!m_SpecialShot.inArsenal(std::stoi(shotType)))
				{
					std::cout << "\nCaptain, we don't have that weapon!\n";
					shotType = "0";
				}
			}while(shotType != "1" && shotType != "2" && shotType != "3" &&
						 shotType != "4" && shotType != "5" && shotType != "6");
		}
	}
	return(std::stoi(shotType));
}

std::vector<std::string> Player::coordinateShot(int shotType)
{
	/*TODO: validate shotVector*/
	std::string shotTypeStr;
	std::string pivotCoord;
	char pivotDirection;
	std::vector<std::string> shotVector;
	std::string shot;

	switch(shotType)
	{
		case 1:
			shotTypeStr = "SINGLE";
			break;

		case 2:
			shotTypeStr = "DOUBLE";
			break;

		case 3:
			shotTypeStr = "TRIPLE";
			break;

		case 4:
			shotTypeStr = "QUADRUPLE";
			break;

		case 5:
			shotTypeStr = "QUINTUPLE";
			break;

		case 6:
			shotTypeStr = "SEXTUPLE";
			break;
	}

	if(shotType > 1 && shotType <= 6)
	{
		//validate pivotCoord
		do{
			std::cout << "Choose a pivot coordinate for that " << shotTypeStr << " shot (col row): ";
			std::cin >> pivotCoord;
			pivotCoord[0] = toupper(pivotCoord[0]);

			if(!validCoord(pivotCoord))
			{
				std::cout << "\nConnection to missiles lost... Please enter a valid input..\n";
				std::cout << "Valid inputs are A through I and 1 through 9, i.e. A2 A5\n\n";
			}
		}while(!validCoord(pivotCoord));

		//validate pivotDirection
		do{
			std::cout << "Up, Down, Left, or Right from pivot? (U, D, L, R): ";
			std::cin >> pivotDirection;
			pivotDirection = toupper(pivotDirection);
			if(pivotDirection != 'U' && pivotDirection != 'D' &&
				 pivotDirection != 'L' && pivotDirection != 'R')
			{
				std::cout << "Please enter U, D, L, or R.\n";
			}
		}while(pivotDirection != 'U' && pivotDirection != 'D' &&
					 pivotDirection != 'L' && pivotDirection != 'R');

		shotVector = getShotVector(pivotCoord, pivotDirection, shotType);
	}
	else
	{
		std::cout << "Coordinate to fire at: ";
		std::cin >> shot;
		shot[0] = toupper(shot[0]);
		shotVector.push_back(shot);
	}

	return shotVector;
}

std::vector<std::string> Player::getShotVector(std::string pivotCoord, char pivotDirection, int shotType)
{
	int row = pivotCoord[1] - '0';
	char col = pivotCoord[0];
	std::vector<std::string> coordVector;
	std::string coord;

	for(int i = shotType; i > 0; i--)
	{
		coord = col + std::to_string(row);
		switch(pivotDirection)
		{
			case 'U':
				row--;
				break;

			case 'D':
				row++;
				break;

			case 'L':
				col--;
				break;

			case 'R':
				col++;
				break;
		}
		coordVector.push_back(coord);
	}

	return coordVector;
}

std::string Player::getShipSunk()
{
  if (m_bs_remaining == 0)
  {
    return "battleship";
  }
  else if (m_cs_remaining == 0)
  {
    return "cruiser";
  }
  else if (m_ss_remaining == 0)
  {
    return "submarine";
  }
  else if (m_ds_remaining == 0)
  {
    return "destroyer";
  }
  else if (m_fs_remaining == 0)
  {
    return "frigate";
  }

  return "noShip";
}

void Player::resetShipSunk()
{
	//if there are no more parts of a certain ship left un-hit, then it will be sunk.
  if (m_bs_remaining == 0)
  {
    m_bs_remaining = 100;
  }
  else if (m_cs_remaining == 0)
  {
    m_cs_remaining = 100;
  }
  else if (m_ss_remaining == 0)
  {
    m_ss_remaining = 100;
  }
  else if (m_ds_remaining == 0)
  {
    m_ds_remaining = 100;
  }
  else if (m_fs_remaining == 0)
  {
    m_fs_remaining = 100;
  }
}

void Player::acquireSpecialShot(std::string shipSunk)
{
	int shotType = 0;

	if(shipSunk == "battleship")
	{
		shotType = 6;
	}
	else if(shipSunk == "cruiser")
	{
		shotType = 5;
	}
	else if(shipSunk == "submarine")
	{
		shotType = 4;
	}
	else if(shipSunk == "destroyer")
	{
		shotType = 3;
	}
	else if(shipSunk == "frigate")
	{
		shotType = 2;
	}

	m_SpecialShot.acquire(shotType);
}

void Player::depleteSpecialShot(int shotType)
{
	m_SpecialShot.deplete(shotType);
}

bool Player::validCoord(std::string coord)
{
	bool valid;
	char letter = coord[0];
	char number = coord[1];

	if (coord.length() != 2) //Is it exactly two letter long?
	{
		valid = false;
	}
	else if (( number >= '1' ) && ( number <= '9' ))
	{
		//compares ascii values
		if ( (letter >= 'A' ) && ( letter <= 'I' )) //Is the alpha within range?
		{
			valid = true; //Then the input is good!
		}
		else
		{
			valid = false;
		}
	}
	else
	{
		valid = false;
	}

	return valid;
}

bool Player::validateShot(std::vector<std::string> shotVector)
{
	unsigned int numDuplicates = 0;
	std::string shot;

	if(shotVector.size() == 1) //single shot selected
	{
		shot = shotVector[0];
		if(!validCoord(shot)) //Is the user input good?
		{
			std::cout << "\nConnection to missiles lost... Please enter a valid input..\n";
			std::cout << "Valid inputs are A through I and 1 through 9, i.e. A2 A5\n\n";
			return false;
		}
		else
		{
			if(uniqueShot(shot)) //Is the shot unique?
			{
				return true;
			}
			else
			{
				std::cout << "\nCaptain! We have already shot at that location!\n\n";
				return false;
			}
		}
	}
	else //special shot selected
	{
		for(auto& shot: shotVector)
		{
			if(!validCoord(shot))
			{
				std::cout << "\nYour special shot is out-of-range!\n\n";
				return false;
			}
			else
			{
				if(!uniqueShot(shot))
				{
					numDuplicates++;
				}
			}
		}

		if(numDuplicates == shotVector.size())
		{
			std::cout << "\nCaptain! That area is only filled with debris!\n";
			std::cout << "Try again!\n\n";
			return false;
		}
	}

	return true;
}

vector<string> Player::getCoordinatesFromBoard() // Get coordinates from player class
{
  char** board = m_ship_board.getBattleBoard();
  for(int i=1; i<10; i++)
  {
    for(int j=1; j<10; j++)
    {
      if(board[j][i] == 'B') // 5 coords
      {
        char l = static_cast<char>(i+64);
        string number = to_string(j);
        string coord = l + number;
        m_playerCoords.push_back(coord);
      }
      if(board[j][i] == 'C') // 4 coords
      {
        char l = static_cast<char>(i + 64);
        string number = to_string(j);
        string coord = l + number;
        m_playerCoords.push_back(coord);
      }
      if(board[j][i] == 'S') // 3 coords
      {
        char l = static_cast<char>(i + 64);
        string number = to_string(j);
        string coord = l + number;
        m_playerCoords.push_back(coord);
      }
      if(board[j][i] == 'D') // 2 coords
      {
        char l = static_cast<char>(i + 64);
        string number = to_string(j);
        string coord = l + number;
        m_playerCoords.push_back(coord);
      }
      if(board[j][i] == 'F') // 1 coord
      {
        char l = static_cast<char>(i + 64);
        string number = to_string(j);
        string coord = l + number;
        m_playerCoords.push_back(coord);
      }
    }
  }
  return m_playerCoords;
}
