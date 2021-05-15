green=$(tput setaf 2);
red=$(tput setaf 1);
blue=$(tput setaf 32);
orange=$(tput setaf 178);
bold=$(tput bold);
reset=$(tput sgr0);

set -e
g++ -o out E.cpp     #
g++ -o gen gen.cpp 
g++ -o brute brute.cpp 
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./out < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "${green} Passed test:  ${orange} $i ${reset}"
done
echo "${blue} WA on the following test: ${reset}"
cat input_file
echo "${red} Your answer is: ${reset}"
cat myAnswer
echo "${green} Correct answer is: ${reset}"
cat correctAnswer