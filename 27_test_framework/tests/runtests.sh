echo "Runs tests:"

for i in tests/*_tests
do
    if test -f $i
    then
        if $VALGRIND ./$1 2>> tests/tests.log
        then
            echo $1 PASS
        else
            echo "ERROR in test $1: see tests/tests.log"
            echo "----------------"
            tail tests/tests.log
            exit 1
        fi
    fi
done

echo ""
