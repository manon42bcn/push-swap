#!/bin/bash

calculate_average() {
    local total_elements=$1
    local i=0
    local PROM=0
    local MIN=99999999  # Arbitrarily large number to ensure actual minimum is less than this.
    local MAX=0  # To ensure actual maximum is more than this.
    local current=0

    while [ $i -lt 20 ]
    do
        ARGS=$(seq $total_elements | sort -R)
        current=$(./push_swap $ARGS | wc -l)

        # Update the total.
        PROM=$(( $PROM + $current ))

        # Update minimum if current value is smaller.
        [ $current -lt $MIN ] && MIN=$current

        # Update maximum if current value is larger.
        [ $current -gt $MAX ] && MAX=$current

        ((i++))
    done

    echo "------------------------------------"
    echo "Average for $total_elements numbers: " $(($PROM / $i))
    echo "Min: $MIN"
    echo "Max: $MAX"
    echo "------------------------------------"
}

calculate_average 2
calculate_average 5
calculate_average 10
calculate_average 50
calculate_average 100
calculate_average 500