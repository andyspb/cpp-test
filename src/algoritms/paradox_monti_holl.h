/*
 * paradox_monti_holl.h
 *
 *  Created on: 3 дек. 2016 г.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_PARADOX_MONTI_HOLL_H_
#define SRC_ALGORITMS_PARADOX_MONTI_HOLL_H_

namespace paradox_monti_holl {

// равновероятная генерация случайных чисел 0, 1
int rand2() {
  return (rand() % 2);
}

// равновероятная генерация случайных чисел 0, 1, 2
int rand3() {
  return (rand() % 3);
}

// случайно прячем приз
class CSituation {
 public:
  void GenerateRandom() {
    m_nPriceNo = rand3();
    m_bOpened[0] = m_bOpened[1] = m_bOpened[2] = false;
    m_nOpenedByAnchor = -1;
    m_nSelectedByUserFirstTime = m_nSelectedByUserSecondTime = -1;
  }

  bool m_bOpened[3];  // двери
  int m_nPriceNo;  // где спрятан приз

  // выбор игрока и ведущего
  int m_nSelectedByUserFirstTime, m_nSelectedByUserSecondTime,
      m_nOpenedByAnchor;
};

// стратегия честного ведущего,
// игроку выгодно менять выбор, шансы удваиваются
class CAnchorStrategyOpenRandom {
 public:
  static void Act(CSituation& situation) {
    int arVars[2] = { (situation.m_nSelectedByUserFirstTime + 1) % 3, (situation
        .m_nSelectedByUserFirstTime + 2) % 3 };
    // Ведущий открывает случайную дверь, если игрок первым выбором угадал приз
    int nVariantNo = rand2();
    int nVariant = arVars[nVariantNo];
    if (nVariant == situation.m_nPriceNo)
      nVariant = arVars[1 - nVariantNo];
    situation.m_bOpened[situation.m_nOpenedByAnchor = nVariant] = true;
  }

  static std::string GetName() {
    return "Anchorman randomly opens an empty door, 50% : 50%";
  }
};

// 0 стратегия нечестного ведущего,
// для игрока не важно менять выбор или нет, шансы равны,
// в ситуации если ведущим открыта дверь, следующая сразу за выбранной игроком
class CAnchorStrategyOpenNotRandom0 {
 public:
  static void Act(CSituation& situation) {
    int arVars[2] = { (situation.m_nSelectedByUserFirstTime + 1) % 3, (situation
        .m_nSelectedByUserFirstTime + 2) % 3 };
    // Ведущему больше нравится дверь, следующая сразу за выбранной игроком.
    // Если он её отркыл, значит приз равновероятно может находиться в двух оставшихся.
    int nVariantNo = 0;
    int nVariant = arVars[nVariantNo];
    if (nVariant == situation.m_nPriceNo)
      nVariant = arVars[1 - nVariantNo];
    situation.m_bOpened[situation.m_nOpenedByAnchor = nVariant] = true;
  }

  static std::string GetName() {
    return "Anchorman tries to open only the next empty door.";
  }
};

// 1 стратегия нечестного ведущего,
// меняя выбор, игрок гарантированно выигрывает приз,
// в ситуации если открыта дверь, следующая сразу за выбранной игроком
class CAnchorStrategyOpenNotRandom1 {
 public:
  static void Act(CSituation& situation) {
    int arVars[2] = { (situation.m_nSelectedByUserFirstTime + 1) % 3, (situation
        .m_nSelectedByUserFirstTime + 2) % 3 };
    // Ведущему больше нравится дверь, идущая перед выбранной игроком.
    // Если он её не отркыл, значит там точно лежит приз.
    int nVariantNo = 1;
    int nVariant = arVars[nVariantNo];
    if (nVariant == situation.m_nPriceNo)
      nVariant = arVars[1 - nVariantNo];
    situation.m_bOpened[situation.m_nOpenedByAnchor = nVariant] = true;
  }

  static std::string GetName() {
    return "Anchorman tries to open only the previous empty door.";
  }
};

// выбор игроком двери
class CUserStrategySelectFirst {
 public:
  static void Act(CSituation& situation) {
    situation.m_nSelectedByUserFirstTime = rand3();
  }
};

// игрок не меняет выбор
class CUserStrategyKeepTheChoose {
 public:
  static void Act(CSituation& situation) {
    situation.m_nSelectedByUserSecondTime =
        situation.m_nSelectedByUserFirstTime;
    situation.m_bOpened[situation.m_nSelectedByUserSecondTime] = true;
  }

  static std::string GetName() {
    return "Keep the choose";
  }
};

// игрок меняет выбор
class CUserStrategyChange {
 public:
  static void Act(CSituation& situation) {
    situation.m_nSelectedByUserSecondTime = (situation
        .m_nSelectedByUserFirstTime + 1) % 3;
    if (situation.m_bOpened[situation.m_nSelectedByUserSecondTime])
      situation.m_nSelectedByUserSecondTime = (situation
          .m_nSelectedByUserSecondTime + 1) % 3;
    situation.m_bOpened[situation.m_nSelectedByUserSecondTime] = true;
  }

  static std::string GetName() {
    return "Change the choose";
  }
};

// симуляция игры
// TUserStrategy - стратегия игрока
// TAnhorStrategy - стратегия ведущего
// nCountIteration - количество испытаний
template<class TUserStrategy, class TAnhorStrategy, int nCountIteration>
void TestFull() {
  const char* pcszDesc0 = "next door was opened";
  const char* pcszDesc1 = "previous door was opened";

  int nWin[2] = { 0 };
  int nLoose[2] = { 0 };
  const char* aDesc[] = { pcszDesc0, pcszDesc1 };

  CSituation situation;

  for (int i = 0; i < nCountIteration; i++) {
    situation.GenerateRandom();

    CUserStrategySelectFirst::Act(situation);

    TAnhorStrategy::Act(situation);
    TUserStrategy::Act(situation);

    int iNextDoor = (situation.m_nSelectedByUserFirstTime + 1) % 3;
    bool bIsConditionNextDoor = (situation.m_nOpenedByAnchor == iNextDoor);
    int iCondition = bIsConditionNextDoor ? 0 : 1;

    // Посчитаем шансы на выигрыш для каждой ситуации:
    // 0 - известно, что ведущий открыл дверь, которая сразу следует за выбранной игроком
    // 1 - известно, что ведущий открыл дверь, которая предшествует выбранной игроком

    if (situation.m_bOpened[situation.m_nPriceNo]) {
      nWin[iCondition]++;
    } else {
      nLoose[iCondition]++;
    }
  }

  for (int i = 0; i < static_cast<int>(sizeof(nWin) / sizeof(int)); i++) {
    int nCount = nWin[i] + nLoose[i];
    std::cout << i << ") " << aDesc[i] << " (" << nCount * 100 / nCountIteration
        << "%)" << " - ";
    std::cout << "Wins: " << nWin[i] << " (" << nWin[i] * 100 / nCount << "%)"
        << "; ";
    std::cout << "Loose: " << nLoose[i] << " (" << nLoose[i] * 100 / nCount
        << "%)" << std::endl;
  }
}

// две стратегии игрока, для одной стратегии ведущего
// TAnhorStrategy - стратегия ведущего
// nCountIteration - количество испытаний
template<class TAnhorStrategy, int nCountIteration>
void Test() {
  std::cout << "========================================================"
      << std::endl;
  std::cout << "Anchorman strategy: " << TAnhorStrategy::GetName() << std::endl;
  std::cout << std::endl;
  std::cout << "User strategy: " << CUserStrategyKeepTheChoose::GetName()
      << std::endl;
  TestFull<CUserStrategyKeepTheChoose, TAnhorStrategy, nCountIteration>();

  std::cout << std::endl;

  std::cout << "User strategy: " << CUserStrategyChange::GetName() << std::endl;
  TestFull<CUserStrategyChange, TAnhorStrategy, nCountIteration>();

  std::cout << std::endl;
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  srand((unsigned) time(NULL));

  const int nCountIteration = 1500000;  // количество испытаний

  std::cout << "Number of iteration: " << nCountIteration << std::endl;
  Test<CAnchorStrategyOpenRandom, nCountIteration>();  // честный ведущий
  Test<CAnchorStrategyOpenNotRandom0, nCountIteration>();  // нечестный 0
  Test<CAnchorStrategyOpenNotRandom1, nCountIteration>();  // нечестный 1

  RETURN_OK();
}

}  // namespace paradox_monti_holl

#endif /* SRC_ALGORITMS_PARADOX_MONTI_HOLL_H_ */
