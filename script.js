
// =====================================================
// ONLINE MOVIE TICKET BOOKING SYSTEM
// JAVASCRIPT
// =====================================================


// =====================================================
// GLOBAL VARIABLES
// =====================================================

let selectedMovie = "";
let selectedTheatre = "";
let selectedShow = "";

let selectedSeats = [];

let totalAmount = 0;


// =====================================================
// IMAGE ERROR FALLBACK
// =====================================================

function imageError(image, movieName) {

    image.style.display = "none";

    let placeholder = document.createElement("div");

    placeholder.className = "image-placeholder";

    placeholder.innerHTML =
        "🎬<span>" + movieName + "</span>";

    image.parentElement.insertBefore(
        placeholder,
        image
    );
}


// =====================================================
// CHANGE BOOKING STEP
// =====================================================

function changeStep(stepNumber) {

    let steps = [
        "stepMovie",
        "stepTheatre",
        "stepShow",
        "stepSeats",
        "stepBooking"
    ];


    steps.forEach(function(step) {

        document
            .getElementById(step)
            .classList
            .remove("active");

    });


    document
        .getElementById(steps[stepNumber - 1])
        .classList
        .add("active");
}


// =====================================================
// MOVIE SELECTION
// =====================================================

function selectMovie(movieName) {

    selectedMovie = movieName;

    document.getElementById(
        "selectedMovie"
    ).innerText = movieName;


    document.getElementById(
        "summaryMovie"
    ).innerText = movieName;


    changeStep(2);


    document
        .getElementById("theatres")
        .scrollIntoView({
            behavior: "smooth"
        });
}


// =====================================================
// THEATRE SELECTION
// =====================================================

function selectTheatre(theatreName) {

    selectedTheatre = theatreName;

    document.getElementById(
        "selectedTheatre"
    ).innerText = theatreName;


    document.getElementById(
        "summaryTheatre"
    ).innerText = theatreName;


    changeStep(3);


    document
        .getElementById("shows")
        .scrollIntoView({
            behavior: "smooth"
        });
}


// =====================================================
// SHOW SELECTION
// =====================================================

function selectShow(showTime) {

    selectedShow = showTime;

    document.getElementById(
        "selectedShow"
    ).innerText = showTime;


    document.getElementById(
        "summaryShow"
    ).innerText = showTime;


    changeStep(4);


    document
        .getElementById("booking")
        .scrollIntoView({
            behavior: "smooth"
        });
}


// =====================================================
// SEAT SELECTION
// =====================================================

document.addEventListener(
    "DOMContentLoaded",
    function() {

        let seats =
            document.querySelectorAll(".seat");


        seats.forEach(function(seat) {

            seat.addEventListener(
                "click",
                function() {


                    // CHECK BOOKED SEAT

                    if (
                        seat.classList.contains(
                            "booked"
                        )
                    ) {

                        alert(
                            "This seat is already booked!"
                        );

                        return;
                    }


                    // GET SEAT NAME

                    let seatName =
                        seat.innerText;


                    // REMOVE SEAT

                    if (
                        selectedSeats.includes(
                            seatName
                        )
                    ) {

                        selectedSeats =
                            selectedSeats.filter(
                                function(item) {

                                    return (
                                        item !==
                                        seatName
                                    );

                                }
                            );


                        seat.classList.remove(
                            "selected"
                        );

                    }


                    // ADD SEAT

                    else {

                        selectedSeats.push(
                            seatName
                        );

                        seat.classList.add(
                            "selected"
                        );

                    }


                    calculateTotal();

                }
            );

        });

    }
);


// =====================================================
// CALCULATE TOTAL
// =====================================================

function calculateTotal() {

    let regularCount = 0;
    let premiumCount = 0;
    let balconyCount = 0;


    let regularTotal = 0;
    let premiumTotal = 0;
    let balconyTotal = 0;


    selectedSeats.forEach(
        function(seat) {

            let row =
                seat.charAt(0);


            // REGULAR

            if (
                row === "A" ||
                row === "B"
            ) {

                regularCount++;

                regularTotal =
                    regularTotal + 199;
            }


            // PREMIUM

            else if (
                row === "C"
            ) {

                premiumCount++;

                premiumTotal =
                    premiumTotal + 249;
            }


            // BALCONY

            else if (
                row === "D" ||
                row === "E"
            ) {

                balconyCount++;

                balconyTotal =
                    balconyTotal + 399;
            }

        }
    );


    // TOTAL

    totalAmount =
        regularTotal +
        premiumTotal +
        balconyTotal;


    // SELECTED SEATS

    if (
        selectedSeats.length > 0
    ) {

        document.getElementById(
            "selectedSeats"
        ).innerText =
            selectedSeats.join(", ");

    }

    else {

        document.getElementById(
            "selectedSeats"
        ).innerText =
            "None";

    }


    // REGULAR PRICE

    document.getElementById(
        "regularPrice"
    ).innerText =
        regularCount +
        " × ₹199 = ₹" +
        regularTotal;


    // PREMIUM PRICE

    document.getElementById(
        "premiumPrice"
    ).innerText =
        premiumCount +
        " × ₹249 = ₹" +
        premiumTotal;


    // BALCONY PRICE

    document.getElementById(
        "balconyPrice"
    ).innerText =
        balconyCount +
        " × ₹399 = ₹" +
        balconyTotal;


    // TOTAL AMOUNT

    document.getElementById(
        "totalAmount"
    ).innerText =
        totalAmount;
}


// =====================================================
// CONFIRM BOOKING
// =====================================================

function confirmBooking() {


    // MOVIE VALIDATION

    if (selectedMovie === "") {

        alert(
            "Please select a movie!"
        );

        return;
    }


    // THEATRE VALIDATION

    if (selectedTheatre === "") {

        alert(
            "Please select a theatre!"
        );

        return;
    }


    // SHOW VALIDATION

    if (selectedShow === "") {

        alert(
            "Please select a show!"
        );

        return;
    }


    // SEAT VALIDATION

    if (
        selectedSeats.length === 0
    ) {

        alert(
            "Please select at least one seat!"
        );

        return;
    }


    // GET CUSTOMER NAME

    let name =
        document
            .getElementById("customerName")
            .value
            .trim();


    // GET MOBILE NUMBER

    let mobile =
        document
            .getElementById("customerMobile")
            .value
            .trim();


    // NAME VALIDATION

    if (name === "") {

        alert(
            "Please enter your name!"
        );

        return;
    }


    // MOBILE VALIDATION

    if (mobile === "") {

        alert(
            "Please enter your mobile number!"
        );

        return;
    }


    if (mobile.length !== 10) {

        alert(
            "Please enter a valid 10 digit mobile number!"
        );

        return;
    }


    // DISPLAY CUSTOMER DETAILS

    document.getElementById(
        "confirmName"
    ).innerText = name;


    document.getElementById(
        "confirmMobile"
    ).innerText = mobile;


    document.getElementById(
        "confirmMovie"
    ).innerText = selectedMovie;


    document.getElementById(
        "confirmTheatre"
    ).innerText = selectedTheatre;


    document.getElementById(
        "confirmShow"
    ).innerText = selectedShow;


    document.getElementById(
        "confirmSeats"
    ).innerText =
        selectedSeats.join(", ");


    document.getElementById(
        "confirmAmount"
    ).innerText =
        totalAmount;


    // CHANGE STEP

    changeStep(5);


    // SHOW CONFIRMATION

    document.getElementById(
        "confirmationBox"
    ).style.display = "block";


    // SCROLL TO CONFIRMATION

    document
        .getElementById("confirmationBox")
        .scrollIntoView({
            behavior: "smooth"
        });

}
