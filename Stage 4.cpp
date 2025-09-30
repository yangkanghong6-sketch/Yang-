#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double baseFee, perKmRate, distance, tripFee, tips;
    double priceBeforeTax, priceAfterTax, priceAfterDiscountApplied, finalPrice;
    const double TAX_RATE = 0.08; 
    string promoCode;
    double discount = 0.0;
    int Choice;
    int n = 0;

    cout << "=== Grab Fare Calculator ===\n";
    
    while (n < 1){
    	cout << "Choose your car type:\n";
   		cout << "1. GrabCar (4 pax) - Base RM 5 + RM 1.50/km\n";
   		cout << "2. GrabCar Plus (6 pax) - Base RM 8 + RM 2.00/km\n";
  		cout << "3. GrabCar Premium (Luxury) - Base RM 15 + RM 3.50/km\n";
  		cout << "Enter your choice (1-3): ";
    	cin >> Choice;

    	switch(Choice) {
        	case 1: baseFee = 5; perKmRate = 1.50; break;
        	case 2: baseFee = 8; perKmRate = 2.00; break;
        	case 3: baseFee = 15; perKmRate = 3.50; break;
        	default:
            	cout << "Invalid choice. Defaulting to GrabCar (4 pax).\n";
            	baseFee = 5; perKmRate = 1.50;
    	}
	
    	cout << "Enter trip distance (km): ";
    	cin >> distance;

    	tripFee = baseFee + (perKmRate * distance);

    	priceBeforeTax = tripFee;
    	priceAfterTax = priceBeforeTax * (1 + TAX_RATE);

    	cout << fixed << setprecision(2);
    	cout << "\nTrip fee before tax: RM " << priceBeforeTax << endl;
    	cout << "Trip fee after tax (8%): RM " << priceAfterTax << endl;

    	cout << "\nDo you have a promo code? (yes/no): ";
    	string hasPromo;
    	cin >> hasPromo;

    	if (hasPromo == "yes" || hasPromo == "Yes") {
        	cout << "Enter promo code: ";
        	cin >> promoCode;

        	if (promoCode == "DISCOUNT10") {
            	discount = 0.10 * priceAfterTax; 
        	} 
			else if (promoCode == "FLAT5") {
            	discount = 5.0; 
        	} 
			else {
            	cout << "Invalid promo code. No discount applied.\n";
        	}
    	}

    	priceAfterDiscountApplied = priceAfterTax - discount;
    	if (priceAfterDiscountApplied < 0) priceAfterDiscountApplied = 0; 

    	cout << "\nDiscount applied: RM " << discount << endl;
    	cout << "Price After Discount Applied: RM " << priceAfterDiscountApplied << endl;
    
    	cout << "\nDo you want to give tips to the driver? (yes/no): ";
    	string hasTips;
    	cin >> hasTips;

    	if (hasTips == "yes" || hasTips == "Yes") {
        	cout << "Enter the amount of the Tips (RM): ";
        	cin >> tips;
		}
	
		finalPrice = priceAfterDiscountApplied + tips;
	
		cout << "\nTips: RM " << tips << endl;
    	cout << "Final Price: RM " << finalPrice << endl;
  
