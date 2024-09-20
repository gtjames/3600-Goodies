if [ "$#" -ne 1 ]; then
    read -p "Enter # of random numbers needed: " count
else
    count=$1
fi
for i in $(seq $count); do
    echo $RANDOM
done

