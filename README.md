# most_frequent

## Description

The file "shakespeare_cleaned.txt" containes all words from texts written by William Shakespeare. We want to answer the following question with the
provided words: For any word length "L" and number "K", what is the Kth most frequent word of length "L"?

## How it works

In the input text file, each line corresponds to a new query, with is a pair of numbers(LENGTH RANK). For example, if the line of input is "9 3" we look
for the fourth mosr frequent word of length 9(rank 3 correspods to 4 because we take 0 into account). The output for each line of the correspondin word. \
If the input file is:  \
    ```
    6 3
    ```
    \
    ```
    10 0
    ``` 
    \
    ```
    9 2
    ```
    \
    ```
    8 14
    ```
    \
    ```
    8 15
    ```
    \
    ```
    26 0
    ```
    \
The output file is:  \
     ```
    father
    ```
    \
    ```
    gloucester
    ``` 
    \
    ```
    messenger
    ```
    \
    ```
    business
    ```
    \
    ```
    personal
    ```
    \
    ```
    -
    ```
    \
So "glucester" is the most frequent word of 10 letters, etc. "Business" and "personal" have the same frequency of 230, but we output "buisness"
because ot comes first lexographically.

## How to install and run project
