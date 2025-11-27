#include "Span.hpp"
#include <iostream>
#include <limits.h>

int	main(void)
{
	const int	N = 10000;

	Span sp(N);
    srand(time(NULL));
	for (unsigned int i = 0; i < N; i++)
	{
		try
		{
			sp.addNumber(rand() % 192288462);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// std::cout << "|   INTS   | " << std::endl;
	// for (unsigned int i = 0; i < sp.size(); i++)
	// {
	// 	std::cout << sp[i] << " ";
	// }
	// std::cout << std::endl;
	try
	{
		std::cout << "the shortest span is : " << sp.shortestSpan() << std::endl;
		std::cout << "the longest span is : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "Generated 10000 values with a randomized value from 0 and MAX_INT" << std::endl
              << sp.size() << " values where stored" << std::endl;

    int repeated = 10000 - sp.size();
    if (repeated)
    {
        if (repeated == 1)
            std::cout << "you got 1 duplicated value the chance of that happening is ONLY 20%!" << std::endl;
        else if (repeated == 2)
            std::cout << "you got 2 duplicated values the chance of that happening is ONLY 5%!" << std::endl;
        else
            std::cout << "you got more than 2 duplicated values the chance of that happening is CLOSE to IMPOSSIBLE!" << std::endl;
    }
	return (0);
}