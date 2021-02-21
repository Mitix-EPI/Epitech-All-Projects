#!/bin/bash

cd ..

./101pong 2 3 4 5 6 7 9 >> TEST
diff TEST bonus/reponses/TEST_2_3_4_5_6_7_9
rm TEST

echo NICE | lolcat

./101pong 1 3 5 7 9 -2 4 >> TEST
diff TEST bonus/reponses/TEST_1_3_5_7_9_-2_4
rm TEST

echo NICE | lolcat

./101pong 1.1 3 5 -7 9 2 4 >> TEST
diff TEST bonus/reponses/TEST_1.1_3_5_-7_9_2_4
rm TEST

echo NICE | lolcat

./101pong 0 0 0 0 0 0 0 >> TEST
diff TEST bonus/reponses/TEST_0
rm TEST

echo NICE | lolcat

./101pong 1 1 1 1 1 1 0 >> TEST
diff TEST bonus/reponses/TEST_1_0
rm TEST

echo NICE | lolcat