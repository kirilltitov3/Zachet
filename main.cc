#include <iostream>
#include <stdexcept>
#include <locale>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "MyWindow.h"


int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {

		MyWindow w;
		w.main_loop();


	} catch (const std::exception &e) {
		std::cerr <<
				"При выполнении программы возникла "
				"ошибка:" << std::endl <<
				e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr <<
				"При выполнении программы возникла "
				"неизвестная ошибка." << std::endl;
		return 1;
	}


	return 0;
}

