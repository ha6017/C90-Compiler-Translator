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
    echo $CTEST

        echo ""
    echo "CASE $NAME"

    #%bin/c_compiler -S test_program.c -o test_program.s
    bin/c_compiler -S test_deliverable/test_cases/$NAME.c -o output_files/$NAME.s 
    if [[ $? -ne 0 ]] ; then
        echo "ERROR : Compiler couldn't compile BWAHAHAHAHA"
        continue
    else 
        echo "passed the 1st command"
    fi 
    #output_files/${NAME}_driver.o

    #%mips-linux-gnu-gcc -mfp32 -o test_program.o -c test_program.s
    mips-linux-gnu-gcc -mfp32 -o output_files/${NAME}.o -c output_files/$NAME.s  
    if [[ $? -ne 0 ]]; then
        echo "ERROR : driver program using gcc failed"
        continue
    else 
        echo "passed the 2nd command"
    fi 

    #mips-linux-gnu-gcc -mfp32 -static -o test_program test_program.o test_program_driver.c
     mips-linux-gnu-gcc -mfp32 -static -o output_files/${NAME}  output_files/${NAME}.o test_deliverable/test_cases/${NAME}_driver.c
    if [[ $? -ne 0 ]]; then
        echo "ERROR : Bitch link failed"
        continue
    fi 

    
    qemu-mips output_files/${NAME}
    echo $?
    if [[ $? -ne 0 ]]; then
        echo "ERROR : Failed testing dickhead"
        pass=pass-1
    else
        echo "passed $NAME"
    fi 

    pass=pass+1
    echo "************************************************************************************"

done
echo "${pass} test passed out of total $TestNo" 