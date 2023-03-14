cd presentation_maker

g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.obj
g++ -std=c++17 -Wall -Wextra -c Context.cpp -o Context.obj
g++ -std=c++17 -Wall -Wextra -c Game.cpp -o Game.obj
g++ -std=c++17 -Wall -Wextra -c error.cpp -o error.obj

g++ -std=c++17 -Wall -Wextra *.obj -o exe.exe -L"../libs" -lmingw32 -lSDL2main -lSDL2

.\exe.exe