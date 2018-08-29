/*
 * paradox_monti_holl.h
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_PARADOX_MONTI_HOLL_H_
#define SRC_ALGORITMS_PARADOX_MONTI_HOLL_H_

namespace paradox_monti_holl {

// �������������� ��������� ��������� ����� 0, 1
int rand2() {
  return (rand() % 2);
}

// �������������� ��������� ��������� ����� 0, 1, 2
int rand3() {
  return (rand() % 3);
}

// �������� ������ ����
class CSituation {
 public:
  void GenerateRandom() {
    m_nPriceNo = rand3();
    m_bOpened[0] = m_bOpened[1] = m_bOpened[2] = false;
    m_nOpenedByAnchor = -1;
    m_nSelectedByUserFirstTime = m_nSelectedByUserSecondTime = -1;
  }

  bool m_bOpened[3];  // �����
  int m_nPriceNo;  // ��� ������� ����

  // ����� ������ � ��������
  int m_nSelectedByUserFirstTime, m_nSelectedByUserSecondTime,
      m_nOpenedByAnchor;
};

// ��������� �������� ��������,
// ������ ������� ������ �����, ����� �����������
class CAnchorStrategyOpenRandom {
 public:
  static void Act(CSituation& situation) {
    int arVars[2] = { (situation.m_nSelectedByUserFirstTime + 1) % 3, (situation
        .m_nSelectedByUserFirstTime + 2) % 3 };
    // ������� ��������� ��������� �����, ���� ����� ������ ������� ������ ����
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

// 0 ��������� ���������� ��������,
// ��� ������ �� ����� ������ ����� ��� ���, ����� �����,
// � �������� ���� ������� ������� �����, ��������� ����� �� ��������� �������
class CAnchorStrategyOpenNotRandom0 {
 public:
  static void Act(CSituation& situation) {
    int arVars[2] = { (situation.m_nSelectedByUserFirstTime + 1) % 3, (situation
        .m_nSelectedByUserFirstTime + 2) % 3 };
    // �������� ������ �������� �����, ��������� ����� �� ��������� �������.
    // ���� �� � ������, ������ ���� ������������� ����� ���������� � ���� ����������.
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

// 1 ��������� ���������� ��������,
// ����� �����, ����� �������������� ���������� ����,
// � �������� ���� ������� �����, ��������� ����� �� ��������� �������
class CAnchorStrategyOpenNotRandom1 {
 public:
  static void Act(CSituation& situation) {
    int arVars[2] = { (situation.m_nSelectedByUserFirstTime + 1) % 3, (situation
        .m_nSelectedByUserFirstTime + 2) % 3 };
    // �������� ������ �������� �����, ������ ����� ��������� �������.
    // ���� �� � �� ������, ������ ��� ����� ����� ����.
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

// ����� ������� �����
class CUserStrategySelectFirst {
 public:
  static void Act(CSituation& situation) {
    situation.m_nSelectedByUserFirstTime = rand3();
  }
};

// ����� �� ������ �����
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

// ����� ������ �����
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

// ��������� ����
// TUserStrategy - ��������� ������
// TAnhorStrategy - ��������� ��������
// nCountIteration - ���������� ���������
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

    // ��������� ����� �� ������� ��� ������ ��������:
    // 0 - ��������, ��� ������� ������ �����, ������� ����� ������� �� ��������� �������
    // 1 - ��������, ��� ������� ������ �����, ������� ������������ ��������� �������

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

// ��� ��������� ������, ��� ����� ��������� ��������
// TAnhorStrategy - ��������� ��������
// nCountIteration - ���������� ���������
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

  const int nCountIteration = 1500000;  // ���������� ���������

  std::cout << "Number of iteration: " << nCountIteration << std::endl;
  Test<CAnchorStrategyOpenRandom, nCountIteration>();  // ������� �������
  Test<CAnchorStrategyOpenNotRandom0, nCountIteration>();  // ��������� 0
  Test<CAnchorStrategyOpenNotRandom1, nCountIteration>();  // ��������� 1

  RETURN_OK();
}

}  // namespace paradox_monti_holl

#endif /* SRC_ALGORITMS_PARADOX_MONTI_HOLL_H_ */
