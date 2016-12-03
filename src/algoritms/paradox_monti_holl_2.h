/*
 * game.h
 *
 *  Created on: 3 дек. 2016 г.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_PARADOX_MONTI_HOLL_2_H_
#define SRC_ALGORITMS_PARADOX_MONTI_HOLL_2_H_

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

namespace paradox_monti_holl_2 {

constexpr int TEST_NUMBERS = 30000;
constexpr int BOX_COUNT = 3;
constexpr int NOT_CHOOSE = -1;
constexpr int FIRST_TIME = 0;
constexpr int SECOND_TIME = 1;
constexpr int ONE_HUNDRED_PERCENT = 100;

class State {
 public:
  State()
      : m_iWinBox(std::rand() % BOX_COUNT),
        m_vSelectedByPlayer(BOX_COUNT - 1, NOT_CHOOSE),
        m_vSelectedByMaster(BOX_COUNT - 2, NOT_CHOOSE),
        m_vBoxes(BOX_COUNT, false) {
  }

  void SetSelectedPlayerByTime(int time, int select) {
    m_vSelectedByPlayer[time] = select;
  }

  int GetSelectedPlayerByTime(int time) const {
    return m_vSelectedByPlayer[time];
  }

  void SetSelectedMasterByTime(int time, int select) {
    m_vSelectedByMaster[time] = select;
  }

  int GetSelectedMasterByTime(int time) const {
    return m_vSelectedByMaster[time];
  }

  void SetOpenBox(int select) {
    m_vBoxes[select] = true;
  }

  bool IsOpenBox(int select) const {
    return m_vBoxes[select];
  }

  int GetWinBox() const {
    return m_iWinBox;
  }
 private:
  int m_iWinBox;
  std::vector<int> m_vSelectedByPlayer;
  std::vector<int> m_vSelectedByMaster;
  std::vector<bool> m_vBoxes;
};

class Strategy {
 public:
  virtual ~Strategy() {
  }
  ;
  virtual void Do(State& state) = 0;
  virtual const char* GetDescription() const = 0;
};

class MasterOpenRandomStrategy : public Strategy {
 public:
  virtual ~MasterOpenRandomStrategy() {
  }
  void Do(State& state) override {
    int playerSelectedFirstTime = state.GetSelectedPlayerByTime(FIRST_TIME);
    int matserChoose = std::rand() % (BOX_COUNT - 1);
    int matserBoxSelect = (playerSelectedFirstTime + matserChoose + 1)
        % BOX_COUNT;
    if (matserBoxSelect == state.GetWinBox()) {
      matserBoxSelect = (playerSelectedFirstTime + (1 - matserChoose) + 1)
          % BOX_COUNT;
    }
    state.SetSelectedMasterByTime(FIRST_TIME, matserBoxSelect);
    state.SetOpenBox(matserBoxSelect);
  }

  const char* GetDescription() const override {
    return "open random empty door strategy";
  }
};

class PlayerSelectFirstStrategy : public Strategy {
 public:
  virtual ~PlayerSelectFirstStrategy() {
  }
  void Do(State& state) override {
    state.SetSelectedPlayerByTime(FIRST_TIME, std::rand() % BOX_COUNT);
  }

  const char* GetDescription() const override {
    return "select random first strategy";
  }
};

class PlayerKeepChooseStrategy : public Strategy {
 public:
  virtual ~PlayerKeepChooseStrategy() {
  }
  void Do(State& state) override {
    int selectedFirstTime = state.GetSelectedPlayerByTime(FIRST_TIME);
    state.SetSelectedPlayerByTime(SECOND_TIME, selectedFirstTime);
    state.SetOpenBox(selectedFirstTime);
  }

  const char* GetDescription() const override {
    return "keep choose strategy";
  }
};

class PlayerChangeChooseStrategy : public Strategy {
 public:
  void Do(State& state) override {
    int selectedSecondTime = (state.GetSelectedPlayerByTime(FIRST_TIME) + 1)
        % BOX_COUNT;
    if (state.IsOpenBox(selectedSecondTime)) {
      selectedSecondTime = (selectedSecondTime + 1) % 3;
    }
    state.SetSelectedPlayerByTime(SECOND_TIME, selectedSecondTime);
    state.SetOpenBox(selectedSecondTime);
  }

  const char* GetDescription() const override {
    return "change choose strategy";
  }
};

template<typename TMasterStrategy, typename TPlayerStrategy, int totalGames>
void PlayGames() {
  int winGames = 0;
  int looseGames = 0;

  std::shared_ptr<Strategy> pStrategy;
  std::shared_ptr<Strategy> pMasterStrategy =
      std::make_shared<TMasterStrategy>();
  std::shared_ptr<Strategy> pPlayerStrategy =
      std::make_shared<TPlayerStrategy>();

  std::cout << std::endl;
  std::cout << "Master: " << pMasterStrategy->GetDescription() << std::endl;
  std::cout << "Player: " << pPlayerStrategy->GetDescription() << std::endl;

  for (int i = 0; i < totalGames; ++i) {
    State state;

    pStrategy = std::make_shared<PlayerSelectFirstStrategy>();
    pStrategy->Do(state);

    pStrategy = pMasterStrategy;
    pStrategy->Do(state);

    pStrategy = pPlayerStrategy;
    pStrategy->Do(state);

    if (state.IsOpenBox(state.GetWinBox())) {
      ++winGames;
    } else {
      ++looseGames;
    }
  }

  std::cout << "Wins: " << winGames << " ("
            << (winGames * ONE_HUNDRED_PERCENT) / totalGames << "%)" << "; ";
  std::cout << "Loose: " << looseGames << " ("
            << (looseGames * ONE_HUNDRED_PERCENT) / totalGames << "%)"
            << std::endl;
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  std::srand(std::time(0));
  paradox_monti_holl_2::PlayGames<
      paradox_monti_holl_2::MasterOpenRandomStrategy,
      paradox_monti_holl_2::PlayerKeepChooseStrategy, TEST_NUMBERS>();
  paradox_monti_holl_2::PlayGames<
      paradox_monti_holl_2::MasterOpenRandomStrategy,
      paradox_monti_holl_2::PlayerChangeChooseStrategy, TEST_NUMBERS>();

  RETURN_OK();
}

}  // namespace paradox_monti_holl_2

#endif /* SRC_ALGORITMS_PARADOX_MONTI_HOLL_2_H_ */
