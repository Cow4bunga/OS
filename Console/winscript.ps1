#Build number
echo [Build Number]
g++ -c Num\NumberLibrary.cpp -o .\wbuild\number.o 
ar rvs .\wbuild\number.lib .\wbuild\number.o 

echo [Build Vector]
g++ -c Vect\VectLib.cpp -INum -o .\wbuild\vector.o 
g++ .\wbuild\vector.o .\wbuild\number.lib -shared -o .\wbuild\vector.dll

echo [Build Main]
g++ .\win_cons\Test\LibrariesDemo.cpp -o .\wbuild\demo -INum -IVect .\wbuild\vector.dll .\wbuild\number.lib

.\wbuild\demo 