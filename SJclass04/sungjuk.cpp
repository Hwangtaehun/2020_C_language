#include <cstring>
#include "sungjuk.h"
using namespace std;

    void CSungJuk::CompScore()
    {
        m_nTot = m_nKor + m_nEng + m_nMat;
    }

    void CSungJuk::SetName(char *lpszName)
    {
        strcpy(m_szName, lpszName);
    }

    void CSungJuk::SetScore(int k, int e, int m)
    {
        m_nKor = k;
        m_nEng = e;
        m_nMat = m;
    }

    char * CSungJuk::GetName()
    {
        return m_szName;
    }

    int CSungJuk::GetTot()
    {
        return m_nTot;
    }
