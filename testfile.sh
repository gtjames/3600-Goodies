#! /bin/bash
testfile()
{
    if [ $# -eq 1 ]; then
        if [[ -f $1 && -r $1 ]]; then
            echo $1 is a readable file
        elseyy
            echo $1 is not a readable file
        fi
    else
        echo "0 or 2 or more args entered"
    fi
}

testfile $1
