const apiKey = "057959411634502face48cc1f7ff3672";

const searchBtn = document.getElementById("searchBtn");
const weatherResult = document.getElementById("weatherResult");


async function getWeather(city) {

    const url =
        `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`;

    try {

        const response = await fetch(url);

        const data = await response.json();

        console.log(data);

        if (data.cod !== 200) {
            
            alert("Please Correct City Name");
            return;

        }

        if (document.getElementById(data.name)) {
            alert("City already added");
            return;
        }

        weatherResult.innerHTML += `

                   
            <div class="card shadow weather-card" id="${data.name}">
            <div class="card-body">

                <h2 class="card-title">
                ${data.name}
                </h2>

                <h1 class="card-title">
                    ${data.main.temp}°C
                </h1>

                <p class="card-text">
                    ${data.weather[0].description}
                </p>    

            </div>

            <ul class="list-group list-group-flush">

             <li class="list-group-item">
               🌡Feels like: ${data.main.feels_like}°C
            </li>

             <li class="list-group-item">
                🔻 Min: ${data.main.temp_min}°C 
            </li>

            <li class="list-group-item">
               🔺 Max Temp: ${data.main.temp_max}°C
            </li>
            
            <li class="list-group-item">
                    Humidity: ${data.main.humidity}%
            </li>

            <li class="list-group-item">
                    Wind: ${data.wind.speed} km/h
            </li>

            <li class="list-group-item">
                    Pressure: ${data.main.pressure}
            </li>

            </ul>
        </div>
                    
        `;

    } catch (error) {

        console.log(error);

    }
}

// Default weather

getWeather("Surat");

// Search weather
searchBtn.addEventListener("click", () => {

    const city = document.getElementById("city").value;

    document.getElementById("city").value = "";  // use for clear search bar


    getWeather(city);


});

