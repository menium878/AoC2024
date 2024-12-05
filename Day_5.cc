#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
bool hasPair(const std::vector<std::pair<int, int>> &vec, int a, int b)
{
    for (const auto &p : vec)
    {
        if (p.first == a && p.second == b)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int sum = 0;
    int sum1 =0;
    char ch;
    std::string line;
    std::ifstream file("cos.txt");
    bool foundEmptyLine = false;
    std::vector<std::pair<int, int>> firstContainer;
    std::vector<int> secondContainer;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
            if (line.empty())
            {
                foundEmptyLine = true;
                continue; 
            }
            size_t delimiterPos = line.find("|");
            
            if (!foundEmptyLine)
            {
                int firstNum = std::stoi(line.substr(0, delimiterPos));   
                int secondNum = std::stoi(line.substr(delimiterPos + 1)); 
                firstContainer.emplace_back(firstNum, secondNum);
            }
            else
            {
                std::stringstream ss(line);
                std::string word="";
                while (std::getline(ss, word, ','))
                {
                    
                    secondContainer.push_back(stoi(word));
                }
                ss.clear();
                ss.str(std::string());
                ss.clear();
                std::vector<int> k = secondContainer;
                auto n = k.size();
                bool swapped;
                for (int i = 0; i < n - 1; i++)
                {
                    swapped = false;
                    for (int j = 0; j < n - i - 1; j++)
                    {
                        if (!hasPair(firstContainer, k[j], k[j + 1]))
                        {
                            std::swap(k[j], k[j + 1]);
                            swapped = true;
                        }
                        
                    }
                }
                if (k == secondContainer)
                        {
                            auto index = std::ceil(n / 2.0);
                            sum += secondContainer[index - 1];
                        }
                        
                else{
                    auto index = std::ceil(n / 2.0);
                            sum1 += k[index - 1];
                }
                secondContainer.clear();
            }
        }
    }
    std::cout << std::endl
              << sum
              << std::endl
              << sum1;
    return 0;
}

