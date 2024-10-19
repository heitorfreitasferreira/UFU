#!/bin/bash

# Criação de dez textos claros (M1, M2, ..., M10) com exatamente 16 bytes
echo "abcdefghijhkde1" > M1.txt
truncate -s 16 M1.txt
echo "klmnopqrstuvwx" > M2.txt
truncate -s 16 M2.txt
echo "1234567890abcd" > M3.txt
truncate -s 16 M3.txt
echo "zyxwvutsrqponm" > M4.txt
truncate -s 16 M4.txt
echo "qwertyuiopasdf" > M5.txt
truncate -s 16 M5.txt
echo "zxcvbnmlkjhgfd" > M6.txt
truncate -s 16 M6.txt
echo "poiuytrewqlmnb" > M7.txt
truncate -s 16 M7.txt
echo "mnbvcxzlkjhpoi" > M8.txt
truncate -s 16 M8.txt
echo "asdfghjklzxcvb" > M9.txt
truncate -s 16 M9.txt
echo "qazwsxedcrfvtg" > M10.txt
truncate -s 16 M10.txt

# Gerar uma chave de 128 bits
key=$(openssl rand -hex 16)
echo "Chave de 128 bits gerada: $key"

# Modificar 1 byte em cada um dos textos (criando M1', M2', ..., M10')
sed 's/a/z/' M1.txt > M1_prime.txt
sed 's/k/y/' M2.txt > M2_prime.txt
sed 's/1/0/' M3.txt > M3_prime.txt
sed 's/z/x/' M4.txt > M4_prime.txt
sed 's/q/w/' M5.txt > M5_prime.txt
sed 's/z/a/' M6.txt > M6_prime.txt
sed 's/p/o/' M7.txt > M7_prime.txt
sed 's/m/n/' M8.txt > M8_prime.txt
sed 's/a/s/' M9.txt > M9_prime.txt
sed 's/q/z/' M10.txt > M10_prime.txt

# Cifrar os textos originais com AES-ECB
for i in {1..10}; do
    openssl enc -aes-128-ecb -nosalt -nopad -K "$key" -in M$i.txt -out C$i.enc
done

# Cifrar os textos modificados com AES-ECB
for i in {1..10}; do
    openssl enc -aes-128-ecb -nosalt -nopad -K "$key" -in M${i}_prime.txt -out C${i}_prime.enc
done

compare_bits() {
    file1=$1
    file2=$2
    
    # Extrair os bits dos arquivos cifrados
    bits1=$(xxd -b "$file1" | cut -d" " -f 2-7 | tr "\n" " ")
    bits2=$(xxd -b "$file2" | cut -d" " -f 2-7 | tr "\n" " ")

    # Contar quantos bits são diferentes
    bit_diff=0
    for ((i=0; i<${#bits1}; i++)); do
        if [ "${bits1:$i:1}" != "${bits2:$i:1}" ]; then
            bit_diff=$((bit_diff+1))
        fi
    done
    echo $bit_diff
}

echo "Arquivo, Bits Diferentes, Taxa de Bits Diferentes" > avalanche_resultados.csv
for i in {1..10}; do
    bit_diff=$(compare_bits C$i.enc C${i}_prime.enc)
    taxa=$(echo "$bit_diff/128" | bc -l)
    echo "C$i, $bit_diff, $taxa" >> avalanche_resultados.csv
done

