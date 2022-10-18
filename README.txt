Case i (Linear Probing):
   
for load factor of 0.5 (1000), I got the average number of comparison 1.492, Expected: 1.5, Delta = 0.00800002
for load factor of 0.2 (400), I got the average number of comparison 1.1275, Expected: 1.1, Delta = 0.0275001
for load factor of 0.8 (~1600), I got the average number of comparison 2.78049, Expected: 3, Delta = 0.219512

Case ii (Linear Probing):

for load factor of 0.5 (1000), I got the average number of comparison 2.429, Expected: 2.5, Delta = 0.0710001
for load factor of 0.2 (400), I got the average number of comparison 1.3225, Expected: 1.2, Delta = 0.1225
for load factor of 0.8 (~1600), I got the average number of comparison 13.2614, Expected: 13, Delta = 0.261414

Case i (Quadratic Probing):

for load factor of 0.5 (1000), I got the average number of comparison 1.435, Expected: 1.4, Delta = 0.0349999
for load factor of 0.2 (400), I got the average number of comparison 1.16, Expected: 1.1, Delta = 0.06
for load factor of 0.8 (~1600), I got the average number of comparison 2.11882, Expected: 2.2, Delta = 0.0811758

Case ii (Quadratic Probing):

for load factor of 0.5 (1000), I got the average number of comparison 2.166, Expected: 2.1, Delta = 0.0659999
for load factor of 0.2 (400), I got the average number of comparison 1.2725, Expected: 1.2, Delta = 0.0725
for load factor of 0.8 (~1600), I got the average number of comparison 5.50407, Expected: 6.4, Delta = 0.895935

In conclusion, these numbers imply that the complexity of Linear and Quadratic hashing for insertion and search is constant(Big-O of them is 1). Another observation is the increase from the runtime is not because of the high complexity of hashing and is because of the size of the file we are processing.
