/*
Lab 2 - Currency Conversion  
1/16/2022
Section 1A
Blake Tigges
*/
#include <stdio.h>

int main() // main function
{
	//Declare Variables and conversion factors 
	float CUR = 0.0; 
	const float USD = 1.0, USD2EUR = 0.8762, USD2CAD = 1.25248, USD2AUD = 1.38645, USD2GBP = 0.73189, USD2CNY = 6.34553; // USD conversion rates from 1/17/2022
	const float EUR = 1.0, EUR2USD = 1 / USD2EUR, EUR2CAD = EUR2USD * USD2CAD, EUR2AUD = EUR2USD * USD2AUD, EUR2GBP = EUR2USD * USD2GBP, EUR2CNY = EUR2USD * USD2CNY; //Convert EUR to USD then to other currency 
	const float CAD = 1.0, CAD2USD = 1 / USD2CAD, CAD2EUR = CAD2USD * USD2EUR, CAD2AUD = CAD2USD * USD2AUD, CAD2GBP = CAD2USD * USD2GBP, CAD2CNY = CAD2USD * USD2CNY; //Convert CAD to USD then to other currency
	const float AUD = 1.0, AUD2USD = 1 / USD2AUD, AUD2EUR = AUD2USD * USD2EUR, AUD2CAD = AUD2USD * USD2CAD, AUD2GBP = AUD2USD * USD2GBP, AUD2CNY = AUD2USD * USD2CNY; //Convert AUD to USD then to other currency
	const float GBP = 1.0, GBP2USD = 1 / USD2GBP, GBP2EUR = GBP2USD * USD2EUR, GBP2CAD = GBP2USD * USD2CAD, GBP2AUD = GBP2USD * USD2AUD, GBP2CNY = GBP2USD * USD2CNY; //Convert GBP to USD then to other currency
	const float CNY = 1.0, CNY2USD = 1 / USD2CNY, CNY2EUR = CNY2USD * USD2EUR, CNY2CAD = CNY2USD * USD2CAD, CNY2AUD = CNY2USD * USD2AUD, CNY2GBP = CNY2USD * USD2GBP; //Convert CNY to USD then to other currency
	
	// Request amount of currency
	printf("Enter the amount of currency to convert: \n");
	scanf("%f", &CUR);
	//CUR = 1; 
	
	// Convert the values and print the table of values 
	printf("\t  USD  |  EUR  |  CAD  |  AUD  |  GBP  |  CNY \n");
	printf("______________________________________________________\n\n");
	printf("USD  |  %.3f | %.3f | %.3f | %.3f | %.3f | %.3f \n", USD * CUR, USD2EUR * CUR, USD2CAD * CUR, USD2AUD * CUR, USD2GBP * CUR, USD2CNY * CUR); // USD Conversions
	printf("______________________________________________________\n\n");
	printf("EUR  |  %.3f | %.3f | %.3f | %.3f | %.3f | %.3f \n", EUR2USD * CUR, EUR * CUR, EUR2CAD * CUR, EUR2AUD * CUR, EUR2GBP * CUR, EUR2CNY * CUR ); // EUR conversion
	printf("______________________________________________________\n\n");
	printf("CAD  |  %.3f | %.3f | %.3f | %.3f | %.3f | %.3f \n", CAD2USD * CUR, CAD2EUR * CUR, CAD * CUR, CAD2AUD * CUR, CAD2GBP * CUR, CAD2CNY * CUR ); // CAD conversions
	printf("______________________________________________________\n\n");
	printf("AUD  |  %.3f | %.3f | %.3f | %.3f | %.3f | %.3f \n", AUD2USD * CUR, AUD2EUR * CUR, AUD2CAD * CUR, AUD * CUR, AUD2GBP * CUR, AUD2CNY * CUR ); // AUD conversions
	printf("______________________________________________________\n\n");
	printf("GBP  |  %.3f | %.3f | %.3f | %.3f | %.3f | %.3f \n", GBP2USD * CUR, GBP2EUR * CUR, GBP2CAD * CUR, GBP2AUD * CUR, GBP * CUR, GBP2CNY * CUR ); // GBP conversions
	printf("______________________________________________________\n\n");
	printf("CNY  |  %.3f | %.3f | %.3f | %.3f | %.3f | %.3f \n", CNY2USD * CUR, CNY2EUR * CUR, CNY2CAD * CUR, CNY2AUD * CUR, CNY2GBP * CUR, CNY * CUR ); // CNY Conversions
	printf("______________________________________________________\n\n");
}
