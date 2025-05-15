/* Ques 1: Search an element in an array */

#include <iostream>
using namespace std;

int main() {
	int z, n;      // z = element to search, n = size of array.
	string result; // To store the result ("Yes" if found, "No" if not).

	// Prompt for user to enter the element to search.
	cout << "The element which you want to search: ";
	cin >> z;

	// Prompt for user to enter the no. of elements in the array.
	cout << "Enter the no. of elements in the Array: ";
	cin >> n;

	int arr[n]; // Declare an array of size n.
	cout << "Enter elements of Array: ";

	for (int i = 0; i < n; ++i) { // Loop to input array elements.
		cin >> arr[i];            // Read each element.
		// cout << "arr[i] : " << arr[i] << endl;

		// Check if the current element matches the search element.
		if (arr[i] == z) {
			result = "Yes"; // set result to "Yes".
			break;          // Exit the loop early as the element is found.
		}
		else {
			result = "No"; // Set result to "No" (might get overwritten if match is found later).
			continue;      // Continue to next iteration.
		}
	}
	
	cout << result; // Output the result ("Yes" if found, otherwise "No").
	return 0;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* Ques 1: Search an element in an array with multiple test cases.
   The program checks whether a given element exists in the array or not
   for multiple test cases.
*/

#include <iostream>
using namespace std;

int main() {
	int T;
	cout << "Enter the no. of Test cases: ";
    cin >> T;

	// Loop runs 'T' times, once for each test case.
	while (T > 0) { // better condition (T--).
	int z, n;
	bool found = false; // Flag to indicate if the element is found.

	cout << "The element which you want to search: ";
	cin >> z;

	cout << "Enter the no. of elements in the Array: ";
	cin >> n;

	int arr[n];
	cout << "Enter elements of Array: ";

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		// cout << "arr[i] : " << arr[i] << endl;

		if (arr[i] == z) { // If the current element matches the search element.
			found = true;  // Set found flag to true.
			break;         // Exit the loop early as the element is found.
		}
	}

    // Output result based on whether the element was found or not.
	cout << (found ? "Yes": "No") << endl;
	--T; // Decrease the no. of remaining test cases.
	}

	return 0;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* Ques 2: Find maximum value in an Array */

#include <iostream>
using namespace std;
	
int main() {
	int n;
	cout << "Enter the no. of elements in the Array: ";
    cin >> n;

    int arr[n];
	cout << "Enter the Mountain's height: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        // cout << "arr[i] : " << arr[i] << endl;
    }

    int Tallest = arr[0];         // Assuming the first mountain as the tallest initially.
    for (int j = 0; j < n; ++j) { // Using the bubble sort algorithm to update the tallest value if a taller mountain is found.
        if (Tallest < arr[j]) {   // <= if the array has the same 2-3 values. While it only check for the largest means it can be false for the same values.
            Tallest = arr[j];
			// cout << "arr[j] : " << arr[j] << endl;
        }
    }

    cout << "Tallest Mountain: " << Tallest;
	return 0;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* Ques 2: Find maximum value in an Array with multiple test cases. */

#include <iostream>
using namespace std;
	
int main() {
    int T, n;
	cout << "Enter the no. of Test cases: ";
    cin >> T;

    // Loop through all test cases.
    while (T > 0) { // better condition T--
		cout << "Enter the no. of elements in Array: ";
        cin >> n;
		
        int arr[n];
		cout << "Enter the Mountain's height: ";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            // cout << "arr[i] : " << arr[i] << endl;
        }

        int Tallest = arr[0];
        for (int j = 0; j < n; ++j) {
            if (Tallest < arr[j]) {
                Tallest = arr[j];
                // cout << "arr[j] : " << arr[j] << endl;
            }
        }

        cout << "Tallest Mountain: " << Tallest << endl;
        --T;
    }

    return 0;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* Ques 3: Take a discount coupon or Not */

#include <iostream>
using namespace std;

int main() {
    int t;
    cout << "Enter the no. of Test cases: ";
    cin >> t;

    while (t--) {
        int n, x, y;     // n = no. of items, x = cost of the coupon, y = discount amount per item.
        cout << "Enter the no. of elements followed by the cost of the coupon and the reducing amount from each item: ";
        cin >> n >> x >> y;

        int a[n];
        int Total = 0;   // Total cost without buying the discount coupon, meaning without adding x in amount.
        cout << "Enter the price of items: ";

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            Total += a[i];
            // cout << "Total : " << Total << endl;
        }

        int Discount = x;    // Discount is the amount with the cost of x (coupon) initially.

        // Calculate total cost after applying the coupon
        for (int j = 0; j < n; j++) {
            if ((a[j] - y) < 0) {    // Condition to set the price = 0 if the price of an item is less than the discount "y". Instead of setting the -ive value, which will reduce the amount in the Discount.
                Discount += 0;
            }
            else {   // Otherwise, subtract discount from item price.
                Discount += (a[j] - y);
                // cout << "Discount : " << Discount << endl;
            }
        }

        // Compare total costs and decide whether the coupon is beneficial or not.
        if (Discount < Total)
            cout << "Coupon" << endl;
        else
            cout << "No Coupon" << endl;
    }
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* Ques 4: Cost of Groceries */

#include <iostream>
using namespace std;

int main() {
    int T;
    cout << "Enter the no. of Test cases: ";
    cin >> T;

    while (T--) {
        int n, x;     // n = no. of elements, x = min. required freshness value.
        cout << "Enter the no. of elements followed by the min. freshness value that you want: ";
        cin >> n >> x;

        int A[n], B[n];     // A stores freshness values, B stores corresponding costs.
        cout << "Enter the freshness value of each item: ";
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        
        cout << "Enter the cost of each item: ";
        for (int j = 0; j < n; j++) {
            cin >> B[j];
        }

        int Total = 0; // Stores the total cost of groceries that you can buy.
        for(int k = 0; k < n; k++) {
            if(A[k] >= x) {    // Check if item's freshness is at least the min. required value.
                Total += B[k]; // If items have, then add the cost of that item.
            }
        }
        cout << "Total Amount: " << Total << endl;
    }

    return 0;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//
