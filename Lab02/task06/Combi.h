#pragma once
#include <algorithm>
#define NINF  ((short)0x8000)

namespace combi
{
    struct  xcombination           // ���������  ��������� (���������) 
    {
        short  n,                  // ���������� ��������� ��������� ���������  
            m,                  // ���������� ��������� � ���������� 

            * sset;            	  // ������ �������� �������� ���������  
        xcombination(
            short n = 1, //���������� ��������� ��������� ���������  
            short m = 1  // ���������� ��������� � ����������
        );
        void reset();              // �������� ���������, ������ ������� 
        short getfirst();          // ������������ ������ ������ ��������    
        short getnext();           // ������������ ��������� ������ ��������  
        short ntx(short i);        // �������� i-� ������� ������� ��������  
        unsigned __int64 nc;       // ����� ���������  0,..., count()-1   
        unsigned __int64 count() const;  // ��������� ���������� ���������      
    };
};
