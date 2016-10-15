#include <iostream>
#include "Editor.hpp"

int main()
{
	try
	{
		Map m(50, 50);
		Editor editor(&m);
		editor.Run();
		return 0;
	}

	catch (std::exception & ex)
	{
		std::cout << ex.what();

		std::cin.get();
		return 1;
	}

}