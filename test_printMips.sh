echo 'make clean'
echo 'make all'

rm -rf output_files

mkdir -p output_files

declare -i TestNo
TestNo=0

declare -i pass
pass=0

for DRIVER in test_deliverable/test_cases/*_driver.c ; do
    echo "*************************************************************"
        TestNo=TestNo+1
    NAME=$(basename $DRIVER _driver.c)
    CTEST=test_deliverable/test_cases/$NAME.c

        echo ""
    echo "CASE $NAME"

    bin/c_compiler -S $CTEST -o output_files/$NAME.s 
    if[[$? -ne 0 ]]; then
        echo "ERROR : Compiler couldn't compile BWAHAHAHAHA"
        continue
    fi 

    mips-linux-gnu-gcc -c $DRIVER -o output_files/${NAME}_driver.o  
    if[[$? -ne 0 ]]; then
        echo "ERROR : driver program using gcc failed"
        continue
    fi 

    mips-linux-gnu-gcc -c -static output_files/${NAME}_driver.o -o output_files/${NAME}_linked
    if[[$? -ne 0 ]]; then
        echo "ERROR : Bitch link failed"
        continue
    fi 

    qemu-mips output_files/${NAME}_linked
    if[[$? -ne 0 ]]; then
        echo "ERROR : Failed testing dickhead"
        pass=pass-1
    else
        echo "passed $NAME"
    fi 

    pass=pass+1
    echo "************************************************************************************"

done
echo "${pass} test passed out of total $TestNo" 