/*
Question:

swap odd and even bits of an input integer

*/

/*
Approach:
Isko array traversal ki tarah nhi kar sakte jo mai pehle soch raha tha. Kuch to alag tareeka hona.

ek observation hai from the given example

Position: 87654321
i/p : 23 (00010111)
o/p : 43 (00101011)

yaha dekho ki even position ek se right shift hua hai and odd position ek se left shifted hai output me.
to apne ko bhi yahi karna hai.

Use concept of masking jaha sirf desired positions (even and odd places here) pe set bit hogi

assuming ki integer 32 bit me store hora hai,

(8times * 4bits = 32bits) 

use 0xAAAAAAAA (a hexadecimal bcoz 0x se start hua) to keep track of even places bcoz A=1010, saare even places set hai.
similarly use 0x55555555 to keep track of odd places bcoz 5=0101

if 64 bit system hai to modifications => 0xAAAAAAAAAAAAAAAA AND 0x5555555555555555 (16times * 4bits = 64bits) 

number max [1--32]bit tak hi jaa sakta hai so piche ke saare bits apne aap manage ho jaayenge and hexadecimal sirf
ease of presentation ke liye use karre hai

see the code for further logic
*/

//Issue:
//TC nhi pata iski
//combine wala part ache se nhi samza

#include<iostream>
using namespace std;

int SwapOddEvenBit(int n)
{
	//get and preserve all set bits at even positions
	int even_bits=(n & 0xAAAAAAAA);
	
	//get and preserve all set bits at odd positions
	int odd_bits=(n & 0x55555555);
	
	//shift all even position bits to right by one and odd position bits towards left by one.
	//NOTE: koi bhi bit loss nhi hoga shifting me bcoz even 2nd place se start hota hai and right shift sirf ek se hora hai.
	even_bits=even_bits>>1;
	odd_bits=odd_bits<<1;
	
	//ab dono set bits ko combine karo to get changed number.Use OR operation here
	n=(even_bits | odd_bits);
	
	return n;
}

int main() 
{ 	
	int n;
	
	cout<<"\nEnter the number n"<<" ";
	cin>>n;
	
	//checking for corner cases
	if(n>0)
	{
		//calling our function
		cout<<"\nThe modified n after odd seven bit swap is => "<<" "<<SwapOddEvenBit(n);	
	}
	else
	{
		cout<<"\nEnter positive number ONLY!!";
	}
	return 0;
}
