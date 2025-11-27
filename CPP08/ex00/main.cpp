#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	std::cout << "Array : ";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "Found : " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}