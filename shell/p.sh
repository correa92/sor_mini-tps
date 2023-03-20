#!/bin/bash

kernel=$(uname -s)
architecture=$(uname -m)
cpu=$(uname -p)

cat /proc/interrupts > i.txt

interruptions=$(cat -n i.txt | head -n 11)

memo=$(free -m -t)
placaVideo=$(lspci | grep VGA)

echo "Mi Kernel es $kernel"
echo "Arquitectura: $architecture"
echo "*****************************************************"
echo "CPU: $cpu"
echo "*****************************************************"
echo "Interrupciones:" 
echo "$interruptions"
echo "*****************************************************"
echo "Memoria RAM + SWAP (Megabytes)"
echo "$memo"
echo "*****************************************************"
echo "Placa de Video: $placaVideo"
