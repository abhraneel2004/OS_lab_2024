#!/bin/bash

# Function to calculate power
pow() {
    local base=$1
    local exp=$2
    local result=1
    
    for((i=1; i<=exp; i++)); do
        result=$((result * base))
    done
    echo $result    # Echo the actual result, not the word "base"
}

# Function to calculate factorial
facto() {
    local num=$1
    local result=1
    
    for((i=2; i<=num; i++)); do
        result=$((result * i))
    done
    echo $result    # Echo the actual result, not the word "facto"
}

# Get input values
read -p "Enter the value of x: " x
echo $x
read -p "Enter the value of n: " n
echo $n

# Calculate series sum
sum=0
for((i=1; i<=n; i++)); do
    term=$(pow $x $i)           # Proper function call syntax
    fact=$(facto $i)            # Calculate factorial
    term2=$(echo "scale=6; $term / $fact" | bc)  # Use bc for floating point division
    sum=$(echo "scale=6; $sum + $term2" | bc)    # Use bc for floating point addition
done

echo "Sum of the series is $sum"