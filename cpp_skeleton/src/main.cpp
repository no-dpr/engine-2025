#include <skeleton/actions.h>
#include <skeleton/constants.h>
#include <skeleton/runner.h>
#include <skeleton/states.h>
#include <time.h>

#include <array>
#include <iostream>

using namespace pokerbots::skeleton;

struct Bot {
 private:
  bool strongHole;

 public:
  /*
    Called when a new round starts. Called NUM_ROUNDS times.

    @param gameState The GameState object.
    @param roundState The RoundState object.
    @param active Your player's index.
  */
  void handleNewRound(GameInfoPtr gameState, RoundStatePtr roundState,
                      int active) {
<<<<<<< HEAD
    // int myBankroll = gameState->bankroll;  // the total number of chips
    // you've gained or lost from the beginning of the game to the start of this
    // round float gameClock = gameState->gameClock;  // the total number of
    // seconds your bot has left to play this game int roundNum =
    // gameState->roundNum;  // the round number from 1 to State.NUM_ROUNDS
    auto myCards = roundState->hands[active];  // your cards
    // bool bigBlind = (active == 1);  // true if you are the big blind

    this->strongHole = false;

    std::array<std::string, 2> card1 = myCards[0];
    std::array<std::string, 2> card2 = myCards[1];

    std::string rank1 = card1[0];
    std::string suit1 = card1[1];
    std::string rank2 = card2[0];
    std::string suit2 = card2[1];

    std::string bestRank = "AKQJ";

    if (rank1 == rank2 || (bestRank)) }
||||||| parent of db96e5d (Initialized repo)
    // int myBankroll = gameState->bankroll;  // the total number of chips you've gained or lost from the beginning of the game to the start of this round 
    // float gameClock = gameState->gameClock;  // the total number of seconds your bot has left to play this game 
    // int roundNum = gameState->roundNum;  // the round number from 1 to State.NUM_ROUNDS 
    // auto myCards = roundState->hands[active];  // your cards 
    // bool bigBlind = (active == 1);  // true if you are the big blind
  }
=======
    // int myBankroll = gameState->bankroll;  // the total number of chips
    // you've gained or lost from the beginning of the game to the start of this
    // round float gameClock = gameState->gameClock;  // the total number of
    // seconds your bot has left to play this game int roundNum =
    // gameState->roundNum;  // the round number from 1 to State.NUM_ROUNDS auto
    // myCards = roundState->hands[active];  // your cards bool bigBlind =
    // (active == 1);  // true if you are the big blind
  }
>>>>>>> db96e5d (Initialized repo)

  /*
    Called when a round ends. Called NUM_ROUNDS times.

    @param gameState The GameState object.
    @param terminalState The TerminalState object.
    @param active Your player's index.
  */
  void handleRoundOver(GameInfoPtr gameState, TerminalStatePtr terminalState,
                       int active) {
    // int myDelta = terminalState->deltas[active];  // your bankroll change
    // from this round
    auto previousState = std::static_pointer_cast<const RoundState>(
        terminalState->previousState);  // RoundState before payoffs
    // int street = previousState->street;  // 0, 3, 4, or 5 representing when
    // this round ended auto myCards = previousState->hands[active];  // your
    // cards auto oppCards = previousState->hands[1-active];  // opponent's
    // cards or "" if not revealed

    bool myBountyHit =
        terminalState
            ->bounty_hits[active];  // true if your bounty hit this round
    bool oppBountyHit =
        terminalState->bounty_hits[1 - active];  // true if your opponent's
                                                 // bounty hit this round

    char bounty_rank = previousState->bounties[active];  // your bounty rank

    // The following is a demonstration of accessing illegal information (will
    // not work)
    char opponent_bounty_rank =
        previousState->bounties[1 - active];  // attempting to grab opponent's
                                              // bounty rank
    if (myBountyHit) {
      std::cout << "I hit my bounty of " << bounty_rank << "!" << std::endl;
    }
    if (oppBountyHit) {
      std::cout << "Opponent hit their bounty of " << opponent_bounty_rank
                << "!" << std::endl;
    }
  }

  /*
    Where the magic happens - your code should implement this function.
    Called any time the engine needs an action from your bot.

    @param gameState The GameState object.
    @param roundState The RoundState object.
    @param active Your player's index.
    @return Your action.
  */
  Action getAction(GameInfoPtr gameState, RoundStatePtr roundState,
                   int active) {
    auto legalActions =
<<<<<<< HEAD
        roundState->legalActions();   // the actions you are allowed to take
    int street = roundState->street;  // 0, 3, 4, or 5 representing pre-flop,
                                      // flop, turn, or river respectively
    auto myCards = roundState->hands[active];  // your cards
    auto boardCards = roundState->deck;        // the board cards
    int myPip =
        roundState->pips[active];  // the number of chips you have contributed
                                   // to the pot this round of betting
    int oppPip = roundState->pips[1 - active];  // the number of chips your
                                                // opponent has contributed to
                                                // the pot this round of betting
    int myStack =
        roundState->stacks[active];  // the number of chips you have remaining
    int oppStack = roundState->stacks[1 - active];  // the number of chips your
                                                    // opponent has remaining
    int continueCost =
        oppPip - myPip;  // the number of chips needed to stay in the pot
    int myContribution =
        STARTING_STACK -
        myStack;  // the number of chips you have contributed to the pot
    int oppContribution =
        STARTING_STACK - oppStack;  // the number of chips your opponent has
                                    // contributed to the pot
    char myBounty = roundState->bounties[active];  // your current bounty rank
||||||| parent of db96e5d (Initialized repo)
        roundState->legalActions(); // the actions you are allowed to take
    int street = roundState->street;  // 0, 3, 4, or 5 representing pre-flop, flop, turn, or river respectively
    auto myCards = roundState->hands[active];  // your cards 
    auto boardCards = roundState->deck;  // the board cards 
    int myPip = roundState->pips[active];  // the number of chips you have contributed to the pot this round of betting 
    int oppPip = roundState->pips[1-active]; // the number of chips your opponent has contributed to the pot this round of betting 
    int myStack = roundState->stacks[active];  // the number of chips you have remaining 
    int oppStack = roundState->stacks[1-active];  // the number of chips your opponent has remaining 
    int continueCost = oppPip - myPip;  // the number of chips needed to stay in the pot
    int myContribution = STARTING_STACK - myStack;  // the number of chips you have contributed to the pot 
    int oppContribution = STARTING_STACK - oppStack;  // the number of chips your opponent has contributed to the pot
    char myBounty = roundState->bounties[active];  // your current bounty rank 
=======
        roundState->legalActions();   // the actions you are allowed to take
    int street = roundState->street;  // 0, 3, 4, or 5 representing pre-flop,
                                      // flop, turn, or river respectively
    auto myCards = roundState->hands[active];  // your cards
    auto boardCards = roundState->deck;        // the board cards
    int myPip =
        roundState->pips[active];  // the number of chips you have contributed
                                   // to the pot this round of betting
    int oppPip =
        roundState
            ->pips[1 - active];  // the number of chips your opponent has
                                 // contributed to the pot this round of betting
    int myStack =
        roundState->stacks[active];  // the number of chips you have remaining
    int oppStack = roundState->stacks[1 - active];  // the number of chips your
                                                    // opponent has remaining
    int continueCost =
        oppPip - myPip;  // the number of chips needed to stay in the pot
    int myContribution =
        STARTING_STACK -
        myStack;  // the number of chips you have contributed to the pot
    int oppContribution =
        STARTING_STACK - oppStack;  // the number of chips your opponent has
                                    // contributed to the pot
    char myBounty = roundState->bounties[active];  // your current bounty rank
>>>>>>> db96e5d (Initialized repo)

    int minCost = 0, maxCost = 0;
    std::array<int, 2> raiseBounds = {0, 0};
    if (legalActions.find(Action::Type::RAISE) != legalActions.end()) {
<<<<<<< HEAD
      raiseBounds =
          roundState->raiseBounds();     // the smallest and largest numbers
                                         // of chips for a legal bet/raise
      minCost = raiseBounds[0] - myPip;  // the cost of a minimum bet/raise
||||||| parent of db96e5d (Initialized repo)
      raiseBounds = roundState->raiseBounds();  // the smallest and largest numbers of chips for a legal bet/raise 
      minCost = raiseBounds[0] - myPip;  // the cost of a minimum bet/raise 
=======
      raiseBounds =
          roundState->raiseBounds();     // the smallest and largest numbers of
                                         // chips for a legal bet/raise
      minCost = raiseBounds[0] - myPip;  // the cost of a minimum bet/raise
>>>>>>> db96e5d (Initialized repo)
      maxCost = raiseBounds[1] - myPip;  // the cost of a maximum bet/raise
    }

    if (legalActions.find(Action::Type::RAISE) != legalActions.end()) {
      if (rand() % 2 == 0) {
        return {Action::Type::RAISE, raiseBounds[0]};
      }
    }
    if (legalActions.find(Action::Type::CHECK) != legalActions.end()) {
      return {Action::Type::CHECK};
    }
    if (rand() % 4 == 0) {
      return {Action::Type::FOLD};
    }
    return {Action::Type::CALL};
  }

 private:
  bool strongHole;
};

/*
  Main program for running a C++ pokerbot.
*/
int main(int argc, char *argv[]) {
  srand(time(NULL));
  auto [host, port] = parseArgs(argc, argv);
  runBot<Bot>(host, port);
  return 0;
}
