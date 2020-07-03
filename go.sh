#!/bin/bash
#This will activate background processing on iOS using geolocation:
cat /dev/location > /dev/null &
./yescompute 8989 &
./yescompute 8990 &
sleep 5
echo  "GO"
./ni.sh &
./ni2.sh &

