#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Abstract Person class
class Person {
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayInfo() = 0; // Pure virtual function
    virtual ~Person() {}
};

// Derived Player class
class Player : public Person {
private:
    int playerID;
    string role;
    int matches;
    int runs;
    int wickets;

public:
    Player() : playerID(0), role(""), matches(0), runs(0), wickets(0) {}
    
    void addPlayer() {
        cout << "Enter Player ID: ";
        cin >> playerID;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Role (Batsman/Bowler/All-rounder): ";
        cin >> role;
        cout << "Enter Matches Played: ";
        cin >> matches;
        cout << "Enter Total Runs: ";
        cin >> runs;
        cout << "Enter Total Wickets: ";
        cin >> wickets;
    }

    void displayInfo() override {
        cout << "ID: " << playerID << " | Name: " << name 
             << " | Age: " << age << " | Role: " << role 
             << " | Matches: " << matches << " | Runs: " << runs 
             << " | Wickets: " << wickets << endl;
    }

    void saveToCSV(ofstream& file) {
        file << playerID << "," << name << "," << age << "," 
             << role << "," << matches << "," << runs << "," 
             << wickets << "\n";
    }

    void loadFromCSV(istringstream& iss) {
        string token;
        getline(iss, token, ',');
        playerID = stoi(token);
        getline(iss, name, ',');
        getline(iss, token, ',');
        age = stoi(token);
        getline(iss, role, ',');
        getline(iss, token, ',');
        matches = stoi(token);
        getline(iss, token, ',');
        runs = stoi(token);
        getline(iss, token);
        wickets = stoi(token);
    }

    int getPlayerID() const { return playerID; }
    string getName() const { return name; }
};

// Team class
class Team {
private:
    int teamID;
    string teamName;
    string country;
    Player players[15];
    int playerCount;

public:
    Team() : teamID(0), teamName(""), country(""), playerCount(0) {}
    int getPlayerCount() { return playerCount;}

    
    void addTeam() {
        cout << "Enter Team ID: ";
        cin >> teamID;
        cin.ignore();

        cout << "Enter Team Name: ";
        getline(cin, teamName);

        cin.ignore();
        cout << "Enter Country: ";
        getline(cin, country);
    }

    void addPlayerToTeam(const Player& p) {
        if (playerCount < 15) {
            players[playerCount++] = p;
        } else {
            cout << "Team is full!" << endl;
        }
    }

    void displayTeam() {
        cout << "\nTeam ID: " << teamID << " | Name: " << teamName 
             << " | Country: " << country << endl;
        cout << "Players (" << playerCount << "/15):\n";
        for (int i = 0; i < playerCount; i++) {
            cout << "  ";
            players[i].displayInfo();
        }
    }

    void saveToCSV(ofstream& file) {
        file << teamID << "," << teamName << "," << country << "," << playerCount << "\n";
        for (int i = 0; i < playerCount; i++) {
            players[i].saveToCSV(file);
        }
    }

    void loadFromCSV(ifstream& file) {
        string line;
        getline(file, line);
        istringstream iss(line);
        string token;
        
        getline(iss, token, ',');
        teamID = stoi(token);
        getline(iss, teamName, ',');
        getline(iss, country, ',');
        getline(iss, token);
        playerCount = stoi(token);

        for (int i = 0; i < playerCount; i++) {
            Player p;
            getline(file, line);
            istringstream playerStream(line);
            p.loadFromCSV(playerStream);
            players[i] = p;
        }
    }

    int getTeamID() const { return teamID; }
    string getTeamName() const { return teamName; }
};

// Venue class
class Venue {
private:
    string venueName;
    string country;
    int capacity;
    string pitchCondition;

public:
    Venue() : venueName(""), country(""), capacity(0), pitchCondition("") {}
    
    void addVenue() {
        cin.ignore();
        cout << "Enter Venue Name: ";
        getline(cin, venueName);

        cin.ignore();
        cout << "Enter Country: ";
        getline(cin, country);
        cout << "Enter Capacity: ";
        cin >> capacity;
        cout << "Enter Pitch Condition: ";
        cin >> pitchCondition;
    }

    void displayVenueInfo() {
        cout << "Venue: " << venueName << " | Country: " << country 
             << " | Capacity: " << capacity 
             << " | Pitch: " << pitchCondition << endl;
    }

    void saveToCSV(ofstream& file) {
        file << venueName << "," << country << "," 
             << capacity << "," << pitchCondition << "\n";
    }

    void loadFromCSV(istringstream& iss) {
        string token;
        getline(iss, venueName, ',');
        getline(iss, country, ',');
        getline(iss, token, ',');
        capacity = stoi(token);
        getline(iss, pitchCondition);
    }
};

// Match class
class Match {
private:
    int matchID;
    string team1Name;
    string team2Name;
    string date;
    string result;
    int oversLimit;
    string matchType; // "T20" or "ODI"
    Venue venue;

public:
    void playMatch() {
        cout << "\n--- Enter Match Details ---" << endl;
        cout << "Match ID: ";
        cin >> matchID;
        cin.ignore();
        cout << "Team 1 Name: ";
        getline(cin, team1Name);
        cout << "Team 2 Name: ";
        getline(cin, team2Name);
        cout << "Date (DD/MM/YYYY): ";
        getline(cin, date);
        cout << "Match Type (T20/ODI): ";
        getline(cin, matchType);
        cout << "Overs Limit: ";
        cin >> oversLimit;
        cin.ignore();
        
        cout << "Enter Winner (Team Name): ";
        getline(cin, result);
        
        cout << "\n--- Venue Details ---" << endl;
        venue.addVenue();
    }

    void displayMatch() {
        cout << "\nMatch ID: " << matchID << endl;
        cout << team1Name << " vs " << team2Name << endl;
        cout << "Date: " << date << " | Type: " << matchType 
             << " | Overs: " << oversLimit << endl;
        cout << "Winner: " << result << endl;
        cout << "Venue: ";
        venue.displayVenueInfo();
    }

    void saveToCSV(ofstream& file) {
        file << matchID << "," << team1Name << "," << team2Name << "," 
             << date << "," << result << "," << oversLimit << "," 
             << matchType << "\n";
        // Save venue details
        venue.saveToCSV(file);
    }

    void loadFromCSV(ifstream& file) {
        string line;
        getline(file, line);
        istringstream iss(line);
        string token;
        
        getline(iss, token, ',');
        matchID = stoi(token);
        getline(iss, team1Name, ',');
        getline(iss, team2Name, ',');
        getline(iss, date, ',');
        getline(iss, result, ',');
        getline(iss, token, ',');
        oversLimit = stoi(token);
        getline(iss, matchType);
        
        // Load venue details
        getline(file, line);
        istringstream venueStream(line);
        venue.loadFromCSV(venueStream);
    }

    string getWinner() const { return result; }
    string getTeam1() const { return team1Name; }
    string getTeam2() const { return team2Name; }
};

// Tournament class
class Tournament {
private:
    int tournamentID;
    string tournamentName;
    Match matches[20];
    int matchCount;
    string winner;

public:
    Tournament() : tournamentID(0), tournamentName(""), matchCount(0), winner("No Winner") {}
    
    void addTournament() {
        cout << "Enter Tournament ID: ";
        cin >> tournamentID;
        cout << "Enter Tournament Name: ";
        cin.ignore();
        getline(cin, tournamentName);
    }

    void addMatch(const Match& match) {
        if (matchCount < 20) {
            matches[matchCount++] = match;
            updateWinner(match.getWinner());
        } else {
            cout << "Maximum matches reached for this tournament!" << endl;
        }
    }

    void updateWinner(const string& team) {
        if (team != "No Result" && team != "") {
            winner = team; 
        }
    }

    void displayResults() {
        cout << "\nTournament: " << tournamentName 
             << " (ID: " << tournamentID << ")" << endl;
        cout << "Winner: " << winner << endl;
        cout << "\nMatches Played: " << matchCount << "/20" << endl;
        for (int i = 0; i < matchCount; i++) {
            matches[i].displayMatch();
        }
    }

    void saveToCSV(ofstream& file) {
        file << tournamentID << "," << tournamentName << "," 
             << matchCount << "," << winner << "\n";
        for (int i = 0; i < matchCount; i++) {
            matches[i].saveToCSV(file);
        }
    }

    void loadFromCSV(ifstream& file) {
        string line;
        getline(file, line);
        istringstream iss(line);
        string token;
        
        getline(iss, token, ',');
        tournamentID = stoi(token);
        getline(iss, tournamentName, ',');
        getline(iss, token, ',');
        matchCount = stoi(token);
        getline(iss, winner);

        for (int i = 0; i < matchCount; i++) {
            Match m;
            m.loadFromCSV(file);
            matches[i] = m;
        }
    }
};

// RankingSystem class
class RankingSystem {
private:
    string teamNames[30];
    int teamPoints[30];
    int teamCount;

public:
    RankingSystem() : teamCount(0) {
        for (int i = 0; i < 30; i++) {
            teamPoints[i] = 0;
        }
    }

    void updateFromMatch(const Match& match) {
        string winner = match.getWinner();
        string team1 = match.getTeam1();
        string team2 = match.getTeam2();

        // Add teams if they don't exist
        int team1Idx = -1, team2Idx = -1;
        
        for (int i = 0; i < teamCount; i++) {
            if (teamNames[i] == team1) team1Idx = i;
            if (teamNames[i] == team2) team2Idx = i;
        }

        if (team1Idx == -1 && teamCount < 30) {
            teamNames[teamCount] = team1;
            team1Idx = teamCount++;
        }
        
        if (team2Idx == -1 && teamCount < 30) {
            teamNames[teamCount] = team2;
            team2Idx = teamCount++;
        }

        // Update points (2 for win, 0 for loss)
        if (winner == team1) {
            teamPoints[team1Idx] += 2;
        } else if (winner == team2) {
            teamPoints[team2Idx] += 2;
        }
    }

    void displayRankings() {
        cout << "\n--- Global Team Rankings ---" << endl;
        for (int i = 0; i < teamCount; i++) {
            cout << teamNames[i] << " - " << teamPoints[i] << " points" << endl;
        }
    }

    void saveToCSV(ofstream& file) {
        file << teamCount << "\n";
        for (int i = 0; i < teamCount; i++) {
            file << teamNames[i] << "," << teamPoints[i] << "\n";
        }
    }

    void loadFromCSV(ifstream& file) {
        string line;
        getline(file, line);
        teamCount = stoi(line);
        
        for (int i = 0; i < teamCount; i++) {
            getline(file, line);
            size_t comma = line.find(',');
            teamNames[i] = line.substr(0, comma);
            teamPoints[i] = stoi(line.substr(comma + 1));
        }
    }
};

// Template class for lists
template <typename T>
class List {
private:
    T items[50];
    int count;

public:
    List() : count(0) {}
    
    void addItem(const T& item) {
        if (count < 50) {
            items[count++] = item;
        } else {
            cout << "List is full!" << endl;
        }
    }
    
    void displayAll() {
        for (int i = 0; i < count; i++) {
            items[i].displayInfo();
        }
    }
    
    int findItemByID(int id) {
        for (int i = 0; i < count; i++) {
            if (items[i].getPlayerID() == id) {
                return i;
            }
        }
        return -1;
    }
    
    int getCount() const { return count; }
    T getItem(int index) { 
        if (index >= 0 && index < count) {
            return items[index];
        }
        return T();
    }
};


// CricketBoard class
class CricketBoard {
private:
    int boardID;
    string boardName;
    string country;
    Team teams[10];
    int teamCount;

public:
    CricketBoard() : boardID(0), boardName(""), country(""), teamCount(0) {}

    int getTeamCount() const { return teamCount; }
    Team& getTeam(int index) { return teams[index]; }

    
    void addBoard() {
        cout << "Enter Board ID: ";
        cin >> boardID;
        cout << "Enter Board Name: ";
        cin.ignore();
        getline(cin, boardName);
        cout << "Enter Country: ";
        getline(cin, country);
    }
    
    void addTeamToBoard(const Team& team) {
        if (teamCount < 10) {
            teams[teamCount++] = team;
        } else {
            cout << "Maximum teams reached for this board!" << endl;
        }
    }
    
    void displayBoardBasic() {
    cout << "Board ID: " << boardID
         << " | Name: " << boardName
         << " | Country: " << country
         << " | Teams: " << teamCount << endl;
        }
    
        void displayTeamsBasic() {
    for (int i = 0; i < teamCount; i++) {
        cout << "Team ID: " << teams[i].getTeamID()
             << " | Name: " << teams[i].getTeamName()
             << " | Players: " << teams[i].getPlayerCount()
             << endl;
    }
    }

    void displayBoard() {
        cout << "\n--- Cricket Board ---" << endl;
        cout << "ID: " << boardID << " | Name: " << boardName 
             << " | Country: " << country << endl;
        cout << "\nTeams (" << teamCount << "/10):" << endl;
        for (int i = 0; i < teamCount; i++) {
            teams[i].displayTeam();
        }
    }
    string getBoardName() const {
    return boardName;
    }

    
    void saveToCSV(ofstream& file) {
        file << boardID << "," << boardName << "," << country << "," << teamCount << "\n";
        for (int i = 0; i < teamCount; i++) {
            teams[i].saveToCSV(file);
        }
    }
    
    void loadFromCSV(ifstream& file) {
        string line;
        getline(file, line);
        istringstream iss(line);
        string token;
        
        getline(iss, token, ',');
        boardID = stoi(token);
        getline(iss, boardName, ',');
        getline(iss, country, ',');
        getline(iss, token);
        teamCount = stoi(token);
        
        for (int i = 0; i < teamCount; i++) {
            Team t;
            t.loadFromCSV(file);
            teams[i] = t;
        }
    }
};

class Coach : public Person {
private:
    string country;
    int experienceYears;

public:
    Coach() : country(""), experienceYears(0) {}

    void addCoach() {
        cout << "Enter Coach Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Country: ";
        cin.ignore();
        getline(cin, country);

        cout << "Years of Experience: ";
        cin >> experienceYears;
    }

    void displayInfo() override {
        cout << "Coach: " << name
             << " | Age: " << age
             << " | Country: " << country
             << " | Experience: " << experienceYears
             << " years" << endl;
    }

    void saveToCSV() {
        ofstream file("coaches.csv", ios::app);
        if (!file.is_open()) return;

        file << name << ","
             << age << ","
             << country << ","
             << experienceYears << endl;

        file.close();
    }

    void loadFromCSV() {
        ifstream file("coaches.csv");
        if (!file.is_open()) return;

        string line, token;

        while (getline(file, line)) {
            istringstream iss(line);

            getline(iss, name, ',');
            getline(iss, token, ',');
            age = stoi(token);
            getline(iss, country, ',');
            getline(iss, token);
            experienceYears = stoi(token);
        }

        file.close();
    }
};
class Umpire : public Person {
private:
    int totalMatches;

public:
    Umpire() : totalMatches(0) {}

    void addUmpire() {
        cout << "Enter Umpire Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Total Matches Officiated: ";
        cin >> totalMatches;
    }

    void displayInfo() override {
        cout << "Umpire: " << name
             << " | Age: " << age
             << " | Matches: " << totalMatches << endl;
    }

    void saveToCSV() {
        ofstream file("umpires.csv", ios::app);
        if (!file.is_open()) return;

        file << name << ","
             << age << ","
             << totalMatches << endl;

        file.close();
    }

    void loadFromCSV() {
        ifstream file("umpires.csv");
        if (!file.is_open()) return;

        string line, token;

        while (getline(file, line)) {
            istringstream iss(line);

            getline(iss, name, ',');
            getline(iss, token, ',');
            age = stoi(token);
            getline(iss, token);
            totalMatches = stoi(token);
        }

        file.close();
    }
};


// ICC class
class ICC {
private:
    CricketBoard boards[5];
    int boardCount;
    Tournament tournaments[10];
    int tournamentCount;
    RankingSystem globalRankings;
    Player players[100];
    int playerCount;


public:
    ICC() : boardCount(0), tournamentCount(0), playerCount(0) {}

    void registerPlayer() {
    if (playerCount < 100) {
        players[playerCount].addPlayer();
        playerCount++;
        cout << "Player registered successfully!" << endl;
    }
}
    void addPlayerToTeam(int boardIndex, int teamID, int playerID) {
    for (int i = 0; i < playerCount; i++) {
        if (players[i].getPlayerID() == playerID) {
            for (int t = 0; t < boards[boardIndex].getTeamCount(); t++) {
                if (boards[boardIndex].getTeam(t).getTeamID() == teamID) {
                    boards[boardIndex].getTeam(t).addPlayerToTeam(players[i]);
                    cout << "Player added to team." << endl;
                    return;
                }
            }
        }
    }
    cout << "Player or Team not found." << endl;
}


    void registerBoard() {
        if (boardCount < 5) {
            CricketBoard board;
            board.addBoard();
            boards[boardCount++] = board;
            cout << "Board registered successfully!" << endl;
        } else {
            cout << "Maximum number of boards reached!" << endl;
        }
    }
    
    void organizeTournament() {
        if (tournamentCount < 10) {
            Tournament tournament;
            tournament.addTournament();
            tournaments[tournamentCount++] = tournament;
            cout << "Tournament created successfully!" << endl;
        } else {
            cout << "Maximum number of tournaments reached!" << endl;
        }
    }
    
    void displayGlobalRankings() {
        globalRankings.displayRankings();
    }
    
    void saveToCSV() {
        ofstream file("icc_data.csv");
        if (!file) {
            cout << "Error creating file!" << endl;
            return;
        }
        
        // Save boards
        file << boardCount << "\n";
        for (int i = 0; i < boardCount; i++) {
            boards[i].saveToCSV(file);
        }
        
        // Save tournaments
        file << tournamentCount << "\n";
        for (int i = 0; i < tournamentCount; i++) {
            tournaments[i].saveToCSV(file);
        }
        
        // Save rankings
        globalRankings.saveToCSV(file);
        
        file.close();
        cout << "Data saved to icc_data.csv" << endl;
    }
    
    void loadFromCSV() {
        ifstream file("icc_data.csv");
        if (!file) {
            cout << "No saved data found!" << endl;
            return;
        }
        
        string line;
        
        // Load boards
        getline(file, line);
        boardCount = stoi(line);
        for (int i = 0; i < boardCount; i++) {
            boards[i].loadFromCSV(file);
        }
        
        // Load tournaments
        getline(file, line);
        tournamentCount = stoi(line);
        for (int i = 0; i < tournamentCount; i++) {
            tournaments[i].loadFromCSV(file);
        }
        
        // Load rankings
        globalRankings.loadFromCSV(file);
        
        file.close();
        cout << "Data loaded from icc_data.csv" << endl;
    }
    
    // Helper functions to get references to stored items i.e. board,tournament etc.
    CricketBoard& getBoard(int index) {
        return boards[index];
    }
    
    Tournament& getTournament(int index) {
        return tournaments[index];
    }
    
    int getBoardCount() const { return boardCount; }
    int getTournamentCount() const { return tournamentCount; }
    
    void updateRankings(const Match& match) {
        globalRankings.updateFromMatch(match);
    }
};

// Flow: Board -> Team -> Player -> Tournament
int main() {
    ICC icc;
    int choice;

    Coach coaches[5];
    int coachCount = 0;

    Umpire umpires[5];
    int umpireCount = 0;

    // Load ICC-related data only
    icc.loadFromCSV();
    cout << "Data loaded from icc_data.csv" << endl;

    do {
        cout << "\n=== ICC Management System ===" << endl;
        cout << "1. Register Cricket Board" << endl;
        cout << "2. Add Team to Board" << endl;
        cout << "3. Register Player" << endl;
        cout << "4. Add Player to Team" << endl;
        cout << "5. Organize Tournament" << endl;
        cout << "6. Add Match to Tournament" << endl;
        cout << "7. View All Details" << endl;
        cout << "8. View Boards" << endl;
        cout << "9. View Teams of a Board" << endl;
        cout << "10. View Players of a Team" << endl;
        cout << "11. Display Global Rankings" << endl;
        cout << "12. Manage Officials (Coach / Umpire)" << endl;
        cout << "13. Save Data" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                icc.registerBoard();
                break;

            case 2: {
                if (icc.getBoardCount() == 0) {
                    cout << "No boards available." << endl;
                    break;
                }

                int index;
                cout << "Select Board (1-" << icc.getBoardCount() << "): ";
                cin >> index;

                if (index < 1 || index > icc.getBoardCount()) {
                    cout << "Invalid selection." << endl;
                    break;
                }

                Team team;
                team.addTeam();
                icc.getBoard(index - 1).addTeamToBoard(team);
                cout << "Team added." << endl;
                break;
            }

            case 3:
                icc.registerPlayer();
                break;

            case 4: {
                int boardIndex, teamID, playerID;
                cout << "Select Board: ";
                cin >> boardIndex;
                cout << "Enter Team ID: ";
                cin >> teamID;
                cout << "Enter Player ID: ";
                cin >> playerID;

                icc.addPlayerToTeam(boardIndex - 1, teamID, playerID);
                break;
            }

            case 5:
                icc.organizeTournament();
                break;

            case 6: {
                if (icc.getTournamentCount() == 0) {
                    cout << "No tournaments available." << endl;
                    break;
                }

                int t;
                cout << "Select Tournament: ";
                cin >> t;

                Match match;
                match.playMatch();
                icc.getTournament(t - 1).addMatch(match);
                icc.updateRankings(match);
                cout << "Match added." << endl;
                break;
            }

            case 7:
                for (int i = 0; i < icc.getBoardCount(); i++) {
                    icc.getBoard(i).displayBoard();
                }
                break;

            case 8:
                for (int i = 0; i < icc.getBoardCount(); i++) {
                    icc.getBoard(i).displayBoardBasic();
                }
                break;

            case 9: {
                int i;
                cout << "Select Board: ";
                cin >> i;
                icc.getBoard(i - 1).displayTeamsBasic();
                break;
            }

            case 10: {
                int b, t;
                cout << "Select Board: ";
                cin >> b;
                cout << "Enter Team ID: ";
                cin >> t;

                CricketBoard& board = icc.getBoard(b - 1);
                bool found = false;

                for (int i = 0; i < board.getTeamCount(); i++) {
                    if (board.getTeam(i).getTeamID() == t) {
                        board.getTeam(i).displayTeam();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Team not found." << endl;

                break;
            }

            case 11:
                icc.displayGlobalRankings();
                break;

            case 12: {
                int sub;
                cout << "1. Add Coach\n2. Add Umpire\n3. View Officials\nChoice: ";
                cin >> sub;

                if (sub == 1) {
                    if (coachCount < 5) {
                        coaches[coachCount++].addCoach();
                        cout << "Coach added (not saved yet)." << endl;
                    } else {
                        cout << "Coach list full." << endl;
                    }
                }
                else if (sub == 2) {
                    if (umpireCount < 5) {
                        umpires[umpireCount++].addUmpire();
                        cout << "Umpire added (not saved yet)." << endl;
                    } else {
                        cout << "Umpire list full." << endl;
                    }
                }
                else if (sub == 3) {
                    cout << "\n--- Coaches ---" << endl;
                    for (int i = 0; i < coachCount; i++)
                        coaches[i].displayInfo();

                    cout << "\n--- Umpires ---" << endl;
                    for (int i = 0; i < umpireCount; i++)
                        umpires[i].displayInfo();
                }
                break;
            }

            case 13: {
                icc.saveToCSV();

                // clear & save coaches
                ofstream cClear("coaches.csv");
                cClear.close();
                for (int i = 0; i < coachCount; i++)
                    coaches[i].saveToCSV();

                // clear & save umpires
                ofstream uClear("umpires.csv");
                uClear.close();
                for (int i = 0; i < umpireCount; i++)
                    umpires[i].saveToCSV();

                cout << "Data saved." << endl;
                break;
            }

            case 0: {
                icc.saveToCSV();

                ofstream cClear("coaches.csv");
                cClear.close();
                for (int i = 0; i < coachCount; i++)
                    coaches[i].saveToCSV();

                ofstream uClear("umpires.csv");
                uClear.close();
                for (int i = 0; i < umpireCount; i++)
                    umpires[i].saveToCSV();

                cout << "Bye Bye..." << endl;
                break;
            }
        }

    } while (choice != 0);

    return 0;
}
