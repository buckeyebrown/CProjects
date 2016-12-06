### Project Description

I initially started with
requesting the user's input, and then verifying if their
input meets the criteria of 2 <= input < 200, and then if 
it does, I stored it in the variable x. Afterwards, I 
iterated through all possible numbers from two to the 
user's value, and printed out all the possible prime 
numbers. To check if it was a prime number, I iterated 
all numbers from 2 to one less than the potentially prime
number, and if the potentialy prime number % any number i,
that was less than the potentially prime number, was 0,
then I knew that the number wasn't prime and flagged it 
as such. However, if it was prime, it was printed out and 
then the next number was checked. This was continued until
we hit the user's input. To check for twin primes, I just 
kept track of the previous prime number, and subtracted it
from the next prime number, and if it equalled two, I 
upped my counter for twin primes. Finally, I printed out 
the number of twin primes.
