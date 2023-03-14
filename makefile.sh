cd presentation_maker

g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.obj
g++ -std=c++17 -Wall -Wextra -c Context.cpp -o Context.obj
g++ -std=c++17 -Wall -Wextra -c error.cpp -o error.obj

g++ -std=c++17 -Wall -Wextra *.obj -o exe.elf `sdl2-config --libs`

rm *.obj

echo
echo "=========================="
echo "| compilation successed! |"
echo "=========================="
echo "    starting execution."
echo "--------------------------"

./exe.elf