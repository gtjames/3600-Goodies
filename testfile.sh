#! /bin/bash
testfile()
{
    if [ $# -eq 1 ]; then
        if [[ -f $1 && -r $1 ]]; then
            echo $1 is a readable file
        else
            echo $1 is not a readable file
        fi
    fi
}

testfile $1
