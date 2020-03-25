make
for OUTPUT in $(ls ./test)

do
    echo $OUTPUT
    diff <(./qtdriver < test/$OUTPUT/test.in) test/$OUTPUT/test.out

    
    if [[ $1 =~ "m" ]]; then
        
        valgrind ./qtdriver < test/$OUTPUT/test.in &> test.out

        LEAKS=1

        while read -r line; do
            if [[ $line =~ "All heap blocks were freed -- no leaks are possible" ]]; then
                echo "No Leaks"
                LEAKS=0
                break
            fi
        done < test.out

        if [[ $LEAKS -eq 1 ]]; then
            echo "Leaks Found"
        fi
    fi

    echo "-----------------------------------"

done

if [[ $1 =~ "m" ]]; then
    rm test.out
fi

# make clean