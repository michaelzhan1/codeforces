#!/bin/sh

touch $1.cpp
touch $1.txt

cat << EOF >> $1.cpp
#include <iostream>
#include <string>

int main()
{
    return 0;
}