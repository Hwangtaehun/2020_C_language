#ifndef SUNGJUK_H_INCLUDED
#define SUNGJUK_H_INCLUDED

class CSungJuk
{
private:
    char m_szName[10];
    int m_nKor;
    int m_nEng;
    int m_nMat;
    int m_nTot;
public:
    void CompScore();
    void SetName(char *lpszName);
    void SetScore(int k, int e, int m);
    char * GetName();
    int GetTot();
};

#endif // SUNGJUK_H_INCLUDED
