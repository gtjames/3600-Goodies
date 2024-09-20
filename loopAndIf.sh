for index in 1 2 3 4 5 6 7 8 9 20
do
    if [ $index –le 3 ]; then
        echo "continue" continue
    fi
    echo $index
    if [ $index –ge 8 ]; then
        echo "break"
        break
    fi
done

