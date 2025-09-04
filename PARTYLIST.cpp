#include <iostream>
#include <string>    // For string manipulation
#include <cctype>    // For character handling
#include <limits>    // For input validation
#include <algorithm> // For max function

using namespace std;

// Global vote count
int Salig_Partylist = 100;
int Olape_Partylist = 100;
int Mamugay_Partylist = 100;

// Function prototypes
void votersVerification();
void menu();
void Vote();
void Partylist_Winner();
void tieBreaker();
void quit();

// Display verified message
void verifiedMessage()
{
  cout << "\n---------------------------------------------" << endl;
  cout << "  âœ… Voter's name and ID number verified!  " << endl;
  cout << "  âœ… You may now proceed to vote.           " << endl;
  cout << "---------------------------------------------" << endl;
}

// Voter verification process
void votersVerification()
{
  string votersName;
  int votersIdnumber;

  while (true)
  {
    cout << "\nEnter Voter's Name: ";
    getline(cin, votersName);
    cout << "Enter Voter's ID Number: ";

    if (!(cin >> votersIdnumber))
    {
      cout << "âŒ Invalid input. Please enter a valid ID number.\n"
           << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    cin.ignore(); // Clear newline from buffer

    // Convert name to lowercase
    string votersNameLower = votersName;
    for (char &c : votersNameLower)
      c = tolower(c);

    // Predefined valid voters
    if ((votersNameLower == "ronald salig" && votersIdnumber == 123456) ||
        (votersNameLower == "harriet sarigumba" && votersIdnumber == 234567) ||
        (votersNameLower == "kent olape" && votersIdnumber == 345678) ||
        (votersNameLower == "carm walog" && votersIdnumber == 456789) ||
        (votersNameLower == "rejan mamugay" && votersIdnumber == 567890))
    {
      cout << "\nWelcome, " << votersName << "!" << endl;
      cout << "Voter's Name      : " << votersName << endl;
      cout << "Voter's ID Number : " << votersIdnumber << endl;
      verifiedMessage();
      break;
    }
    else
    {
      cout << "âŒ Invalid voter name or ID. Please try again.\n"
           << endl;
    }
  }
}

// Display the menu
void menu()
{
  while (true)
  {
    int decision;
    cout << "\n===============================";
    cout << "\n           MENU               ";
    cout << "\n===============================";
    cout << "\n  1: User Data (Restart)";
    cout << "\n  2: Vote";
    cout << "\n  3: View Partylist Standing";
    cout << "\n  4: Quit the Program";
    cout << "\n===============================";
    cout << "\nOption: ";

    if (!(cin >> decision))
    {
      cout << "âŒ Invalid input! Enter a number between 1-4.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (decision)
    {
    case 1:
      Salig_Partylist = 100;
      Olape_Partylist = 100;
      Mamugay_Partylist = 100;

      cout << "\nðŸ”„ Restarting voter verification...\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      votersVerification();
      menu();
      break;
    case 2:
      Vote();
      break;
    case 3:
      Partylist_Winner();
      break;
    case 4:
      quit();
      return;
    default:
      cout << "âŒ Invalid choice. Try again!\n";
    }
  }
}

// Voting process
void Vote()
{
  int vote_val;
  while (true)
  {
    cout << "\n=====================================" << endl;
    cout << "       ðŸ—³ï¸ PLEASE VOTE WISELY!        " << endl;
    cout << "=====================================" << endl;
    cout << "  1ï¸âƒ£  SALIG PARTYLIST               " << endl;
    cout << "  2ï¸âƒ£  OLAPE PARTYLIST               " << endl;
    cout << "  3ï¸âƒ£  MAMUGAY PARTYLIST             " << endl;
    cout << "=====================================" << endl;
    cout << "Enter your vote: ";

    if (!(cin >> vote_val))
    {
      cout << "âŒ Invalid input! Enter 1, 2, or 3.\n"
           << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (vote_val)
    {
    case 1:
      Salig_Partylist++;
      cout << "âœ” You voted for SALIG PARTYLIST!" << endl;
      break;
    case 2:
      Olape_Partylist++;
      cout << "âœ” You voted for OLAPE PARTYLIST!" << endl;
      break;
    case 3:
      Mamugay_Partylist++;
      cout << "âœ” You voted for MAMUGAY PARTYLIST!" << endl;
      break;
    default:
      cout << "âŒ Invalid vote! Try again.\n"
           << endl;
      continue;
    }
    break;
  }
}

// Display the winner
void Partylist_Winner()
{
  cout << "\n===================================" << endl;
  cout << "        ðŸŽ‰ PARTYLIST RESULTS ðŸŽ‰     " << endl;
  cout << "===================================" << endl;
  cout << "  SALIG PARTYLIST   : " << Salig_Partylist << " votes" << endl;
  cout << "  OLAPE PARTYLIST   : " << Olape_Partylist << " votes" << endl;
  cout << "  MAMUGAY PARTYLIST : " << Mamugay_Partylist << " votes" << endl;
  cout << "===================================" << endl;

  int maxVotes = max({Salig_Partylist, Olape_Partylist, Mamugay_Partylist});
  bool saligWins = (Salig_Partylist == maxVotes);
  bool olapeWins = (Olape_Partylist == maxVotes);
  bool mamugayWins = (Mamugay_Partylist == maxVotes);
  int tieCount = saligWins + olapeWins + mamugayWins;

  if (tieCount == 1) // Single winner
  {
    cout << "ðŸŽŠ CONGRATULATIONS TO ";
    if (saligWins)
      cout << "SALIG PARTYLIST! ðŸŽŠ" << endl;
    if (olapeWins)
      cout << "OLAPE PARTYLIST! ðŸŽŠ" << endl;
    if (mamugayWins)
      cout << "MAMUGAY PARTYLIST! ðŸŽŠ" << endl;
    cout << "===================================" << endl;
  }
  else // Tie detected
  {
    cout << "âš ï¸  IT'S A TIE BETWEEN: ";
    if (saligWins)
      cout << "SALIG ";
    if (olapeWins)
      cout << "OLAPE ";
    if (mamugayWins)
      cout << "MAMUGAY ";
    cout << "PARTYLIST(S)!" << endl;
    cout << "===================================" << endl;
    tieBreaker(); // Conduct a tie-breaking round
  }
}

// Conduct a tie-breaker vote
void tieBreaker()
{
  cout << "\nâš ï¸  TIE-BREAKER ROUND! ONE MORE VOTE WILL BE HELD!" << endl;
  Vote(); // Restart the voting process
}

// Quit the program
void quit()
{
  cout << "\n===================================" << endl;
  cout << "  ðŸš€ THANK YOU FOR USING THE PROGRAM!  " << endl;
  cout << "===================================" << endl;
}

// Main function
int main()
{
  votersVerification(); // Start voter verification
  menu();               // Run menu in a loop
  return 0;
}

// End of program