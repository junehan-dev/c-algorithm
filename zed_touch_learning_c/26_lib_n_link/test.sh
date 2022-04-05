cc -c dynamic_lib.c -o dynamic_lib.o 
cc -shared dynamic_lib.o -o d_lib.so

cc -Wall -g -DNDEBUG main.c -ldl -o main.out

echo "1: main.out ./d_lib.so print_a_message 'hello there'"
main.out ./d_lib.so print_a_message "hello there"
echo ""
echo "2: ./main.out ./d_lib.so print_a_message "hello there""
./main.out ./d_lib.so print_a_message "hello there"
echo ""
echo "3:./main.out ./d_lib.so uppercase "hello there""
./main.out ./d_lib.so uppercase "hello there"
echo ""
echo "4:./main.out ./d_lib.so lowercase "HELLO tHeRe""
./main.out ./d_lib.so lowercase "HELLO tHeRe"
echo ""
echo "5:./main.out ./d_lib.so fail_on_purpose "i fail""
./main.out ./d_lib.so fail_on_purpose "i fail"
echo ""
echo "6:./main.out ./d_lib.so fail_on_purpose"
./main.out ./d_lib.so fail_on_purpose
echo ""
echo "7:./main.out ./d_lib.so not_exist_name_function"
./main.out ./d_lib.so not_exist_name_function 
echo ""
echo "8:./main.out ./d_lib.so not_exist_name_function not_exist_name_function_2"
./main.out ./d_lib.so not_exist_name_function not_exist_name_function_2
echo ""
echo "9:./main.out ./not_exist.so not_exist_name_function not_exist_name_function_2"
./main.out ./not_exist.so not_exist_name_function not_exist_name_function_2
echo ""
echo "fin--"

rm *.o
rm *.so
rm *.out
