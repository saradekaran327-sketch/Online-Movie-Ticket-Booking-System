#include<iostream>
#include<string>
using namespace std;


// =========================
// MOVIE CLASS
// =========================

class Movie
{
public:
    int movieId;
    string movieName;
    string genre;
    int duration;
    float rating;

    void displayMovie()
    {
        cout << "Movie ID: " << movieId << endl;
        cout << "Movie Name: " << movieName << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
        cout << "-----------------------------" << endl;
    }
};


// =========================
// THEATRE CLASS
// =========================

class Theatre
{
public:
    int theatreId;
    string theatreName;
    string city;
    int screenNo;

    void displayTheatre()
    {
        cout << "Theatre ID: " << theatreId << endl;
        cout << "Theatre Name: " << theatreName << endl;
        cout << "City: " << city << endl;
        cout << "Screen No: " << screenNo << endl;
        cout << "-----------------------------" << endl;
    }
};


// =========================
// SHOW CLASS
// =========================

class Show
{
public:
    int showId;
    int movieId;
    int theatreId;
    string showDate;
    string showTime;

    void displayShow()
    {
        cout << "Show ID: " << showId << endl;
        cout << "Movie ID: " << movieId << endl;
        cout << "Theatre ID: " << theatreId << endl;
        cout << "Date: " << showDate << endl;
        cout << "Time: " << showTime << endl;
        cout << "-----------------------------" << endl;
    }
};


// =========================
// SEAT CLASS
// =========================

class Seat
{
public:
    string seatNo[25];
    bool isBooked[25];
    string seatType[25];
    int seatPrice[25];
    int totalSeats;

    void displaySeats()
    {
        cout << endl;
        cout << "========== SEAT LAYOUT ==========" << endl;
        cout << endl;
        cout << "\t\t\tSCREEN" << endl;
        cout << "---------------------------------------------" << endl;

        for(int i = 0; i < totalSeats; i++)
        {
            cout << seatNo[i] << " Rs." << seatPrice[i];

            if(isBooked[i] == true)
            {
                cout << "(X)";
            }
            else
            {
                cout << "(A)";
            }

            cout << "\t";

            // New row after every 5 seats
            if((i + 1) % 5 == 0)
            {
                cout << endl;
            }

            // Balcony starts after Row C
            if(i == 14)
            {
                cout << endl;
                cout << "\t\t===== BALCONY =====" << endl;
                cout << endl;
            }
        }

        cout << endl;
        cout << "(A) = Available\t(X) = Booked" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Regular  : Rs.199" << endl;
        cout << "Premium  : Rs.249" << endl;
        cout << "Balcony  : Rs.399" << endl;
        cout << "=============================================" << endl;
    }
};

//========================
// CUSTOMER CLASS
//========================

class Customer
{
public:
    int customerId;
    string customerName;
    string mobileNo;

    void displayCustomer()
    {
        cout << "Customer ID   : " << customerId << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << "Mobile Number : " << mobileNo << endl;
        cout << "-----------------------------" << endl;
    }
};

// =========================
// MAIN FUNCTION
// =========================

int main()
{

    // =========================
    // MOVIE SECTION
    // =========================

    Movie movies[6];

    movies[0].movieId = 1;
    movies[0].movieName = "Avatar";
    movies[0].genre = "Action";
    movies[0].duration = 162;
    movies[0].rating = 4.5;

    movies[1].movieId = 2;
    movies[1].movieName = "Avengers";
    movies[1].genre = "Action";
    movies[1].duration = 181;
    movies[1].rating = 4.3;

    movies[2].movieId = 3;
    movies[2].movieName = "Dangal";
    movies[2].genre = "Drama";
    movies[2].duration = 161;
    movies[2].rating = 4.6;

    movies[3].movieId = 4;
    movies[3].movieName = "KGF";
    movies[3].genre = "Action";
    movies[3].duration = 168;
    movies[3].rating = 4.4;

    movies[4].movieId = 5;
    movies[4].movieName = "3Idiots";
    movies[4].genre = "Comedy";
    movies[4].duration = 170;
    movies[4].rating = 4.7;

    movies[5].movieId = 6;
    movies[5].movieName = "Pushpa";
    movies[5].genre = "Action";
    movies[5].duration = 179;
    movies[5].rating = 4.1;


    cout << "===== ONLINE MOVIE TICKET BOOKING SYSTEM =====" << endl;
    cout << endl;

    cout << "===== MOVIE LIST =====" << endl;

    for(int i = 0; i < 6; i++)
    {
        movies[i].displayMovie();
    }


    // =========================
    // MOVIE SELECTION
    // =========================

    int choice = 0;

    while(choice < 1 || choice > 6)
    {
        cout << "Enter Movie ID to select movie: ";
        cin >> choice;

        if(choice < 1 || choice > 6)
        {
            cout << "Invalid Movie ID!" << endl;
            cout << "Please enter a valid Movie ID." << endl;
        }
    }

    cout << endl;
    cout << "===== SELECTED MOVIE =====" << endl;
    movies[choice - 1].displayMovie();


    // =========================
    // THEATRE SECTION
    // =========================

    Theatre theatres[4];

    theatres[0].theatreId = 1;
    theatres[0].theatreName = "PVR Phoenix Market City";
    theatres[0].city = "Pune";
    theatres[0].screenNo = 1;

    theatres[1].theatreId = 2;
    theatres[1].theatreName = "INOX Bund Garden";
    theatres[1].city = "Pune";
    theatres[1].screenNo = 2;

    theatres[2].theatreId = 3;
    theatres[2].theatreName = "Cinepolis Seasons Mall";
    theatres[2].city = "Pune";
    theatres[2].screenNo = 3;

    theatres[3].theatreId = 4;
    theatres[3].theatreName = "City Pride Kothrud";
    theatres[3].city = "Pune";
    theatres[3].screenNo = 4;


    cout << endl;
    cout << "===== PUNE THEATRE LIST =====" << endl;

    for(int i = 0; i < 4; i++)
    {
        theatres[i].displayTheatre();
    }


    // =========================
    // THEATRE SELECTION
    // =========================

    int theatreChoice = 0;

    while(theatreChoice < 1 || theatreChoice > 4)
    {
        cout << "Enter Theatre ID to select theatre: ";
        cin >> theatreChoice;

        if(theatreChoice < 1 || theatreChoice > 4)
        {
            cout << "Invalid Theatre ID!" << endl;
            cout << "Please enter a valid Theatre ID." << endl;
        }
    }

    cout << endl;
    cout << "===== SELECTED THEATRE =====" << endl;
    theatres[theatreChoice - 1].displayTheatre();


    // =========================
    // SHOW SECTION
    // =========================

    Show shows[4];

    shows[0].showId = 1;
    shows[0].movieId = choice;
    shows[0].theatreId = theatreChoice;
    shows[0].showDate = "20-08-2026";
    shows[0].showTime = "10:00 AM";

    shows[1].showId = 2;
    shows[1].movieId = choice;
    shows[1].theatreId = theatreChoice;
    shows[1].showDate = "20-08-2026";
    shows[1].showTime = "01:00 PM";

    shows[2].showId = 3;
    shows[2].movieId = choice;
    shows[2].theatreId = theatreChoice;
    shows[2].showDate = "20-08-2026";
    shows[2].showTime = "04:00 PM";

    shows[3].showId = 4;
    shows[3].movieId = choice;
    shows[3].theatreId = theatreChoice;
    shows[3].showDate = "20-08-2026";
    shows[3].showTime = "07:00 PM";


    cout << endl;
    cout << "===== AVAILABLE SHOWS =====" << endl;

    for(int i = 0; i < 4; i++)
    {
        shows[i].displayShow();
    }


    // =========================
    // SHOW SELECTION
    // =========================

    int showChoice = 0;

    while(showChoice < 1 || showChoice > 4)
    {
        cout << "Enter Show ID to select show: ";
        cin >> showChoice;

        if(showChoice < 1 || showChoice > 4)
        {
            cout << "Invalid Show ID!" << endl;
            cout << "Please enter a valid Show ID." << endl;
        }
    }

    cout << endl;
    cout << "===== SELECTED SHOW =====" << endl;
    shows[showChoice - 1].displayShow();


    // =========================
    // SEAT SECTION
    // =========================

    Seat seat;

    seat.totalSeats = 25;

    // All seats available

    for(int i = 0; i < 25; i++)
    {
        seat.isBooked[i] = false;
    }


    // =========================
    // SEAT NUMBERING
    // =========================

    seat.seatNo[0] = "A1";
    seat.seatNo[1] = "A2";
    seat.seatNo[2] = "A3";
    seat.seatNo[3] = "A4";
    seat.seatNo[4] = "A5";

    seat.seatNo[5] = "B1";
    seat.seatNo[6] = "B2";
    seat.seatNo[7] = "B3";
    seat.seatNo[8] = "B4";
    seat.seatNo[9] = "B5";

    seat.seatNo[10] = "C1";
    seat.seatNo[11] = "C2";
    seat.seatNo[12] = "C3";
    seat.seatNo[13] = "C4";
    seat.seatNo[14] = "C5";

    seat.seatNo[15] = "D1";
    seat.seatNo[16] = "D2";
    seat.seatNo[17] = "D3";
    seat.seatNo[18] = "D4";
    seat.seatNo[19] = "D5";

    seat.seatNo[20] = "E1";
    seat.seatNo[21] = "E2";
    seat.seatNo[22] = "E3";
    seat.seatNo[23] = "E4";
    seat.seatNo[24] = "E5";


    // =========================
    // ALREADY BOOKED SEATS
    // =========================

    seat.isBooked[2] = true;     // A3
    seat.isBooked[7] = true;     // B3
    seat.isBooked[12] = true;    // C3
    seat.isBooked[17] = true;    // D3
    seat.isBooked[22] = true;    // E3


    // =========================
    // SEAT TYPE AND PRICE
    // =========================

    // Regular = Rs.199

    for(int i = 0; i < 10; i++)
    {
        seat.seatType[i] = "Regular";
        seat.seatPrice[i] = 199;
    }


    // Premium = Rs.249

    for(int i = 10; i < 15; i++)
    {
        seat.seatType[i] = "Premium";
        seat.seatPrice[i] = 249;
    }


    // Balcony = Rs.399

    for(int i = 15; i < 25; i++)
    {
        seat.seatType[i] = "Balcony";
        seat.seatPrice[i] = 399;
    }


    // =========================
    // DISPLAY SEAT LAYOUT
    // =========================

    seat.displaySeats();


// =========================
// MULTIPLE SEAT SELECTION
// =========================

int numberOfSeats;
int totalAmount = 0;

string selectedSeats[25];
int selectedPrices[25];
string selectedTypes[25];

int selectedCount = 0;

cout << endl;
cout << "===== MULTIPLE SEAT SELECTION =====" << endl;

cout << "Enter number of seats: ";
cin >> numberOfSeats;

for(int j = 1; j <= numberOfSeats; j++)
{
    string selectedSeat;
    int selectedIndex = -1;

    cout << "Enter Seat " << j << ": ";
    cin >> selectedSeat;

    // Search Seat
    for(int i = 0; i < seat.totalSeats; i++)
    {
        if(seat.seatNo[i] == selectedSeat)
        {
            selectedIndex = i;
            break;
        }
    }

    // Check Seat
    if(selectedIndex == -1)
    {
        cout << "Invalid Seat Number!" << endl;
        j--;
    }
    else if(seat.isBooked[selectedIndex] == true)
    {
        cout << "Seat " << selectedSeat << " is already booked!" << endl;
        j--;
    }
    else
    {
        seat.isBooked[selectedIndex] = true;

        selectedSeats[selectedCount] = seat.seatNo[selectedIndex];
        selectedPrices[selectedCount] = seat.seatPrice[selectedIndex];
        selectedTypes[selectedCount] = seat.seatType[selectedIndex];

        totalAmount = totalAmount + seat.seatPrice[selectedIndex];

        selectedCount++;

        cout << "Seat " << selectedSeat << " selected successfully!" << endl;
        cout << "Price: Rs. " << seat.seatPrice[selectedIndex] << endl;
    }
}

    cout << endl;
    cout << "===== BOOKING SUMMARY =====" << endl;

    cout << "Selected Seats:" << endl;

    for(int i = 0; i < selectedCount; i++)
    {
        cout << selectedSeats[i]
            << "\t"
            << selectedTypes[i]
            << "\tRs. "
            << selectedPrices[i] << endl;
    }

    cout << "-----------------------------" << endl;
    cout << "Number of Seats : " << selectedCount << endl;
    cout << "Total Amount    : Rs. " << totalAmount << endl;

    // =========================
    // CUSTOMER SECTION
    // =========================

    Customer customer;

    cout << endl;
    cout << "===== CUSTOMER DETAILS =====" << endl;

    cout << "Enter Customer ID: ";
    cin >> customer.customerId;

    cout << "Enter Customer Name: ";
    cin >> customer.customerName;

    cout << "Enter Mobile Number: ";
    cin >> customer.mobileNo;

    cout << endl;

    cout << "===== CUSTOMER DETAILS =====" << endl;
    customer.displayCustomer();

    // =========================
    // BOOKING RECEIPT
    // =========================

    cout << endl;
    cout << "========================================" << endl;
    cout << "        ONLINE MOVIE TICKET" << endl;
    cout << "========================================" << endl;

    cout << "Customer ID   : " << customer.customerId << endl;
    cout << "Customer Name : " << customer.customerName << endl;
    cout << "Mobile Number : " << customer.mobileNo << endl;

    cout << "----------------------------------------" << endl;

    cout << "Movie         : "
        << movies[choice - 1].movieName << endl;

    cout << "Theatre       : "
        << theatres[theatreChoice - 1].theatreName << endl;

    cout << "Show Date     : "
        << shows[showChoice - 1].showDate << endl;

    cout << "Show Time     : "
        << shows[showChoice - 1].showTime << endl;

    cout << "----------------------------------------" << endl;

    cout << "SELECTED SEATS" << endl;

    for(int i = 0; i < selectedCount; i++)
    {
        cout << selectedSeats[i]
            << "\t"
            << selectedTypes[i]
            << "\tRs. "
            << selectedPrices[i] << endl;
    }

    cout << "----------------------------------------" << endl;

    cout << "Total Seats   : " << selectedCount << endl;
    cout << "Total Amount  : Rs. " << totalAmount << endl;

    cout << "========================================" << endl;
    cout << "       BOOKING SUCCESSFUL!" << endl;
    cout << "========================================" << endl;

    // =========================
    // PAYMENT SECTION
    // =========================

    int paymentChoice;

    cout << endl;
    cout << "===== PAYMENT SECTION =====" << endl;
    cout << "1. UPI" << endl;
    cout << "2. Debit Card" << endl;
    cout << "3. Cash" << endl;

    cout << "Enter Payment Method: ";
    cin >> paymentChoice;

    while(paymentChoice < 1 || paymentChoice > 3)
    {
        cout << "Invalid Payment Method!" << endl;
        cout << "Please enter a valid choice: ";
        cin >> paymentChoice;
    }

    cout << endl;

    if(paymentChoice == 1)
    {
        cout << "Payment Method : UPI" << endl;
    }
    else if(paymentChoice == 2)
    {
        cout << "Payment Method : Debit Card" << endl;
    }
    else
    {
        cout << "Payment Method : Cash" << endl;
    }

    cout << "Amount to Pay   : Rs. " << totalAmount << endl;
    cout << "Payment Status  : Successful" << endl;

    cout << "----------------------------------------" << endl;

    // =========================
    // FINAL TICKET
    // =========================

    int bookingId = 1001;

    cout << endl;
    cout << "========================================" << endl;
    cout << "          FINAL MOVIE TICKET" << endl;
    cout << "========================================" << endl;

    cout << "Booking ID    : " << bookingId << endl;

    cout << "Customer Name : "
        << customer.customerName << endl;

    cout << "Movie         : "
        << movies[choice - 1].movieName << endl;

    cout << "Theatre       : "
        << theatres[theatreChoice - 1].theatreName << endl;

    cout << "Show Date     : "
        << shows[showChoice - 1].showDate << endl;

    cout << "Show Time     : "
        << shows[showChoice - 1].showTime << endl;

    cout << "----------------------------------------" << endl;

    cout << "Seats:" << endl;

    for(int i = 0; i < selectedCount; i++)
    {
        cout << selectedSeats[i]
            << "\t"
            << selectedTypes[i]
            << "\tRs. "
            << selectedPrices[i] << endl;
    }

    cout << "----------------------------------------" << endl;

    cout << "Total Seats  : " << selectedCount << endl;
    cout << "Total Amount : Rs. " << totalAmount << endl;
    cout << "Payment      : Successful" << endl;

    cout << "========================================" << endl;
    cout << "       TICKET BOOKED SUCCESSFULLY" << endl;
    cout << "========================================" << endl;
    cout << "        THANK YOU FOR BOOKING!" << endl;
    cout << "========================================" << endl;

    // =========================
    // END OF BOOKING
    // =========================

    cout << endl;
    cout << "========================================" << endl;
    cout << "       THANK YOU FOR USING OUR SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "       HAVE A NICE DAY!" << endl;
    cout << "========================================" << endl;


    return 0;
}