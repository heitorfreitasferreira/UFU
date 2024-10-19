#!/bin/bash

k128_hex='FE384EF6E548B5A0F4E1133D91E11CEE'
k192_hex='C4A7E2A786AC2C4930B3B0CABD947D4D3E530C24A9C2B59'
k256_hex='8C790DBF3D13E4DE19900C15C3598A6B2F2C70E47373410818A981AA3A4B831'
iv_hex='A16FB13930D3C6F81884DBBB4881E3B2'

files=("arquivo_1MB.txt" "arquivo_100MB.txt" "arquivo_1GB.txt")
file_sizes=("1MB" "100MB" "1GB")
key_sizes=("128" "192" "256")
keys=($k128 $k192 $k256)

cipher_file() {
    local file=$1
    local key_hex=$2
    local iv_hex=$3
    local key_size=$4
    local cipher_file="ciphered_${key_size}_${file}"
    { time openssl enc -aes-${key_size}-cbc -K "$key_hex" -iv "$iv_hex" -in "$file" -out "$cipher_file"; } 2>&1 | grep real | awk '{print $2}'
}

# Inicializando arquivo CSV para armazenar resultados
echo "file_size,key_size,time" > resultados.csv

# Realizando o experimento para cada arquivo e cada chave
for j in {0..2}; do
    file="${files[$j]}"
    file_size="${file_sizes[$j]}"
    for i in {0..2}; do
        key_size=${key_sizes[$i]}
        key_hex=${keys[$i]}
        
        # Cifrando o arquivo 10 vezes e gravando os tempos no CSV
        for iteracao in {1..10}; do
            tempo=$(cipher_file "$file" "$key_hex" "$iv_hex" "$key_size")
            # Convertendo o tempo do formato mm:ss para segundos
            minutos=$(echo $tempo | cut -d'm' -f1)
            segundos=$(echo $tempo | cut -d'm' -f2 | cut -d's' -f1)
            tempo_total=$(echo "$minutos*60 + $segundos" | bc)
            
            # Adicionando resultado ao arquivo CSV
            echo "$file_size,$key_size,$tempo_total" >> resultados.csv
        done
    done
done