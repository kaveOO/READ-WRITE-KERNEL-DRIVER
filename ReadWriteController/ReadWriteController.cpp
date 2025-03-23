#include <iostream>
#include "KernelInterface.hpp"

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\ReadWrite");

	ULONG Address = Driver.GetClientAddress();
	std::cout << "Address right here -> " << Address << std::endl;

	while (true)
	{

	}
}