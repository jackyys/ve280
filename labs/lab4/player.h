#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hero.h"
#include "exceptions.h"
#include <deque>

enum Camp {
    RED = 41, GREEN = 42, YELLOW = 43, BLUE = 44, CAMP_SIZE = 4
};

class Player {
protected:
    std::string name;
    Camp camp;
    Hero *hero;
    unsigned int health;
    bool striked;
    std::deque<const Card *> cards;
public:
    Player(const std::string &name, Camp camp);

    virtual std::string getName() const;

    virtual void printName() const;

    virtual Camp getCamp() const;

    virtual const Hero *getHero() const;

    virtual unsigned int getHealth() const;

    virtual void increaseHealth();

    virtual void decreaseHealth();

    virtual void printHealth() const;

    virtual bool getStriked() const;

    virtual void setStriked(bool striked);

    virtual size_t getNumCards() const;

    virtual void printCards() const;

    virtual const Card *eraseCard(size_t index);

    virtual void pushCard(const Card *card);

    virtual void printPlayer() const;

    virtual void drawCard();

    virtual void drawCards(size_t num);

    virtual void playCard() = 0;

    virtual void printPlay(const Card *card) const;

    virtual void printPlay(const Card *card, const Player *target) const;

    virtual void printHit(const Card *card);

    virtual Player *selectTarget() = 0;

    virtual const Card *requestCard(Action action) = 0;

    virtual void discardCard(size_t index);

    virtual void discardCards() = 0;

    virtual ~Player();
};

class HumanPlayer : public Player {
private:
    void readCommand(std::string &command, std::vector<size_t> &args);

    void handleGeneralCommand(const std::string &command, const std::vector<size_t> &args) const;

public:
    HumanPlayer(const std::string &name, Camp camp);

    void playCard() override;

    Player *selectTarget() override;

    const Card *requestCard(Action action) override;

    void discardCards() override;
};

class MyopicPlayer : public Player {
public:
    MyopicPlayer(const std::string &name, Camp camp);

    void playCard() override;

    Player *selectTarget() override;

    const Card *requestCard(Action action) override;

    void discardCards() override;
};

#endif
