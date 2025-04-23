echo ""
echo "####### Executing $1 #######"
echo ""

g++ -std=c++11 $1.cpp -o $1 && ./$1

echo ""
echo "################################################"
echo ""