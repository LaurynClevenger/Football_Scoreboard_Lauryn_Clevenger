/*  Lauryn Clevenger
    COSC 1437 Programming Fundamentals II
    11/18/2020
    Dr Tyson Mcmillan
*/
#include <iostream>
#include <string>
using namespace std;

class Team
{
  private:
    string name;
    string coach_Name;
    string home_City;
    bool homeStatus;
    int score;
    int timeout_Count;
  public:
    Team()  // default constructure
    {
      score = 0;
      homeStatus = false; // Home Team = true / Visitor = false
      name = "DefaultTeamName";
    }
    void setScore(int s)  { score = s; }
    void setHomeStatus(bool hs) { homeStatus = hs; }
    void setName(string n)  { name = n; }
    int getScore() const { return score; }
    bool getHomeStatus() const { return homeStatus; }
    string getName() const { return name; }  
};

class Scoreboard
{
  private:
    int down;
    int quarter;
    int toGo;
    Team home;
    Team visitor; 
  public:
    Scoreboard()
    {
      down = 0;
      quarter = 0;

    }
    void setDown(int d) { down = d; }
    void setQuarter(int q) { quarter = q; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getDown() const { return down; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string score = "";
      string reset = "";
      cout << home.getName() << "\t\t" << visitor.getName() << endl;
      cout << score << home.getScore() << reset << "\t\t" << visitor.getScore() << endl;
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo;
  string newName = "";
  string userChoice = "";
  int newScore = 0;

  // Set home Team
  tOne.setHomeStatus(true);   // tOne is Home Team newScore

  s.setHome(tOne);
  s.setVisitor(tTwo);

  /***********Dr_T Edit***********/
  s.showScoreboard(); //use this to print the scoreboard to the screen 

  do
  {
      cout << "A = Update Home Team Name" << endl;
      cout << "B = Update Home Team Score" << endl;
      cout << "C = Show Scoreboard" << endl;
      cout << "E = Exit" << endl;
      cout << ">";
      cin >> userChoice;

      
      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne  
        // Seem to have infinite loop here      
      }
      else if (userChoice == "C" || userChoice == "c")
      {
        cout << "Now this is the current Scoreboard!" << endl;
        s.showScoreboard();
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
  
  }while(userChoice != "E" && userChoice != "e");
  //Dr_T Use an if-else block here within do-while loop to keep looping the menu with user options. See my example from the video and code 
  return 0;
}
// what is downs technicslly and to gos?  
//Dr_T note Teams get 4 downs per offensive round to get to 10 yards, to go
// is how many years the offensive team needs to get to 10 yards 