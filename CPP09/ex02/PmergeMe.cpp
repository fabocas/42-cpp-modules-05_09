#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

};
void PmergeMe::sortVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;
    std::vector<std::pair <int,int> > pairs;
    int straggler = -1;

    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if (v[i] > v[i + 1])     // 8 3 4 5  8 > 3
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
        else
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
    }
    if (v.size() % 2 != 0) // number cant be divided by it is od
        straggler = v.back();
    
    std::vector<int> main_list;
    std::vector<int> small_list;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        main_list.push_back(pairs[i].first); // biger numbers
        small_list.push_back(pairs[i].second); // small numbers
    }
    //sort the list
    if (main_list.size() > 1)
        sortVector(main_list);
    for (size_t i = 0;i < small_list.size();i++)
    {
        std::vector<int>::iterator it = std::lower_bound(main_list.begin(), main_list.end(), small_list[i]);
        main_list.insert(it, small_list[i]);
    }
    if (straggler != -1)
    {
        std::vector<int>::iterator it = std::lower_bound(main_list.begin(), main_list.end(), straggler);
        main_list.insert(it, straggler);
    }
    v = main_list;
}

void PmergeMe::sortDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;
    std::vector<std::pair <int,int> > pairs;
    int straggler = -1;

    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if (d[i] > d[i + 1])     // 8 3 4 5  8 > 3
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
        else
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
    }
    if (d.size() % 2 != 0) // number cant be divided by it is od
        straggler = d.back();
    
    std::deque<int> main_list;
    std::deque<int> small_list;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        main_list.push_back(pairs[i].first); // biger numbers
        small_list.push_back(pairs[i].second); // small numbers
    }
    //sort the list
    if (main_list.size() > 1)
        sortDeque(main_list);
    for (size_t i = 0;i < small_list.size();i++)
    {
        std::deque<int>::iterator it = std::lower_bound(main_list.begin(), main_list.end(), small_list[i]);
        main_list.insert(it, small_list[i]);
    }
    if (straggler != -1)
    {
        std::deque<int>::iterator it = std::lower_bound(main_list.begin(), main_list.end(), straggler);
        main_list.insert(it, straggler);
    }
    d = main_list;
}
