#include <stdio.h>

#include "BootsTrap.h"

int main()
{
	
	std::shared_ptr<GL::BootsTrap> bootstrap = std::make_shared<GL::BootsTrap>();
	bootstrap->init();
	bootstrap->play();
	bootstrap->clear();

	

	return 0;
}