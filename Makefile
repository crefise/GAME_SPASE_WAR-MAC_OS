all: game
game:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -pedantic  src/*.c -o endgame -I resource/SDL/include -L resource/SDL/lib -l SDL2-2.0.0 -l SDL2_Image-2.0.0 -l SDL2_Mixer-2.0.0 -l SDL2_Ttf-2.0.0 

inst: install_lib

rem_inst: uninstall_lib

install_lib:
	rm -drf resource/SDL
	brew install sdl2
	mkdir resource/SDL
	mkdir resource/SDL/lib
	brew install sdl2_image
	brew install sdl2_mixer
	brew install sdl2_ttf
	sh resource/scripts/install_lib.sh

uninstall_lib:
	rm -drf resource/SDL
