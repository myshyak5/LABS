#include "func.hpp"

bool Read(int& cnt, std::string words[N_max])
{
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        return false;
    }
    while (!in.eof())
    {
        in >> words[cnt];
        cnt++;
    }
    return true;
}
void ClearElements(int cnt, std::string words[N_max])
{
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            if (!std::isalpha(words[i][j]))
            {
                words[i].erase(j, 1);
                j--;
            }
        }
    }
}
bool IsPalindromMoreOneLetter(int cnt, std::string words[N_max])
{
    bool b = false;
    for (int i = 0; i < cnt; i++)
    {
        int m = words[i].length();
        if (m > 1)
        {
            b = true;
            for (int j = 0; j < m / 2; j++)
            {
                char letter1 = tolower(words[i][j]);
                char letter2 = tolower(words[i][m - 1 - j]);
                if ((letter1 != letter2))
                {
                    b = false;
                    break;
                }
            }
            if (b)
            {
                break;
            }
        }
        
    }
    return b;
}
void ClearGl(int cnt, std::string words[N_max])
{
    char gl[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::size_t index = words[i].find(gl[j]);
            while (index != std::string::npos)
            {
                words[i].erase(index, 1);
                index = words[i].find(gl[j], index);
            }
        }
    }
}
void CountOfSogl(int cnt, std::string words[N_max], int CountSogl[N_max])
{
    char sogl[20] {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            char sogli = std::tolower(sogl[j]);
            std::size_t index = words[i].find(sogli);
            while (index != std::string::npos)
            {
                CountSogl[i] += 1;
                index = words[i].find(sogli, index + 1);
            }
        }
    }
}
void SortNotPalindrom(int cnt, std::string words[N_max], int CountSogl[N_max])
{
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (CountSogl[i] < CountSogl[j])
            {
                std::swap(words[i], words[j]);
                std::swap(CountSogl[i], CountSogl[j]);
            }       
        }
    }
}
void SortPalindrom(int cnt, std::string words[N_max], int CountSogl[N_max])
{
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            int m_max = std::min(words[i].length(), words[j].length());
            for (int m = 0; m < m_max; m++)
            {
                if ((int)((char)words[i][m]) > (int)((char)words[j][m]))
                {
                    std::swap(words[i], words[j]);
                    break;
                }
            }
        }
    }
}
bool Write(int cnt, std::string words[N_max])
{
    std::ofstream outt("output.txt");
    if (!outt.is_open())
    {
        return false;
    }
    for (int i = 0; i < cnt; i++)
    {
        outt << words[i] << " ";
    }
    return true;
}